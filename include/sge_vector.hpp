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

        Vector operator*(double) const noexcept;
        Vector& operator*=(double) noexcept;

        Vector operator/(double) const;
        Vector& operator/=(double);

        // logic operators
        bool operator==(const Vector&) const noexcept;

        // I/O operators
        friend std::ostream& operator<<(std::ostream&, const Vector&) noexcept;

        // interface functions
        friend const double dot(const Vector&, const Vector&) noexcept;
        friend const double distance(const Vector&, const Vector&) noexcept;
        const double norm() const noexcept;
        
     private:
        std::array<double,3> components;
    };

} // namespace sge


#endif