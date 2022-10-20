#include "sge_scene.hpp"

// std
#include <limits>

namespace sge {

    /////////////////////////
    // constructors

    Scene::Scene()
    : backgroundColor(Color(255, 255, 255)) {}

    Scene::Scene(const Color& backgroundColor)
    : backgroundColor(backgroundColor) {}

    Scene::Scene(Color&& backgroundColor)
    : backgroundColor(std::move(backgroundColor)) {}

    /////////////////////////
    // getters

    const Color& Scene::getBackgroundColor() const noexcept {
        return this->backgroundColor;
    }

    const std::vector<Sphere>& Scene::getObjects() const noexcept {
        return this->objects;
    }

    /////////////////////////
    // setters

    void Scene::setBackgroundColor(const Color& color) noexcept {
        this->backgroundColor = color;
    }

    void Scene::setBackgroundColor(Color&& color) noexcept {
        this->backgroundColor = std::move(color);
    }

    /////////////////////////
    // interface functions

    void Scene::addObject(const Sphere& primitive) noexcept {
        this->objects.push_back(primitive);
    }

    void Scene::addObject(Sphere&& primitive) noexcept {
        this->objects.push_back(std::move(primitive));
    }

    const int Scene::countObjects() const noexcept {
        return this->objects.size();
    }

    void Scene::addLight(const Light& light) noexcept {
        this->lights.push_back(light);
    }

    void Scene::addLight(Light&& light) noexcept {
        this->lights.push_back(light);
    }

    const int Scene::countLights() const noexcept {
        return this->lights.size();
    }

    /////////////////////////

} // namespace sge