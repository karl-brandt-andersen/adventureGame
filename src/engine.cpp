#include "../include/engine.h"

Engine::Engine(){    
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;
    

    window.create(sf::VideoMode(resolution.x, resolution.y), "Adventure Game"/*, sf::Style::Fullscreen*/);
    window.setFramerateLimit(144);
    backgroundTexture.loadFromFile("Background-1.png");
    backgroundSprite.setTexture(backgroundTexture);
    scale = {resolution.x/backgroundSprite.getTexture()->getSize().x, resolution.y/backgroundSprite.getTexture()->getSize().y};
    backgroundSprite.scale(scale);
}

void Engine::start(){
    sf::Clock clock;
    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                break;
                default:
                    
                break;
            }
        }   
        sf::Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
}

void Engine::input()
{
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player.moveUp();
    }
    else
    {
        player.stopUp();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player.moveDown();
    }
    else
    {
        player.stopDown();
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
    player.setScale(scale);
    window.draw(player.getSprite());
 
    // Show everything we have just drawn
    window.display();
}