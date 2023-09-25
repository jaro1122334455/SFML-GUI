#include "GUI_logic/Logo.h"
#include "GUI_logic/setup.h"



Logo::Logo(std::string text)
{

    f1.loadFromFile("../fonts/SnakeOutlineDemo-nRE5V.otf");
    t1.setCharacterSize(150);
    t1.setFont(f1);
    t1.setString(text);
    t1.setFillColor(sf::Color(95, 173, 86));
    t1.setOrigin(t1.getGlobalBounds().width / 2 , t1.getGlobalBounds().height / 2);
    t1.setPosition((setup::W / 2), (setup::H * 0.05));

}

void Logo::draw(sf::RenderTarget& target, sf::RenderStates state) const                         //target to przesłane okno do wyświetlania (tak jak window.draw())
{
    target.draw(this->t1, state);
}