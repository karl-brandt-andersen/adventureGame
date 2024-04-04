#include<../include/mapLoader.h>
#define NumberOfItems 10
#define NumberOfLevels 2

MapLoader::MapLoader(){}

void MapLoader::loader(std::string pathToImage){
    selectedLevel.mapTexture.loadFromFile(pathToImage);
    selectedLevel.mapSprite.setTexture(selectedLevel.mapTexture);
}

void MapLoader::windowScaleUpdate(sf::Vector2f scaleXY){
    selectedLevel.mapSprite.scale(scaleXY);
    for (int i = 0; i < NumberOfItems; i++)
            {
                selectedLevel.structures[i].scale(scaleXY);
                
            }
}

void MapLoader::selector(std::string setLevel){ //funtion to set level from list of levels
    bool levelFound = false;
    for (int i = 0; i < NumberOfLevels; ++i) {
        if (setLevel == levels[i].levelName) {
            selectedLevel.levelName = levels[i].levelName;
            selectedLevel.mapTexture = levels[i].mapTexture;
            selectedLevel.mapSprite = levels[i].mapSprite;
            for (int j = 0; j < NumberOfItems; ++j) {
                selectedLevel.structures[j] = levels[i].structures[j];
                selectedLevel.StructureRectangels[j] = levels[i].StructureRectangels[j];
                selectedLevel.StructureRectangelTextures[j] = levels[i].StructureRectangelTextures[j];
            }
            levelFound = true;
            break;
        }
    }
    if (!levelFound) {
        fmt::println("No level named ", setLevel);
    }
}

