#ifndef SGE_CAMERA_H
#define SGE_CAMERA_H

// sge
#include "sge_vector.hpp"

namespace sge {
    
    class Camera {
     public:
        // constructors 
        Camera();
        Camera(const Vector&);
        Camera(Vector&&);

        // getters
        Vector const & getPosition() const noexcept;
        const double getViewportWidth() const noexcept;
        const double getViewportHeight() const noexcept;
        const double getViewportDistance() const noexcept;

        // setters
        void setPosition(const Vector&) noexcept;
        void setViewportWidth(double viewportWidth);
        void setViewportHeight(double viewportHeight);
        void setViewportDistance(double viewportDistance);

        // interface functions

     private:
        Vector position;
        double viewportWidth;
        double viewportHeight;
        double viewportDistance;
    
    };

} // namespace sge


#endif