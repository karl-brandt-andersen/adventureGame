# pragma once

class hp
{
private:
    int health;
    int shield;
public:
    hp();

    void setHp(int a);

    void addHp(int a);

    int getHp();

    void setShield(int a);

    void addShield(int a);

    int getShield();

    void takeDamage(int hitPoint);

};