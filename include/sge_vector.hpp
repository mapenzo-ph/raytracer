#ifndef SGE_GEOMETRY_H
#define SGE_GEOMETRY_H

// std
#include <iostream>
#include <array>

namespace sge {
    
    class Vector {
     public:
        // constructors
        Vector() = default;
        Vector(double, double, double);
        
        // copy semantics
        Vector(const Vector&);
        Vector& operator=(const Vector&) noexcept;
        
        // move semantics 
        Vector(Vector &&);
        Vector& operator=(Vector&&) noexcept;

        // arithmetic operators
        Vector operator+(const Vector&) const noexcept;
        Vector& operator+=(const Vector&) noexcept;

        Vector operator-(const Vector&) const noexcept;
        Vector& operator-=(const Vector&) noexcept;

        Vector operator*(double factor) const noexcept;
        Vector& operator*=(double factor) noexcept;

        // logic operators
        bool operator==(const Vector&) const noexcept;

        // I/O operators
        friend std::ostream& operator<<(std::ostream& os, const Vector& vector) noexcept;

        // interface functions
        friend double dot(const Vector&, const Vector&) noexcept;
        friend double distance(const Vector&, const Vector&) noexcept;
        
     private:
        std::array<double,3> components;
    };

} // namespace sge


#endif