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


    Button* b3 = new Button("TEST", 50, {200, 70}, {setup::W / 2, setup::H / 2 + 200}, sf::Color(77, 144, 120), sf::Color(247, 129, 84));

    delete b3;

    b3 = nullptr;

    Logo logo("SNAKE");

    // Dialog dialog_2 = nullptr;

    Dialog* dialog = nullptr;

    // Dialog* dialog_test = new Dialog();

    // delete dialog;

    // dialog = nullptr;










    // ----------------------------------------------------------

    sf::RectangleShape* rect_1 = new sf::RectangleShape();

    rect_1->setSize({200, 200});
    rect_1->setPosition({setup::W / 2, setup::H / 2});
    rect_1->setFillColor(sf::Color::Blue);

    // delete rect_1;

    // rect_1 = nullptr;

    // ------------------------------------------------------------

    // delete dialog;

    // dialog = nullptr;

    


    // sf::Text logo = Logo("SNAKE");





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
                //     // if((*dialog).isMouseOver(window) == false)
                //     // {
                        b1.swapColors(window);
                        b2.swapColors(window);
                        // (*b3).swapColors(window);
                //     // }
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




                

                // if(b3 != nullptr && (*b3).isMouseOver(window))
                // {
                //     delete b3;
                //     b3 = nullptr;
                // }

            }


        }

        // std::cout << (*dialog).isMouseOver(window) << std::endl;

        window.clear(sf::Color(242, 193, 78));

        
        

        
        
        // if(b2.isMouseOver(window))
        // {
        
        // }

        // window.draw(shape);
        window.draw(b1);
        window.draw(b2);

        // if(b3 != nullptr)
        // {
        //     window.draw(*b3);
        // }

        // if(dialog_test != nullptr)
        // {
        //     window.draw(*dialog_test);
        // }
        // window.draw(b3);
        window.draw(logo);
        // window.draw((*dialog));


        if (dialog != nullptr)
        {
            // std::cout << "jest rozne od nullptr" << std::endl;
            window.draw((*dialog));
        }
        // else
        // {
        //     // window.draw((*rect_1));
        //     std::cout << "jest rozne od null" << std::endl;
        // }
        // else if(dialog == nullptr)
        // {
        //     window.draw((*rect_1));
        // }

        window.display();
    }

    return 0;
}
