#pragma once

#include <SFML/Graphics.hpp>
#include "../include/animation.h"
#include <fmt/core.h>

 
//using namespace sf;
 
class Player
{

private:
    float timer;
    sf::IntRect rectSprite;
    sf::Vector2f Position;
    sf::Sprite Sprite;
    sf::Texture Texture;
 

    bool LeftPressed;
    bool RightPressed;
    bool UpPressed;
    bool DownPressed;
 
    // Bob's speed in pixels per second
    float Speed;
 

public:
 
    Player();
 
    // Send a copy of the sprite to main
    sf::Sprite getSprite();

    void setScale(sf::Vector2f scale);
 
    void moveLeft();
 
    void moveRight();

    void moveUp();

    void moveDown();
 
    // Stop Bob moving in a specific direction
    void stopLeft();
 
    void stopRight();

    void stopUp();

    void stopDown();
 
    // We will call this function once every frame
    void update(float elapsedTime);
 
};