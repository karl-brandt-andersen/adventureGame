#include<../include/hp.h>



    hp::hp(){
        health = 10;
        shield = 0;
    }

    void hp::setHp(int a){
        health = a;
    }


    void hp::addHp(int a){
        health += a;
    }

    int hp::getHp(){
        return(health);
    }

    void hp::setShield(int a){
        shield = a;
    }

    void hp::addShield(int a){
        shield += a;
    }

    int hp::getShield(){
        return(shield);
    }

    void hp::takeDamage(int hitPoint){
        health -= hitPoint + shield;
    }
