#pragma once

#include <SFML/Graphics.hpp>
#include "../include/animation.h"
#include <fmt/core.h>
#include <../include/physics.h>
#define numberOfItems 10
 
class Player
{

private:
    float timer;
    sf::IntRect rectSprite;
    sf::Vector2f Position;
    sf::Sprite Sprite;
    sf::Texture Texture;

    Animation animate;

    bool LeftPressed;
    bool RightPressed;
    bool UpPressed;
    bool DownPressed;
 
    float Speed; //pixels pr second

    Physics physics;

public:
 
    Player();
 
    // Send a copy of the sprite to main
    sf::Sprite getSprite();

    void scale(sf::Vector2f scale);
 
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
    void update(float elapsedTime, sf::Sprite structures[numberOfItems], sf::Sprite map);
 
};