#pragma once

#include <SFML/Graphics.hpp>
#include "../include/player.h"

//using namespace sf;

class Engine
{
private:
    sf::RenderWindow window;;
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;

    Player player;

    void input();
    void update(float dtAsSeconds);
    void draw();
public:
    Engine();

    void start();
};
