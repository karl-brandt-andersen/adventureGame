#include "../include/player.h"
#define numberOfItems 10

Player::Player()
{
    timer = 0;
    Speed = 400;
    rectSprite.top = 0;
    rectSprite.left = 5;
    rectSprite.width = 5;
    rectSprite.height = 5;

    Texture.loadFromFile("PlayerSpriteSheet2.png");
    Sprite.setTextureRect(rectSprite);
    Sprite.setTexture(Texture);

    Position.x = 500;
    Position.y = 500;
}
void Player::scale(sf::Vector2f scale)
{
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

void Player::update(float elapsedTime, sf::Sprite structures[numberOfItems], sf::Sprite map)
{
    timer += elapsedTime;

    // Initialize movement flags
    bool canMoveUp = true;
    bool canMoveDown = true;
    bool canMoveLeft = true;
    bool canMoveRight = true;

    // Iterate through structures and map once for all collision checks
    for (int i = 0; i < numberOfItems; i++)
    {
        if (physics.Interacts(Sprite, structures[i]) == "A bottom of B" || physics.InteractsMap(Sprite, map) == "player top of map")
        {
            canMoveUp = false;
        }
        if (physics.Interacts(Sprite, structures[i]) == "A top of B" || physics.InteractsMap(Sprite, map) == "player bottom of map")
        {
            canMoveDown = false;
        }
        if (physics.Interacts(Sprite, structures[i]) == "A left of B" || physics.InteractsMap(Sprite, map) == "player right of map")
        {
            canMoveRight = false;
        }
        if (physics.Interacts(Sprite, structures[i]) == "A right of B" || physics.InteractsMap(Sprite, map) == "player left of map")
        {
            canMoveLeft = false;
        }
    }

    // Handle vertical movement
    if (UpPressed && canMoveUp)
    {
        Sprite.move(0, -Speed * elapsedTime);
        animate.animate(3, rectSprite, Sprite, timer);
    }
    else if (DownPressed && canMoveDown)
    {
        Sprite.move(0, Speed * elapsedTime);
        animate.animate(4, rectSprite, Sprite, timer);
    }
    else if (canMoveDown == true)
    {
        // Apply gravity
        Sprite.move(0, physics.getGravityForce() * elapsedTime);
    }

    // Handle horizontal movement
    if (RightPressed && canMoveRight)
    {
        Sprite.move(Speed * elapsedTime, 0);
        animate.animate(1, rectSprite, Sprite, timer);
    }
    else if (LeftPressed && canMoveLeft)
    {
        Sprite.move(-Speed * elapsedTime, 0);
        animate.animate(2, rectSprite, Sprite, timer);
    }
}

/*
// the time elapsed, and the speed
void Player::update(float elapsedTime, sf::Sprite structures[numberOfItems], sf::Sprite map)
{

    timer += elapsedTime;

    if (UpPressed)
    {
        for (int i = 0; i < numberOfItems; i++)
        {
            if (physics.Interacts(Sprite, structures[i]) != "x under y" || physics.InteractsMap(Sprite, map) != "player top of map")
            {
                Sprite.move(0, -Speed * elapsedTime);
                animate.animate(3, rectSprite, Sprite, timer);
            }
        }
    }
    else if (DownPressed)
    {
        for (int i = 0; i < numberOfItems; i++)
        {
            if (physics.Interacts(Sprite, structures[i]) != "x over y" || physics.InteractsMap(Sprite, map) != "player bottom of map")
            {
                Sprite.move(0, Speed * elapsedTime);
                animate.animate(4, rectSprite, Sprite, timer);
            }
        }
    }
    else
    {
        for (int i = 0; i < numberOfItems; i++)
        {
            if (physics.Interacts(Sprite, structures[i]) != "x over y" || physics.InteractsMap(Sprite, map) != "player bottom of map")
            {
                Sprite.move(0, physics.getGravityForce() * elapsedTime);
            }
        }
    }

    if (RightPressed)
    {
        for (int i = 0; i < numberOfItems; i++)
        {
            if (physics.Interacts(Sprite, structures[i]) != "x left y" || physics.InteractsMap(Sprite, map) != "player right of map")
            {
                Sprite.move(Speed * elapsedTime, 0);
                animate.animate(1, rectSprite, Sprite, timer);
            }
        }
    }

    if (LeftPressed)
    {
        for (int i = 0; i < numberOfItems; i++)
        {
            if (physics.Interacts(Sprite, structures[i]) != "x right y" || physics.InteractsMap(Sprite, map) != "player left of map")
            {
                Sprite.move(-Speed * elapsedTime, 0);
                animate.animate(2, rectSprite, Sprite, timer);
            }
        }
    }
}
*/
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