#include "Button.h"


Button::Button(const std::string text, float fontSize, sf::Vector2f size, sf::Vector2f position, sf::Color bgColor, sf::Color textColorr)
{
    buttonShape = new sf::RectangleShape();
    buttonColor = new sf::Color();
    buttonText = new sf::Text();
    this->textColor = new sf::Color();
    font = new sf::Font();


    (*buttonColor) = bgColor;
    (*textColor) = textColorr;

    buttonShape->setSize(size);
    buttonShape->setPosition(position);
    buttonShape->setOrigin((size.x) / 2, (size.y) / 2);
    buttonShape->setFillColor(bgColor);



    buttonText->setString(text);
    buttonText->setFillColor(textColorr);
    font->loadFromFile("Arimo Bold for Powerline.ttf");
    buttonText->setFont((*font));
    buttonText->setCharacterSize(fontSize);
    buttonText->setOrigin(buttonText->getGlobalBounds().width / 2, buttonText->getGlobalBounds().height);
    buttonText->setPosition(position);

}

void Button::draw(sf::RenderTarget& target, sf::RenderStates state) const                         //target to przesłane okno do wyświetlania (tak jak window.draw())
{
    target.draw((*buttonShape), state);
    target.draw((*buttonText), state);
}

sf::RectangleShape& Button::getButtonShape()
{
    return (*buttonShape);
}

sf::Text& Button::getButtonText()
{
    return (*buttonText);
}

sf::Color Button::getButtonColor()
{
    return (*buttonColor);
}

sf::Color Button::getTextColor()
{
    return (*textColor);
}


bool Button::isMouseOver(sf::RenderWindow &window)
{   
    // Pokazanie aktualnej pozycji myszki
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    // Pozycja przycisku - ze zwględu na to że origin jest przestawiony na środek (w konstruktorze) to należy wrócić do oryginalnej pozycji
    float buttonX = buttonShape->getPosition().x - (buttonShape->getLocalBounds().width / 2);
    float buttonY = buttonShape->getPosition().y - (buttonShape->getLocalBounds().height / 2);

    // Wymiary przycisku - do oryginalnej pozycji (lewy górny róg) dodajemy jego wysokość i szerokość
    float btnPosWidth = buttonX + buttonShape->getLocalBounds().width;
    float btnPosHeight = buttonY + buttonShape->getLocalBounds().height;


    if(mouseX < btnPosWidth && mouseX > buttonX && mouseY < btnPosHeight && mouseY > buttonY)
    {
        return true;
    }

    return false;

}


void Button::swapColors(sf::RenderWindow &window)
{
    if(isMouseOver(window))
    {
        buttonShape->setFillColor((*textColor));
        buttonText->setFillColor((*buttonColor));
    }
    else
    {
        buttonShape->setFillColor((*buttonColor));
        buttonText->setFillColor((*textColor));
    }
}

void Button::setButtonPosition(sf::Vector2f position)
{
    buttonShape->setPosition(position);
    buttonText->setPosition(position);
}

Button::~Button()
{
    delete buttonShape;
    delete buttonColor;
    delete buttonText;
    delete textColor;
    delete font;

    buttonShape = nullptr;
    buttonColor = nullptr;
    buttonText = nullptr;
    textColor = nullptr;
    font = nullptr;



}
