#ifndef SGE_RAYTRACER_H
#define SGE_RAYTRACER_H

// sge
#include "sge_canvas.hpp"
#include "sge_camera.hpp"
#include "sge_scene.hpp"

// std
#include <memory>

namespace sge {
    
    class Raytracer {
     public:    
        // constructors
        Raytracer(Scene *scene, Camera *camera, Canvas *canvas);

        Raytracer()                 = delete;
        Raytracer(const Raytracer&) = delete;
        Raytracer(Raytracer&&)      = delete;

        // interface functions  
        void trace() const noexcept;
    
     private:
        // helper functions
        const Vector canvasToViewport(int, int) const noexcept;
        const double computeLighting(const Vector&, const Vector&) const noexcept;
        const Color traceRay(const Vector&, const Vector&, double, double) const noexcept;

        // class members
        Scene *scene;
        Camera *camera;
        Canvas *canvas;
    };

} // namespace sge

#endif 