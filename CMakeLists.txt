cmake_minimum_required(VERSION 3.0.0)

project(GUI VERSION 1.0.0)


# add_subdirectory(Snake_logic)

# add_executable(GUI 
# main.cpp 
# Button.cpp 
# Dialog.cpp 
# Logo.cpp
# )




set(SOURCES 
main.cpp
main.cpp 
Button.cpp 
Dialog.cpp 
Logo.cpp)


add_executable(GUI 
${SOURCES})



# target_link_libraries(Snake PUBLIC snake_logic)

    
    

    







target_include_directories(GUI PRIVATE /home/jarek/SFML-2.6.0/include)

target_link_libraries(GUI PRIVATE
    /home/jarek/SFML-2.6.0/lib/libsfml-graphics.so
    /home/jarek/SFML-2.6.0/lib/libsfml-window.so
    /home/jarek/SFML-2.6.0/lib/libsfml-system.so
)


