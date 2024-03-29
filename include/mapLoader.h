# pragma once

#include <SFML/Graphics.hpp>
#include<fmt/core.h>

class MapLoader
{
private:
    float scale;
    std::string level;

    
public:

    struct LevelData
    {   
        std::string levelName = {};
        sf::Texture mapTexture  = {};
        sf::Sprite mapSprite = {};
        sf::Sprite structures[10] = {};
        sf::IntRect StructureRectangels[10] = {};
        sf::Texture StructureRectangelTextures[10] = {};

    };

    MapLoader::LevelData selectedLevel;
    MapLoader::LevelData levels[2];

    MapLoader();

    void loader(std::string PathToImage);

    void windowScaleUpdate(sf::Vector2f scaleXY);

    void selector(std::string setlevel);
    
};