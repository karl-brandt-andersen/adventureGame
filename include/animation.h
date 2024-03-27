#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
private:
        
public:
    void animate(int dir, sf::IntRect &spritesheet, sf::Sprite &spr, float &timer);
};
