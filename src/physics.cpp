#include <../include/physics.h>
#include <fmt/core.h>
#include "windows.h"

Physics::Physics(){

}

std::string Physics::Interacts(sf::Sprite A, sf::Sprite &B){
    std::string interaction = "";

    sf::Vector2f APosition = A.getPosition();
    sf::Vector2f BPosition = B.getPosition();

    sf::Vector2f ASize(A.getTextureRect().width, B.getTextureRect().height);
    sf::Vector2f BSize(A.getTextureRect().width, B.getTextureRect().height);

float BRight = BPosition.x + BSize.x;
    float BBottom = BPosition.y + BSize.y;

    if (APosition.x <= BRight * B.getScale().x) {
        interaction = "A left of B";
    }
    else if (APosition.x + ASize.x * A.getScale().x >= BPosition.x) {
        interaction = "A right of B";
    }
    else if (APosition.y + ASize.y * A.getScale().y >= BPosition.y) {
        interaction = "A top of B";
    }
    else if (APosition.y <= BBottom * B.getScale().y) {
        interaction = "A bottom of B";
    }
    else {
        interaction = "no interaction";
    }
    fmt::println("{}", interaction);
    
    
    return "0";//Fjern
    
    //return interaction;
    
}

std::string Physics::InteractsMap(sf::Sprite player, sf::Sprite &map) {
    std::string interaction = "";

    // Get player and map positions
    sf::Vector2f playerPosition = player.getPosition();
    sf::Vector2f mapPosition = map.getPosition();

    // Get player and map dimensions
    sf::Vector2f playerSize(player.getTextureRect().width, player.getTextureRect().height);
    sf::Vector2f mapSize(map.getTextureRect().width, map.getTextureRect().height);

    // Calculate map boundaries
    float mapRight = mapPosition.x + mapSize.x;
    float mapBottom = mapPosition.y + mapSize.y;

    // Check player position relative to map boundaries
    if (playerPosition.x + playerSize.x * player.getScale().x >= mapRight) {
        interaction = "player right of map";
    }
    else if (playerPosition.x <= mapPosition.x) {
        interaction = "player left of map";
    }
    else if (playerPosition.y <= mapPosition.y) {
        interaction = "player top of map";
    }
    else if (playerPosition.y + playerSize.y * player.getScale().y >= mapBottom) {
        interaction = "player bottom of map";
    }
    else {
        interaction = "player in map";
    }
    //fmt::println("{}", interaction);
    return interaction;
}



void Physics::gravity(sf::Sprite creature, float force){
    creature.move(0, -force);
}

void Physics::setGravityForce(float x){
    gravityForce = x;
}

float Physics::getGravityForce(){
    return(gravityForce);
}