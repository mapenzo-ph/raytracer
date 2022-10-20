#ifndef SGE_COLOR_H
#define SGE_COLOR_H

// std
#include <iostream>
#include <array>


namespace sge {
    
    class Color {
     public:
        // constructors
        Color();
        Color(uint8_t r, uint8_t g, uint8_t b);

        // copy semantics
        Color(const Color &);
        Color& operator=(const Color&);

        // move semantics
        Color(Color&&);
        Color& operator=(Color&&);

        // arithmetic operators
        Color operator+(const Color& other) const;
        Color& operator+=(const Color& other);

        Color operator-(const Color& other) const;
        Color& operator-=(const Color& other);

        Color operator*(double factor) const;
        Color& operator*=(double factor);

        // I/O operators
        friend std::ostream& operator<<(std::ostream& os, const Color& color) noexcept;

        // getters
        uint8_t const getR() const noexcept;
        uint8_t const getG() const noexcept;
        uint8_t const getB() const noexcept;
        uint8_t const getA() const noexcept;

     private:
        std::array<uint8_t,3> rgb;
        uint8_t alpha;
    };

} // namespace sge


#endif