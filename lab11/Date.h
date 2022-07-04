#ifndef DATE_H
#define DATE_H

#include <ostream>

struct Date{
    int year;
    int day;
    int month;
    Date(){
        year = 1;
        day = 1;
        month = 1;
    }
    Date(int year, int month, int day){
        this->year = year;
        this->month = month;
        this->day = day;
    }

    int operator-(Date a){
        int byear =  year-a.year;
        if(a.month > month){
            byear = byear-1;
            return byear;
        }
        if(a.day > day){
            byear = byear-1;
            return byear;
        }
        
        return byear;

    }


};


#endif
