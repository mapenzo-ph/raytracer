# create raytracer lib
add_library(libraytracer sge_color.cpp sge_vector.cpp sge_sphere.cpp
                         sge_canvas.cpp sge_camera.cpp sge_scene.cpp
                         sge_light.cpp sge_raytracer.cpp)
target_link_libraries(libraytracer PRIVATE ${SDL2_LIBRARIES})