#include "Dialog.h"



Dialog::Dialog()
{
    this->dialShape = new sf::RectangleShape();
    this->dialText = new sf::Text();
    this->f1 = new sf::Font();

    this->button_1 = new Button("RETURN", 25, {150, 40}, {setup::W / 2, setup::H / 2},  sf::Color(77, 144, 120), sf::Color(247, 129, 84));
    this->button_2 = new Button("EXIT", 25, {150, 40}, {setup::W / 2, setup::H / 2},  sf::Color(77, 144, 120), sf::Color(247, 129, 84));


    float dialWidth = 400;
    float dialHeight = 200;
    sf::Vector2f position = {setup::W/2, setup::H/2};

    // Wspolrzedne te beda dodawane do oryginalnego origina glownego okna (lewy gorny rog) 
    // W celu przestawienia origina na lewy gorny rog dialogboxa aby latwiej pozycjonowac przyciski
    float newX = (setup::W - dialWidth) / 2;
    float newY = (setup::H - dialHeight) / 2;

    this->f1->loadFromFile("Arimo Bold for Powerline.ttf");
    this->dialText->setString("YOU LOSE\n SCORE: 0");
    this->dialText->setFont(*f1);
    this->dialText->setCharacterSize(40);
    this->dialText->setFillColor(sf::Color(247, 129, 84));
    this->dialText->setOrigin(dialText->getGlobalBounds().width / 2, dialText->getGlobalBounds().height);
    this->dialText->setPosition({position.x, position.y - 15});
    
    
    this->dialShape->setSize({dialWidth, dialHeight});
    this->dialShape->setOrigin(dialWidth / 2, dialHeight / 2);
    this->dialShape->setFillColor(sf::Color(242, 193, 78));
    this->dialShape->setOutlineThickness(5);
    this->dialShape->setOutlineColor(sf::Color(77, 144, 120));
    this->dialShape->setPosition(position);

    // this->button_1->setButtonPosition({150, 300});
    this->button_1->setButtonPosition({newX + 100,newY + 150});
    this->button_2->setButtonPosition({350, 300});

    // this->button_1->setButtonPosition({this->dialShape.getLocalBounds().width, this->dialShape.getLocalBounds().height});

    

    std::cout<< this->dialShape->getGlobalBounds().width << " " << this->dialShape->getGlobalBounds().height << std::endl;
 

}


// Dialog::Dialog(std::string text, sf::Vector2f size, sf::Vector2f position, sf::Color bgColot, sf::Color textColor)
// {


//     // this->dialText.setString(text);
    
//     // this->dialShape.setSize({size});
//     // this->dialShape.setOrigin(size.x / 2, size.y / 2);
    
// }

void Dialog::draw(sf::RenderTarget& target, sf::RenderStates state) const                         //target to przesłane okno do wyświetlania (tak jak window.draw())
{
    target.draw((*dialShape), state);
    target.draw((*dialText), state);

    target.draw((*button_1));
    target.draw((*button_2));

}

bool Dialog::isMouseOver(sf::RenderWindow &window)
{   
    // Pokazanie aktualnej pozycji myszki
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    // Pozycja diala - ze zwględu na to że origin jest przestawiony na środek (w konstruktorze) to należy wrócić do oryginalnej pozycji
    float dialX = dialShape->getPosition().x  - (dialShape->getLocalBounds().width / 2);
    float dialY = dialShape->getPosition().y- (dialShape->getLocalBounds().height / 2);

    // Wymiary diala - do oryginalnej pozycji (lewy górny róg) dodajemy jego wysokość i szerokość
    float diaPosWidth = dialX + dialShape->getLocalBounds().width;
    float diaPosHeight = dialY + dialShape->getLocalBounds().height;

    // Jesli wspolrzedne myszy pokryja sie z wymiarami diala zwraca true jesli nie false
    if(mouseX < diaPosWidth && mouseX > dialX && mouseY < diaPosHeight && mouseY > dialY)
    {
        return true;
    }

    return false;

}

Button& Dialog::getButton_1()
{
    return *button_1;
}

Button* Dialog::getButton_2()
{
    return button_2;
}

Dialog::~Dialog()
{
    delete button_1;
    delete button_2;


    delete dialShape;
    delete dialText;
    delete f1;

    button_1 = nullptr;
    button_2 = nullptr;

    dialShape = nullptr;
    dialText = nullptr;
    f1 = nullptr;

}