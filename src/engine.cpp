#include "../include/engine.h"

Engine::Engine(){
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    window.create(sf::VideoMode(resolution.x, resolution.y), "Adventure Game", sf::Style::Fullscreen);
    backgroundTexture.loadFromFile("background.jpg");
    backgroundSprite.setTexture(backgroundTexture);
}

void Engine::start(){
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
    
}

void Engine::input()
{
    // Handle the player quitting
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window.close();
    }
 
    // Handle the player moving
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player.moveLeft();
    }
    else
    {
        player.stopLeft();
    }
 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player.moveRight();
    }
    else
    {
        player.stopRight();
    }                       
 
}

void Engine::update(float dtAsSeconds)
{
    player.update(dtAsSeconds);
}

void Engine::draw()
{
    // Rub out the last frame
    window.clear(sf::Color::White);
 
    // Draw the background
    window.draw(backgroundSprite);
    window.draw(player.getSprite());
 
    // Show everything we have just drawn
    window.display();
}