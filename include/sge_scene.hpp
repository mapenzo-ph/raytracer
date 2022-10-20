#ifndef SGE_SCENE_H
#define SGE_SCENE_H

// sge
#include "sge_color.hpp"
#include "sge_sphere.hpp"

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
        Color& getBackgroundColor() noexcept;
        std::vector<Sphere> const &getObjects() const noexcept;
        
        // setters
        void setBackgroundColor(const Color&) noexcept;
        void setBackgroundColor(Color&&) noexcept;

        // interface functions
        void addObject(const Sphere&) noexcept;
        void addObject(Sphere&&) noexcept;
        int const countObjects() const noexcept;
        Color const & traceRay(const Vector&, const Vector&, double, double) const noexcept;
      
     private:
        Color backgroundColor;
        std::vector<Sphere> objects;
    };

} // namespace sge


#endif