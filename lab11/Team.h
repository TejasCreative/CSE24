#ifndef TEAM_H
#define TEAM_H

#include <ostream>
#include <string>
#include <Player.h>

struct Team{
    Player* players;
    int count;
    int capacity;
    std::string name;

    Team(){
        count = 0;
        capacity = 1;
        players = new Player[capacity];
        name = "";
    }

    Team(std::string name){
        count = 0;
        capacity = 1;
        players = new Player[capacity];
        this->name = name;
    }

    Team(const Team& other){
        name = other.name;
        count = other.count;
        players = new Player[count];
        for (int i = 0; i < count; i++){
            players[i] = other.players[i];
        }
    }
    Team& operator=(const Team& other){
        name = other.name;
        count = other.count;
        delete[] players;
        players = new Player[count];
        for (int i = 0; i < count; i++){
            players[i] = other.players[i];
        }
    }

    Dist averageHeight() const {
        Dist total;
        for(int i = 0; i < count; i++){
            total = total + players[i].height;
        }
        
        return total / count;
    }

    int averageAge(int year, int month, int day){
        Date today = Date(year, month, day);
        return averageAge(today);
    }

    int averageAge(Date today){
        int total = 0;

        for (int i = 0; i < count; i++){
            total += today - players[i].birthday;
        }

        return total/count;
    }

    void add(Player p){
        players[count] = p;
        count++;

        if (count == capacity){
            // We have run out of space, so we double our storage

            int oldCapacity = capacity;
            capacity *= 2;

            Player* temp = new Player[capacity]; // This is twice as big as the original

            // Copy all contents of the players array into temp
            for(int i = 0; i < oldCapacity; i++){
                temp[i] = players[i];
            }

            // Move players pointer to the new storage, delete the old storage
            Player* oldStorage = players;
            players = temp;

            // Release the old storage space
            delete[] oldStorage;

        }
    }

    ~Team(){
        delete[] players;
    }

};

std::ostream& operator<<(std::ostream& os, const Team& t){
    os << t.name << ":" << std::endl << std::endl;
    for (int i = 0; i < t.count; i++){
        os << t.players[i] << std::endl;
    }
    os << std::endl;

    return os;
}



#endif
