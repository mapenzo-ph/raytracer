#include "SGE.hpp"

// std
#include <iostream>

using namespace sge;

int main() {
    // init objects
    auto canvas = Canvas("raytracer", 800, 800);
    auto camera = Camera();
    auto scene  = Scene();
    auto raytrc = Raytracer(&scene, &camera, &canvas);

    // add primitives to the scene
    scene.addObject(Sphere(Vector(0, -1, 3), 1.0, Color(255, 0, 0)));
    scene.addObject(Sphere(Vector(2, 0, 4),  1.0, Color(0, 0, 255)));
    scene.addObject(Sphere(Vector(-2, 0, 4), 1.0, Color(0, 255, 0)));

    // run raytracer

    raytrc.trace();

    // show result
    canvas.paint();
    return 0;
}