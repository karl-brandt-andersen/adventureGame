#include<../include/mapLoader.h>


MapLoader::MapLoader(){}

void MapLoader::loader(std::string pathToImage){
    selectedLevel.mapTexture.loadFromFile(pathToImage);
    selectedLevel.mapSprite.setTexture(selectedLevel.mapTexture);
}

void MapLoader::windowScaleUpdate(sf::Vector2f scaleXY){
    selectedLevel.mapSprite.scale(scaleXY);
    for (int i = 0; i < 10; i++)
            {
                selectedLevel.structures[i].setScale(scaleXY);
                
            }
}

void MapLoader::selector(std::string setLevel){ //funtion to set level from list of levels
    bool levelFound = false;
    for (int i = 0; i < 2; ++i) {
        if (setLevel == levels[i].levelName) {
            selectedLevel.levelName = levels[i].levelName;
            selectedLevel.mapTexture = levels[i].mapTexture;
            selectedLevel.mapSprite = levels[i].mapSprite;
            for (int j = 0; j < 10; ++j) {
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

