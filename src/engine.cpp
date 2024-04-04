#include <../include/engine.h>
#include <fmt/core.h>

Engine::Engine()
{
    
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;
    sf::IntRect mapBounds = {0, 0, (int)resolution.x, (int)resolution.y};

    window.create(sf::VideoMode(resolution.x, resolution.y), "Adventure Game" , sf::Style::Fullscreen);
    window.setFramerateLimit(144);

    mapLoader.levels[0].levelName = "Level1";
    mapLoader.levels[0].mapSprite.setOrigin(0,0);
    mapLoader.levels[0].mapSprite.setPosition(0,0);
    mapLoader.levels[0].mapTexture.loadFromFile("Background-1.png");
    mapLoader.levels[0].mapSprite.setTexture(mapLoader.levels[0].mapTexture);
    mapLoader.levels[0].mapSprite.setTextureRect(mapBounds);

    

    mapLoader.levels[0].StructureRectangels[0] = {0, 0, 550, 40};
    mapLoader.levels[0].StructureRectangelTextures[0].loadFromFile("Platform.png");
    mapLoader.levels[0].structures[0].setTextureRect(mapLoader.levels[0].StructureRectangels[0]);
    mapLoader.levels[0].structures[0].setTexture(mapLoader.levels[0].StructureRectangelTextures[0]);
    mapLoader.levels[0].structures[0].setPosition(0, resolution.y/2);

    // fmt::println("1");
    mapLoader.selector("Level1");
    scale = {(float)resolution.x / mapLoader.selectedLevel.mapSprite.getTexture() ->getSize().x, (float)resolution.y / mapLoader.selectedLevel.mapSprite.getTexture()->getSize().y};
    mapLoader.windowScaleUpdate(scale);
}

void Engine::start()
{
    sf::Clock clock;
    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                resolution.x = sf::VideoMode::getDesktopMode().width;
                resolution.y = sf::VideoMode::getDesktopMode().height;
                window.setSize(resolution);
            break;
            default:

                break;
            }

        }

        mapLoader.selectedLevel.mapSprite.setScale(scale);
        mapLoader.selectedLevel.mapSprite.setOrigin(0, 0);
        mapLoader.selectedLevel.mapSprite.setPosition(0, 0);

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
    player.update(dtAsSeconds, mapLoader.selectedLevel.structures, mapLoader.selectedLevel.mapSprite);
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
    
    player.scale(scale);
        
    sf::Vector2f test = {10.0f,10.0f}; //slet
    player.scale(test); //slet
    window.draw(player.getSprite());

    // Show everything we have just drawn
    window.display();
}