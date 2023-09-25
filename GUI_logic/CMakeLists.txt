add_library(gui_logic
src/Button.cpp 
src/Dialog.cpp 
src/Logo.cpp)


target_include_directories(gui_logic PUBLIC /home/jarek/SFML-2.6.0/include)

target_link_libraries(gui_logic PUBLIC
    /home/jarek/SFML-2.6.0/lib/libsfml-graphics.so
    /home/jarek/SFML-2.6.0/lib/libsfml-window.so
    /home/jarek/SFML-2.6.0/lib/libsfml-system.so
)


target_include_directories(gui_logic PUBLIC include)