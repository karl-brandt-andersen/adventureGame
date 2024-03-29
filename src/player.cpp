#include "../include/player.h"
 
Player::Player()
{
    timer = 0;
    Speed = 400;
    rectSprite.top= 0;
    rectSprite.left = 320;
    rectSprite.width = 320;
    rectSprite.height = 320;
    
    Texture.loadFromFile("PlayerSpriteSheet.png");
    Sprite.setTextureRect(rectSprite);
    Sprite.setTexture(Texture);  
 
    Position.x = 100;
    Position.y = 100;
 
}
void Player::setScale(sf::Vector2f scale){
    Sprite.setScale(scale.x, scale.y);
}

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

void Player::moveUp()
{
    UpPressed = true;
}

void Player::moveDown()
{
    DownPressed = true;
}
 
void Player::stopLeft()
{
    LeftPressed = false;
}
 
void Player::stopRight()
{
    RightPressed = false;
}

void Player::stopUp()
{
    UpPressed = false;
}

void Player::stopDown()
{
    DownPressed = false;
}
 

// the time elapsed, and the speed
void Player::update(float elapsedTime)
{
    Animation animate;
    timer += elapsedTime;
    
    if (UpPressed)
    {
        Sprite.move(0, -Speed * elapsedTime);
        animate.animate(3,rectSprite, Sprite, timer);
    }
    else{
        Sprite.move(0, physics.getGravityForce() * elapsedTime);
    }
 
    if (DownPressed)
    {
        Sprite.move(0, Speed * elapsedTime);
        animate.animate(4,rectSprite, Sprite, timer);
    }
    else
    {
        Sprite.move(0, physics.getGravityForce() * elapsedTime);
    }
    

    if (RightPressed)
    {
        Sprite.move(Speed * elapsedTime, 0);
        animate.animate(1,rectSprite, Sprite, timer);
    }
 
    if (LeftPressed)
    {
        Sprite.move(-Speed * elapsedTime, 0);
        animate.animate(2,rectSprite, Sprite, timer);
    }

    
    //physics.gravity(Sprite, physics.getGravityForce());
 
}






/*
    if (UpPressed)
    {
        Position.y -= Speed * elapsedTime;
        animate.animate(3,rectSprite, Sprite, timer);
    }
 
    if (DownPressed)
    {
        Position.y += Speed * elapsedTime;
        animate.animate(4,rectSprite, Sprite, timer);
    }

    if (RightPressed)
    {
        Position.x += Speed * elapsedTime;
        animate.animate(1,rectSprite, Sprite, timer);
    }
 
    if (LeftPressed)
    {
        Position.x -= Speed * elapsedTime;
        animate.animate(2,rectSprite, Sprite, timer);
    }

    Sprite.move(Position);
    physics.gravity(Sprite, Speed + physics.getGravityForce());
 */