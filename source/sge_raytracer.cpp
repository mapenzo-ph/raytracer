#include "sge_raytracer.hpp"

// std
#include <limits>

namespace sge {

    /////////////////////////
    // constructors

    Raytracer::Raytracer(Scene *pScene, Camera *pCamera, Canvas *pCanvas) 
    : scene(pScene), camera(pCamera), canvas(pCanvas) {}

    /////////////////////////
    // interface functions

    void Raytracer::trace() const noexcept {
        auto cWidth  = canvas->getWidth();
        auto cHeight = canvas->getHeight(); 
        auto origin  = camera->getPosition();
        auto inf = std::numeric_limits<double>::infinity();
        for (int i = -cWidth/2; i <= cWidth/2; ++i) {
            for (int j = -cHeight/2; j <= cHeight/2; ++j) {
                auto direction = canvasToViewport(i, j);
                auto color = traceRay(origin, direction, 1.0, inf);
                canvas->putPixel(i, j, color);
            }
        }
    }

    /////////////////////////
    // helper functions

    const Vector Raytracer::canvasToViewport(int px, int py) const noexcept {
        auto x = px * camera->getViewportWidth() / canvas->getWidth();
        auto y = py * camera->getViewportHeight() / canvas->getHeight();
        return Vector(x, y, camera->getViewportDistance());
    }   

    const double Raytracer::computeLighting(const Vector& point, 
                                            const Vector& normal) const noexcept {
        double i = 0.0;
        for (auto light: scene->getLights()) {
            auto type = light.getType();
            if (type == LightType::ambient) {
                i += light.getIntensity();
            } else {
                auto dir = (type == LightType::point) ? light.getSrcOrDir() - point :
                                                        light.getSrcOrDir();
                auto prj = dot(normal, dir);
                i += (prj > 0) ? light.getIntensity() * prj / (normal.norm() * dir.norm()) : 0.0;
            }
        }
        return i;
    }

    const Color Raytracer::traceRay(const Vector &origin, const Vector &direction, 
                                     double tMin, double tMax) const noexcept {
        // find closest intersection between ray and sphere
        auto tClosest = std::numeric_limits<double>::infinity();
        Sphere closest;
        // find closest sphere color
        for (auto sphere: scene->getObjects()) {
            auto [t1, t2] = sphere.intersectRay(origin, direction);
            if ((t1 >= tMin && t1 <= tMax) && t1 < tClosest) {
                tClosest = t1;
                closest = sphere;
            }
            if ((t2 >= tMin && t2 <= tMax) && t2 < tClosest) {
                tClosest = t2;
                closest = sphere;
            }
        }
        // if no intersection return bg color
        if (tClosest == std::numeric_limits<double>::infinity()) {
            return scene->getBackgroundColor();
        }  
        // else compute lighting and return color
        auto rPoint = origin + (direction * tClosest);
        auto normal = rPoint - closest.getCenter();
        normal = normal / normal.norm();
        return closest.getColor() * computeLighting(rPoint, normal);
    }

    /////////////////////////

} // namespace sge