#include "sge_sphere.hpp"

// std
#include <limits>
#include <cmath>

namespace sge {
    
    /////////////////////////
    // constructors

    Sphere::Sphere(const Vector& center, double radius, const Color& color)
    : center(center), radius(radius), color(color) {}

    /////////////////////////
    // copy semantics

    // copy ctor
    Sphere::Sphere(const Sphere& other)
    : center(other.center), radius(other.radius), color(other.color) {}

    // copy assignment
    Sphere& Sphere::operator=(const Sphere& other) {
        this->center = other.center;
        this->radius = other.radius;
        this->color  = other.color;
        return *this;
    }

    /////////////////////////
    // move semantics

    // move ctor
    Sphere::Sphere(Sphere&& other)
    : center(std::move(other.center)), radius(other.radius), color(std::move(other.color)) {}

    // move assignment
    Sphere& Sphere::operator=(Sphere&& other) {
        this->center = std::move(other.center);
        this->radius = other.radius;
        this->color  = std::move(other.color);
        return *this;
    }

    /////////////////////////
    // getters

    const Vector& Sphere::getCenter() const noexcept {
        return this->center;
    }

    const Color& Sphere::getColor() const noexcept {
        return this->color;
    }

    /////////////////////////
    // interface functions

    std::tuple<double, double> Sphere::intersectRay(const Vector& origin, const Vector& direction) const noexcept{
        // compute coeffs of quadratic equation for intersections
        auto co = origin - this->center;
        auto a = dot(direction, direction);
        auto b = 2 * dot(co, direction);
        auto c = dot(co, co) - (this->radius * this->radius);
        
        // solve quadratic equation
        auto delta = b*b - 4*a*c;
        if (delta < 0) {
            auto inf = std::numeric_limits<double>::infinity();
            return std::make_tuple(inf, inf);
        }
        auto inv2a = 0.5 / a;
        auto t1 = (-b + std::sqrt(delta)) * inv2a;
        auto t2 = (-b - std::sqrt(delta)) * inv2a;
        return std::make_tuple(t1, t2);
    }

    /////////////////////////

} // namespace sge
