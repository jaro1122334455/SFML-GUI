#include <SFML/Graphics.hpp>
#include <iostream>
// #include <string.h>
#include "GUI_logic/Button.h"
#include "GUI_logic/Logo.h"
#include "GUI_logic/Dialog.h"
#include "GUI_logic/setup.h"




int main()
{
    sf::RenderWindow window(sf::VideoMode(setup::W, setup::H), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Button b1("START", 50, {200, 70}, {setup::W / 2, setup::H / 2}, sf::Color(77, 144, 120), sf::Color(247, 129, 84));
    Button b2("EXIT", 50, {200, 70}, {setup::W / 2, setup::H / 2 + 100}, sf::Color(77, 144, 120), sf::Color(247, 129, 84));

    Logo logo("SNAKE");


    Dialog* dialog = nullptr;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if(event.type == sf::Event::MouseMoved)
            {

                if(dialog == nullptr)
                {
                    b1.swapColors(window);
                    b2.swapColors(window);

                }

                if(dialog != nullptr)
                {

                    if((*dialog).isMouseOver(window) == true)
                    {
                        (*dialog).getButton_1().swapColors(window);
                        (*dialog).getButton_2()->swapColors(window);   
                    }

                }

  
            }

            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(dialog == nullptr)
                {

                    if(b1.isMouseOver(window))
                    {
                        dialog = new Dialog();
                    }


                    if(b2.isMouseOver(window))
                    {
                        window.close();
                    }

                }
                
                if(dialog != nullptr)
                {
                    if(((*dialog).isMouseOver(window) == true) && (*dialog).getButton_1().isMouseOver(window))
                    {
                        delete dialog;
                        dialog = nullptr;

                    }

                    else if(((*dialog).isMouseOver(window) == true) && (*dialog).getButton_2()->isMouseOver(window))
                    {
                        delete dialog;
                        dialog = nullptr;

                        window.close();
                    }

                }


            }


        }

        window.clear(sf::Color(242, 193, 78));

        
        window.draw(b1);
        window.draw(b2);

        window.draw(logo);


        if (dialog != nullptr)
        {
            window.draw((*dialog));
        }
        window.display();
    }

    return 0;
}
