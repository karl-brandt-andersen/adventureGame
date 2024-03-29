#pragma once

#include <SFML/Graphics.hpp>
#include "../include/player.h"
#include "../include/mapLoader.h"


//using namespace sf;

class Engine
{
private:
    sf::RenderWindow window;
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;

    Player player;
    MapLoader mapLoader;
    Physics physics;

    void input();
    void update(float dtAsSeconds);
    void draw();
public:
    sf::Vector2f scale;
    Engine();

    void start();
};
