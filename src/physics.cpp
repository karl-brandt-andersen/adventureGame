#include <../include/physics.h>

Physics::Physics(){

}

bool Physics::Interacts(sf::IntRect x, sf::IntRect &y){
    return(x.intersects(y));
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