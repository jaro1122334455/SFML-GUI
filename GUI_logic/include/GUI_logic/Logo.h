#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>


class Logo : public sf::Drawable
{
private:
    sf::Font f1;
    sf::Text t1;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

public:

    Logo(std::string text);

    // ~Logo() = default;


};