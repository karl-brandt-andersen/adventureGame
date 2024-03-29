#include <../include/engine.h>
#include<fmt/core.h>


Engine::Engine(){    
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    window.create(sf::VideoMode(resolution.x, resolution.y), "Adventure Game"/*, sf::Style::Fullscreen*/);
    window.setFramerateLimit(60);

    mapLoader.levels[0].levelName = "Level1";
    mapLoader.levels[0].mapTexture.loadFromFile("Background-1.png");
    mapLoader.levels[0].mapSprite.setTexture(mapLoader.levels[0].mapTexture);
    mapLoader.levels[0].StructureRectangels[0] = {0, 40, 550, 40};
    mapLoader.levels[0].StructureRectangelTextures[0].loadFromFile("Platform.png");
    mapLoader.levels[0].structures[0].setTextureRect(mapLoader.levels[0].StructureRectangels[0]);
    mapLoader.levels[0].structures[0].setTexture(mapLoader.levels[0].StructureRectangelTextures[0]);
    mapLoader.levels[0].structures[0].setPosition(0,530);

    //fmt::println("1");
    mapLoader.selector("Level1");
    scale = {resolution.x/mapLoader.selectedLevel.mapSprite.getTexture()->getSize().x, resolution.y/mapLoader.selectedLevel.mapSprite.getTexture()->getSize().y};
    mapLoader.windowScaleUpdate(scale);
    
    
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
    window.draw(mapLoader.selectedLevel.mapSprite);
    window.draw(mapLoader.selectedLevel.structures[0]);
    window.draw(mapLoader.selectedLevel.structures[1]);
    window.draw(mapLoader.selectedLevel.structures[2]);
    window.draw(mapLoader.selectedLevel.structures[3]);
    window.draw(mapLoader.selectedLevel.structures[4]);
    window.draw(mapLoader.selectedLevel.structures[5]);
    window.draw(mapLoader.selectedLevel.structures[6]);
    window.draw(mapLoader.selectedLevel.structures[7]);
    window.draw(mapLoader.selectedLevel.structures[8]);
    window.draw(mapLoader.selectedLevel.structures[9]);
    
    player.setScale(scale);
    window.draw(player.getSprite());
    
    // Show everything we have just drawn
    window.display();
}