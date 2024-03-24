#pragma once

#include <SFML/Graphics.hpp>
#include "../include/player.h"
 
//using namespace sf;
 
class Player
{

private:
 
    sf::Vector2f Position;
    sf::Sprite Sprite;
    sf::Texture Texture;
 

    bool LeftPressed;
    bool RightPressed;
 
    // Bob's speed in pixels per second
    float Speed;
 

public:
 
    Player();
 
    // Send a copy of the sprite to main
    sf::Sprite getSprite();
 
    void moveLeft();
 
    void moveRight();
 
    // Stop Bob moving in a specific direction
    void stopLeft();
 
    void stopRight();
 
    // We will call this function once every frame
    void update(float elapsedTime);
 
};