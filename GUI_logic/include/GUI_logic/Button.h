#pragma once
// #ifndef BUTTON_H
// #define BUTTON_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>



class Button : public sf::Drawable
{

private:
    
    sf::RectangleShape* buttonShape;
    sf::Color* buttonColor;
    sf::Text* buttonText;
    sf::Color* textColor;
    sf::Font* font;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;





public:
    Button(const std::string text, float fontSize, sf::Vector2f size, sf::Vector2f position, sf::Color bgColor, sf::Color textColor);
    
    sf::RectangleShape& getButtonShape();
    sf:: Text& getButtonText();

    sf::Color getButtonColor();
    sf::Color getTextColor();

    void setButtonPosition(sf::Vector2f position);

    bool isMouseOver(const sf::RenderWindow &window);
    void swapColors(sf::RenderWindow &window);
    ~Button();
};

// #endif // BUTTON_H

