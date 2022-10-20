#ifndef SGE_WINDOW_H
#define SGE_WINDOW_H

// sge
#include "sge_color.hpp"
#include "sge_vector.hpp"

//ext
#include <SDL2/SDL.h>

//std 
#include <string>

namespace sge {
    
    class Canvas {
     public:
        // constructors
        Canvas(std::string title, int width, int height);

        // destructor
        ~Canvas();

        // getters
        const int getWidth() const noexcept;
        const int getHeight() const noexcept;

        // setters
        void setWidth(int width);
        void setHeight(int height);
        
        // interface functions
        void putPixel(int x, int y, const Color& color) const noexcept;
        void paint() const noexcept;
        
     private:
        const std::string title;
        int width, height;

        SDL_Window *window;
        SDL_Renderer *renderer;
    };
    
} // namespace rte


#endif