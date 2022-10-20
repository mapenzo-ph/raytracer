#ifndef SGE_LIGHTS_H
#define SGE_LIGHTS_H

#include "sge_vector.hpp"

namespace sge {

    enum class LightType { point, directional, ambient };

    class Light {
     public:
        // named constructors
        static Light point(const Vector&, double) noexcept;
        static Light point(Vector&&, double) noexcept;

        static Light directional(const Vector&, double) noexcept;
        static Light directional(Vector&&, double) noexcept;

        static Light ambient(double) noexcept;

        // copy semantics
        Light(const Light&);
        Light& operator=(const Light&) noexcept;

        // move semantics
        Light(Light&&);
        Light& operator=(Light&&) noexcept;

        // getters
        const LightType getType() const noexcept;
        const Vector& getSrcOrDir() const noexcept;
        const double getIntensity() const noexcept;

     private:
        // private constructor
        Light(LightType, const Vector&, double);
        Light(LightType, Vector&&, double);

        // private data
        LightType type;
        Vector srcOrDir;
        double intensity;

    };

}

#endif