#include "sge_camera.hpp"

// std
#include <stdexcept>

namespace sge {
    
    /////////////////////////
    // constructors

    // default ctor: camera in origin, approx 53° FOW
    Camera::Camera()
    : position(Vector(0, 0, 0)), viewportWidth(1), viewportHeight(1), viewportDistance(1) {}

    // custom ctor
    Camera::Camera(const Vector& position) 
    : position(position), viewportWidth(1), viewportHeight(1), viewportDistance(1) {}

    Camera::Camera(Vector&& position)
    : position(std::move(position)), viewportWidth(1), viewportHeight(1), viewportDistance(1) {}

    /////////////////////////
    // getters 

    Vector const & Camera::getPosition() const noexcept {
        return this->position;
    }

    double const Camera::getViewportWidth() const noexcept {
        return this->viewportWidth;
    }

    double const Camera::getViewportHeight() const noexcept {
        return this->viewportHeight;
    }
    
    double const Camera::getViewportDistance() const noexcept {
        return this->viewportDistance;
    }

    /////////////////////////
    // setters

    void Camera::setPosition(const Vector& position) noexcept {
        this->position = position;
    }

    void Camera::setViewportWidth(double viewportWidth) {
        if (viewportWidth > 0) this->viewportWidth = viewportWidth;
        else throw std::invalid_argument("Camera: viewportWidth must be set to a positive number");
    }

    void Camera::setViewportHeight(double viewportHeight) {
        if (viewportHeight > 0) this->viewportHeight = viewportHeight;
        else throw std::invalid_argument("Camera: viewportHeigth must be set to a positive number");
    }

    void Camera::setViewportDistance(double viewportDistance) {
        if (viewportDistance > 0) this->viewportDistance = viewportDistance;
        else throw std::invalid_argument("Camera: viewportDistance must be set to a positive number");
    }

    /////////////////////////
    
} // namespace sge
