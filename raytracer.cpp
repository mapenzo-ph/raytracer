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

    // add objects to the scene
    scene.addObject(Sphere(Vector( 0, -5001, 0), 5000, Color(255, 255, 0)));
    scene.addObject(Sphere(Vector( 0, -1, 3), 1, Color(255, 0, 0)));
    scene.addObject(Sphere(Vector( 2,  0, 4), 1, Color(0, 0, 255)));
    scene.addObject(Sphere(Vector(-2,  0, 4), 1, Color(0, 255, 0)));    

    // add lights to the scene
    scene.addLight(Light::directional(Vector(1, 4, 4), 0.2));
    scene.addLight(Light::point(Vector(2, 1, 0), 0.6));
    scene.addLight(Light::ambient(0.2));
    
    // run raytracer
    raytrc.trace();

    // show result
    canvas.paint();
    return 0;
}