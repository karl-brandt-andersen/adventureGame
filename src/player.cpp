#include "../include/player.h"
 
Player::Player()
{
    Speed = 400;
 
    Texture.loadFromFile("player.png");
    Sprite.setTexture(Texture);     
    Sprite.setScale(0.2, 0.2);
 
    Position.x = 500;
    Position.y = 100;
 
}
 
// Make the private spite available to the draw() function
sf::Sprite Player::getSprite()
{
    return Sprite;
}
 
void Player::moveLeft()
{
    LeftPressed = true;
}
 
void Player::moveRight()
{
    RightPressed = true;
}
 
void Player::stopLeft()
{
    LeftPressed = false;
}
 
void Player::stopRight()
{
    RightPressed = false;
}
 

// the time elapsed, and the speed
void Player::update(float elapsedTime)
{
    if (RightPressed)
    {
        Position.x += Speed * elapsedTime;
    }
 
    if (LeftPressed)
    {
        Position.x -= Speed * elapsedTime;
    }
 
    // Now move the sprite to its new position
    Sprite.setPosition(Position);   
 
}