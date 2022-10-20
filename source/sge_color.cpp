#include "sge_color.hpp"

namespace sge {
    
    /////////////////////////
    // constructors

    // default ctor
    Color::Color() : alpha(255) {}

    // named ctor
    Color::Color(uint8_t r, uint8_t g, uint8_t b) 
    : rgb(std::array<uint8_t,3>{r,g,b}), alpha(255) {}

    /////////////////////////
    // copy semantics

    // copy ctor
    Color::Color(const Color& other)
    : rgb(other.rgb), alpha(other.alpha) {}

    // copy assignment
    Color& Color::operator=(const Color& other) {
        if (this != &other) {
            this->rgb = other.rgb;
            this->alpha = other.alpha;
        }
        return *this;
    }

    /////////////////////////
    // move semantics

    // move ctor
    Color::Color(Color&& other) 
    : rgb(std::move(other.rgb)), alpha(other.alpha) {}

    // move assignment
    Color& Color::operator=(Color&& other) {
        if (this != &other) {
            this->rgb = std::move(other.rgb);
            this->alpha = other.alpha;
        }
        return *this;
    }

    /////////////////////////
    // arithmetic operators

    // operator +
    Color Color::operator+(const Color &other) const {
        Color result;
        int sum = 0;
        for (int i = 0; i < 3; ++i) {
            sum = this->rgb.at(i) + other.rgb.at(i);
            result.rgb.at(i) = (sum < 256) ? (uint8_t) sum : 255;
        }
        return result;
    }

    // operator +=
    Color& Color::operator+=(const Color& other) {
        int sum = 0;
        for (int i = 0; i < 3; ++i) {
            sum = this->rgb.at(i) + other.rgb.at(i);
            this->rgb.at(i) = (sum < 256) ? (uint8_t) sum : 255;
        }
        return *this;
    }

    // operator -
    Color Color::operator-(const Color &other) const {
        Color result;
        int diff = 0;
        for (int i=0; i<3; ++i) {
            diff = this->rgb.at(i) - other.rgb.at(i);
            result.rgb.at(i) = (diff >= 0) ? (uint8_t) diff : 0;
        }
        return result;
    }

    // operator -=
    Color& Color::operator-=(const Color& other) {
        int diff = 0;
        for (int i = 0; i < 3; ++i) {
            diff = this->rgb.at(i) - other.rgb.at(i);
            this->rgb.at(i) = (diff >= 0) ? (uint8_t) diff : 0;
        }
        return *this;
    }

    // operator *
    Color Color::operator*(double factor) const {
        Color result;
        int product = 0;
        for (int i = 0; i < 3; ++i) {
            product = int(factor * this->rgb.at(i));
            result.rgb.at(i) = (product < 256) ? (uint8_t) product : 255; 
        }
        return result;
    }
    
    // operator *=
    Color& Color::operator*=(double factor) {
        int product = 0;
        for (int i = 0; i < 3; ++i) {
            product = int(factor * this->rgb.at(i));
            this->rgb.at(i) = (product < 256) ? (uint8_t) product : 255;
        }
        return *this;
    }

    /////////////////////////
    // I/O operators

    // put operator
    std::ostream& operator<<(std::ostream& os, const Color& color) noexcept {
        os << "Color(" << (unsigned) color.rgb.at(0) << ", " 
                       << (unsigned) color.rgb.at(1) << ", "
                       << (unsigned) color.rgb.at(2) << ", "
                       << (unsigned) color.alpha << ")";
        return os;
    }

    /////////////////////////
    // getters

    uint8_t const Color::getR() const noexcept {
        return rgb.at(0);
    }

    uint8_t const Color::getG() const noexcept {
        return rgb.at(1);
    }

    uint8_t const Color::getB() const noexcept {
        return rgb.at(2);
    }

    uint8_t const Color::getA() const noexcept {
        return alpha;
    }

    /////////////////////////

} // namespace sge
