#include "sge_canvas.hpp"

// std
#include <stdexcept>

namespace sge {
    
    /////////////////////////
    // constructors

    Canvas::Canvas(std::string title, int width, int height) 
    : title(title), width(width), height(height) {
        // use SDL2 to show window on screen
        SDL_InitSubSystem(SDL_INIT_VIDEO);
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
            width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        // paint background with uniform color
        SDL_SetRenderDrawColor(renderer, 15, 15, 25, 255);
        SDL_RenderClear(renderer);
    }

    /////////////////////////
    // destructor 

    Canvas::~Canvas() {
        // destroy SDL objects
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }

    /////////////////////////
    // getters 

    int const Canvas::getWidth() const noexcept { return this->width; }
    int const Canvas::getHeight() const noexcept {return this->height; }

    /////////////////////////
    // setters 

    void Canvas::setWidth(int width) {
        if (width > 0) this->width = width;
        else throw std::invalid_argument("Canvas: width must be set to a positive number");
    }

    void Canvas::setHeight(int height) { 
        if (height > 0) this->height = height;
        else throw std::invalid_argument("Canvas: height must be set to a positive number");
    }

    /////////////////////////
    // interface funcations 

    void Canvas::putPixel(int cx, int cy, const Color& color) const noexcept {
        SDL_SetRenderDrawColor(renderer, color.getR(), color.getG(), color.getB(), color.getA());
        // NB: implicitly converting from canvas to screen coordinates
        SDL_RenderDrawPoint(renderer, width/2 + cx, height/2 - cy); 
    }

    void Canvas::paint() const noexcept{
        SDL_RenderPresent(renderer);
        // keep window open until closed manually
        SDL_Event event;
        while (true) {
            if (SDL_WaitEvent(&event) && event.type == SDL_QUIT)
                break;
        }
    }

    /////////////////////////

} // namespace sge