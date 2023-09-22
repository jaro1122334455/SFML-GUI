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



    // Button* button_1 = new Button("RETURN", 25, {150, 40}, {setup::W / 2, setup::H / 2},  sf::Color(77, 144, 120), sf::Color(247, 129, 84));
    // Button* button_2 = new Button("EXIT", 25, {150, 40}, {setup::W / 2, setup::H / 2},  sf::Color(77, 144, 120), sf::Color(247, 129, 84));
    // Button b2("WYJSCIE", {200, 70}, {setup::W / 2, setup::H / 2},  sf::Color(77, 144, 120), sf::Color(247, 129, 84));

    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;



public:
    Dialog();
    // Dialog(std:: string text, sf::Vector2f size, sf::Vector2f position, sf::Color bgColot, sf::Color textColor);
    ~Dialog();

    Button& getButton_1();
    Button* getButton_2();

    bool isMouseOver(sf::RenderWindow &window);

};