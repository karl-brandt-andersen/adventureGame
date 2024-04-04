# pragma once

#include <SFML/Graphics.hpp>

class Physics
{
private:
    float gravityForce = 300;
public:

    Physics();
    
    std::string Interacts(sf::Sprite x, sf::Sprite &y);

    std::string InteractsMap(sf::Sprite player, sf::Sprite &map);
    
    void gravity(sf::Sprite creature, float force);

    void setGravityForce(float x);
    
    float getGravityForce();
};