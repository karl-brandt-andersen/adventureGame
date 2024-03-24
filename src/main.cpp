/*
Jeg vil lave en tekst baseret adventure game

Jeg vil lave baner med forskellige rum, hvor der er items og monstre

Spilleren skal kunne bevæge sig med WASD og kunne slå med E og vælge items fra inventory med Q


*/
#include "kba.h"
#include <fmt/core.h>
//#include <SFML/Graphics.hpp>
#include "engine.h"
#include "player.h"


class hp
{
private:
    int hp;
    int shield;
public:
    void setHp(int a){
        hp = a;
    }


    void addHp(int a){
        hp += a;
    }

    int getHp(){
        return(hp);
    }

    void setShield(int a){
        shield = a;
    }

    void addShield(int a){
        shield += a;
    }

    int getShield(){
        return(shield);
    }

    void takeDamage(int hitPoint){
        hp -= shield - hitPoint;
    }

};

class inventory
{
private:

public:
    char inventory[5]; //[weapon, helmet, chestplate, shield, potion]


};

class Creature // Creatures skal have en bestemt skade de kan give, et symbol, der viser hvilken slags creature de er og måske en drop chance for loot de kan smide
{
private:
    int hitPoints;
    int speed;

public:
    int getHitPoints()
    {
        return (hitPoints);
    }

    int getSpeed()
    {
        return (speed);
    }

    void setHitPoints(int n)
    {
        hitPoints = n;
    }

    void setSpeed(int n)
    {
        speed = n;
    }
};

class player
{
private:
    std::string name;
    int hitPoints;
    int level;
    int speed;

public:
    int getHitPoints()
    {
        return hitPoints;
    }

    int getLevel()
    {
        return level;
    }

    int getSpeed()
    {
        return speed;
    }

    void setName(std::string n)
    {
        name = n;
    }

    void setHitPoints(int hp)
    {
        hitPoints = hp;
    }

    void setLevel(int lvl)
    {
        level = lvl;
    }

    void setSpeed(int spd)
    {
        speed = spd;
    }

};

int test1(double a, double b){
    double x = kba::math::add(a,b);
    std::string y = fmt::format("svaret er {}", x);
    fmt::print(y);
    return 0;
}

int test2(){
    fmt::print("fmt test");
    return 0;
}

int main()
{
    //test1(4,9);
    //test2();
    //test2();
    Engine engine;
 
    // Start the engine
    engine.start();
 
    // Quit in the usual way when the engine is stopped
    return 0;
}