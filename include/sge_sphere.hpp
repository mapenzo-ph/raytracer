#ifndef SGE_PRIMITIVES_H
#define SGE_PRIMITIVES_H

// sge
#include "sge_color.hpp"
#include "sge_vector.hpp"

// std
#include <tuple>

namespace sge {
    
    class Sphere {
     public:
        // constructors
        Sphere() = default;
        Sphere(const Vector& center, double radius, const Color& color);

        // copy semantics
        Sphere(const Sphere&);
        Sphere& operator=(const Sphere&);

        // move semantics
        Sphere(Sphere&&);
        Sphere& operator=(Sphere&&);

        // getters
        const Vector& getCenter() const noexcept;
        const Color& getColor() const noexcept;

        // interface functions
        std::tuple<double, double> intersectRay(const Vector&, const Vector&) const noexcept;

      private:
        Vector center;
        double radius;
        Color color;
    };

} // namespace sge


#endif