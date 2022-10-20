#ifndef SGE_SCENE_H
#define SGE_SCENE_H

// sge
#include "sge_color.hpp"
#include "sge_sphere.hpp"
#include "sge_light.hpp"

// std
#include <vector>

namespace sge {
    
    class Scene {  
     public:
        // constructors
        Scene();
        Scene(const Color&);
        Scene(Color&&);

        // getters
        const Color& getBackgroundColor() const noexcept;
        const std::vector<Sphere>& getObjects() const noexcept;
        
        // setters
        void setBackgroundColor(const Color&) noexcept;
        void setBackgroundColor(Color&&) noexcept;

        // interface functions
        void addObject(const Sphere&) noexcept;
        void addObject(Sphere&&) noexcept;
        const int countObjects() const noexcept;

        void addLight(const Light&) noexcept;
        void addLight(Light&&) noexcept;
        const int countLights() const noexcept;

     private:
        Color backgroundColor;
        std::vector<Sphere> objects;
        std::vector<Light> lights;
    };

} // namespace sge


#endif