/*
Jeg vil lave en tekst baseret adventure game

Jeg vil lave baner med forskellige rum, hvor der er items og monstre

Spilleren skal kunne bevæge sig med WASD og kunne slå med E og vælge items fra inventory med Q


*/

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include "dependencies/kba.h"
#include <fmt/core.h>



class Creature // Creatures skal have en bestemt skade de kan give, et symbol, der viser hvilken slags creature de er og måske en drop chance for loot de kan smide
{
private:
    int life;
    int hitPoints;
    int dropChance;
    int speed;

public:
    Creature(int a, int b, int c) : life(a), hitPoints(b), dropChance(c){};

    int getLife()
    {
        return (life);
    }

    int getHitPoints()
    {
        return (hitPoints);
    }

    int getdropChance()
    {
        return (dropChance);
    }

    int getSpeed()
    {
        return (speed);
    }

    void setLife(int n)
    {
        life = n;
    }

    void setHitPoints(int n)
    {
        hitPoints = n;
    }

    void setdropChance(int n)
    {
        dropChance = n;
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
    int life;
    int hitPoints;
    int inventory[5]; // hitpoints skal vælges ud fra hvad spilleren har valgt i inventory
    int level;
    int speed;
    int shield;

public:
    player(std::string n, int l, int hp, int inv[5], int lvl, int spd, int sh)
        : name(n), life(l), hitPoints(hp), level(lvl), speed(spd), shield(sh) {}

    int getLife()
    {
        return life;
    }

    int getHitPoints()
    {
        return hitPoints;
    }

    int getInventory(int n)
    {
        return inventory[n];
    }

    int getLevel()
    {
        return level;
    }

    int getSpeed()
    {
        return speed;
    }

    int getShield()
    {
        return shield;
    }

    void setName(std::string n)
    {
        name = n;
    }

    void setLife(int l)
    {
        life = l;
    }

    void setHitPoints(int hp)
    {
        hitPoints = hp;
    }

    void setInventory(int n, int x)
    {
        inventory[n] = x; // Lav en type til våben, der indenholder de hitpoints de tillæger og det skjold de giver. f.eks. skjold(skjold = 5, hitpoint=0) eller sværd(skjold=0, hitpoint=10)
    }

    void setLevel(int lvl)
    {
        level = lvl;
    }

    void setSpeed(int spd)
    {
        speed = spd;
    }

    void setShield(int sh)
    {
        shield = sh;
    }
};

class mapGenerator // Brug JSON filer til at lave et tekstbaseret map, med 3 rum, hvor en spiller kan level op og komme til næste verden.
{
private:
    /* data */
public:
    mapGenerator(/* args */);
    ~mapGenerator();
};

class mapLoader
{
private:
    /* data */
public:
    mapLoader(/* args */);
    ~mapLoader();
};

class renderEngine
{
private:
    /* data */
public:
    renderEngine(/* args */);
    ~renderEngine();
};

int test()
{
    auto count = 150;
    for (size_t i = 0; i < count; i++)
    {
        system("cls");
        COORD cursorPosition = {0, 0};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

        fmt::print("Count {}", i);

        Sleep(17);
    }
    return 0;
}

int test2(int a, int b){
    std::cout << kba::math::add(a,b);
    return 0;
}

int test3(){
    fmt::print("fmt test");
    return 0;
}


int main()
{
    //test();
    test2(2,8);
    //test3();
}