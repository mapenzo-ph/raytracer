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

    Vector const Raytracer::canvasToViewport(int px, int py) const noexcept {
        auto x = px * camera->getViewportWidth() / canvas->getWidth();
        auto y = py * camera->getViewportHeight() / canvas->getHeight();
        return Vector(x, y, camera->getViewportDistance());
    }   

    Color const Raytracer::traceRay(const Vector &origin, const Vector &direction, double tMin, 
                    double tMax = std::numeric_limits<double>::infinity()) const noexcept {
        // find closest intersection between ray and sphere
        auto tClosest = std::numeric_limits<double>::infinity();
        Color cClosest = scene->getBackgroundColor();
        for (auto sphere: scene->getObjects()) {
            auto [t1, t2] = sphere.intersectRay(origin, direction);
            if ((t1 >= tMin && t1 <= tMax) && t1 < tClosest) {
                tClosest = t1;
                cClosest = sphere.getColor();
            }
            if ((t2 >= tMin && t2 <= tMax) && t2 < tClosest) {
                tClosest = t2;
                cClosest = sphere.getColor();
            }
        } 
        return cClosest;
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