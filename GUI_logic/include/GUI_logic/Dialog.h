#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>

#include "setup.h"
#include "Button.h"

class Dialog : public sf::Drawable
{

private:

    sf::RectangleShape* dialShape;
    sf::Color* dialColor;
    
    sf::Font* f1;
    sf::Color* textColor;
    sf::Text* dialText;

    Button* button_1;
    Button* button_2;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;



public:
    Dialog();
    // Dialog(std:: string text, sf::Vector2f size, sf::Vector2f position, sf::Color bgColot, sf::Color textColor);
    ~Dialog();

    Button& getButton_1();
    Button* getButton_2();

    bool isMouseOver(const sf::RenderWindow &window) const;

};