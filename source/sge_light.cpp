#include "sge_light.hpp"

namespace sge {

    /////////////////////////
    // constructors

    // private class constructor
    Light::Light(LightType type, const Vector& srcOrDir, double intensity)
    : type(type), srcOrDir(srcOrDir), intensity(intensity) {} 

    Light::Light(LightType type, Vector&& srcOrDir, double intensity)
    : type(type), srcOrDir(std::move(srcOrDir)), intensity(intensity) {}

    // named ctors for point light
    Light Light::point(const Vector& source, double intensity) noexcept {
        return Light(LightType::point, source, intensity);
    } 

    Light Light::point(Vector&& source, double intensity) noexcept {
        return Light(LightType::point, std::forward<Vector&&>(source), intensity);
    }

    // named ctors for directional light
    Light Light::directional(const Vector& direction, double intensity) noexcept {
        return Light(LightType::directional, direction, intensity);
    }

    Light Light::directional(Vector&& direction, double intensity) noexcept {
        return Light(LightType::directional, direction, intensity);
    }

    // named ctor for ambient light
    Light Light::ambient(double intensity) noexcept {
        return Light(LightType::ambient, Vector(0, 0, 0), intensity);
    }

    /////////////////////////
    // copy semantics

    Light::Light(const Light& other)
    : type(other.type), srcOrDir(other.srcOrDir), intensity(other.intensity) {}

    Light& Light::operator=(const Light& other) noexcept {
        this->type = other.type;
        this->srcOrDir = other.srcOrDir;
        this->intensity = other.intensity;
        return *this;
    }

    /////////////////////////
    // move semantics

    Light::Light(Light&& other)
    : type(other.type), srcOrDir(std::move(other.srcOrDir)), intensity(other.intensity) {}

    Light& Light::operator=(Light&& other) noexcept {
        this->type = other.type;
        this->srcOrDir = std::move(other.srcOrDir);
        this->intensity = other.intensity;
        return *this;
    }

    /////////////////////////
    // getters

    const Vector& Light::getSrcOrDir() const noexcept {
        return this->srcOrDir;
    }

    const double Light::getIntensity() const noexcept {
        return this->intensity;
    }

    /////////////////////////
    // interface functions



    /////////////////////////

}