#include "sge_vector.hpp"

// std
#include <stdexcept>
#include <iostream>
#include <cmath>

namespace sge {
    /////////////////////////
    // constructors

    // base ctor
    Vector::Vector(double x, double y, double z) 
    : components(std::array<double,3>{x,y,z}) {}

    /////////////////////////
    // copy semantics 

    // copy ctor
    Vector::Vector(const Vector& other)
    : components(other.components) {}

    // copy assignment
    Vector& Vector::operator=(const Vector& other) noexcept{
        if (this != &other) this->components = other.components;
        return *this;
    }

    /////////////////////////
    // move semantics

    // move ctor
    Vector::Vector(Vector&& other)
    : components(std::move(other.components)) {}

    // move assignment
    Vector& Vector::operator=(Vector&& other) noexcept{
        if (this != &other) this->components = std::move(other.components);
        return *this;
    }
    
    /////////////////////////
    // arithmetic operators

    // operator +
    Vector Vector::operator+(const Vector& other) const noexcept{
        Vector result;
        for (int i = 0; i < 3; ++i) {
            result.components.at(i) = this->components.at(i) + other.components.at(i);
        }
        return result;
    }

    // operator +=
    Vector& Vector::operator+=(const Vector& other) noexcept{
        for (int i = 0; i < 3; ++i) {
            this->components.at(i) += other.components.at(i);
        }
        return *this;
    }

    // operator -
    Vector Vector::operator-(const Vector& other) const noexcept{
        Vector result;
        for (int i = 0; i < 3; ++i) {
            result.components.at(i) = this->components.at(i) - other.components.at(i);
        }
        return result;
    }

    // operator -= 
    Vector& Vector::operator-=(const Vector& other) noexcept{
        for (int i = 0; i < 3; ++i) {
            this->components.at(i) -= other.components.at(i);
        }
        return *this;
    }

    // operator *
    Vector Vector::operator*(double factor) const noexcept{
        Vector result;
        for (int i = 0; i < 3; ++i) {
            result.components.at(i) = this->components.at(i) * factor;
        }
        return result;
    }

    // operator *=
    Vector& Vector::operator*=(double factor) noexcept {
        for (int i = 0; i < 3; ++i) {
            this->components.at(i) *= factor;
        }
        return *this;
    }

    // operator /
    Vector Vector::operator/(double factor) const {
        if (factor == 0) { throw std::invalid_argument("Vector: zero division error"); }
        Vector result;
        for (int i = 0; i < 3; ++i) {
            result.components.at(i) = this->components.at(i) / factor;
        }
        return result;
    }

    // operator /=
    Vector& Vector::operator/=(double factor) {
        if (factor == 0) { throw std::invalid_argument("Vector: zero division error"); }
        for (int i = 0; i < 3; ++i) {
            this->components.at(i) /= factor;
        }
        return *this;
    }

    /////////////////////////
    // logic operators

    // equals operators
    bool Vector::operator==(const Vector& other) const noexcept{
        return this->components == other.components;
    }

    /////////////////////////
    // I/O operators

    std::ostream& operator<<(std::ostream& os, const Vector& vector) noexcept {
        os << "Vector(" << vector.components.at(0) << ", "
                         << vector.components.at(1) << ", "
                         << vector.components.at(2) << ")";
        return os;
    }

    /////////////////////////
    // interface functions

    const double dot(const Vector& vec1, const Vector& vec2) noexcept {
        auto dot = 0.0;
        for (int i = 0; i < 3; ++i) {
            dot += vec1.components.at(i) * vec2.components.at(i);
        }
        return dot;
    }

    const double distance(const Vector& vec1, const Vector& vec2) noexcept {
        auto diff = vec1 - vec2;
        return std::sqrt(dot(diff, diff));
    }

    const double Vector::norm() const noexcept {
        return std::sqrt(dot(*this, *this));
    }

    /////////////////////////
    
} // namespace sge
