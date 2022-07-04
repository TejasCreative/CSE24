#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <ostream>
#include <Dist.h>
#include <Date.h>

struct Player{
    std::string name;
    Dist height;
    Date birthday;

    Player(){
        this->name = "";
        this->height = Dist();
        this->birthday = Date();
    }

    Player(std::string name, int feet, int inches){
        this->name = name;
        this->height = Dist(feet, inches);
        this->birthday = Date();
    }

    Player(std::string name, int feet, int inches, int year, int month, int day){
        this->name = name;
        this->height = Dist(feet, inches);
        this->birthday = Date(year, month, day);
    }

};


std::ostream& operator<<(std::ostream& os, const Player& p){
    os << p.name << " - " << p.height << " - " << p.birthday;
    return os;
}

#endif
