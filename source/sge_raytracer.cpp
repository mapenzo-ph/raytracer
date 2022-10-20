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

    const Vector Raytracer::canvasToViewport(int px, int py) const noexcept {
        auto x = px * camera->getViewportWidth() / canvas->getWidth();
        auto y = py * camera->getViewportHeight() / canvas->getHeight();
        return Vector(x, y, camera->getViewportDistance());
    }   

    const Color& Raytracer::traceRay(const Vector &origin, const Vector &direction, double tMin, 
                    double tMax = std::numeric_limits<double>::infinity()) const noexcept {
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
        return closest.getColor();
    }

    void Raytracer::trace() const noexcept {
        auto cWidth  = canvas->getWidth();
        auto cHeight = canvas->getHeight(); 
        auto origin  = camera->getPosition();
        for (int i = -cWidth/2; i <= cWidth/2; ++i) {
            for (int j = -cHeight/2; j <= cHeight/2; ++j) {
                auto direction = canvasToViewport(i, j);
                auto color = traceRay(origin, direction, 1.0);
                canvas->putPixel(i, j, color);
            }
        }
    }

    /////////////////////////

} // namespace sge