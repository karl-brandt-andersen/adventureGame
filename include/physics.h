# pragma once

#include <SFML/Graphics.hpp>

class Physics
{
private:
    float gravityForce = 100;
public:

    Physics();
    
    bool Interacts(sf::IntRect x, sf::IntRect &y);
    
    void gravity(sf::Sprite creature, float force);

    void setGravityForce(float x);
    
    float getGravityForce();
};