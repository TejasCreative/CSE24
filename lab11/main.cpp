#include <iostream>
#include <Team.h>

using namespace std;

int main(){

    Team dreamTeam("1992 Dream Team");

    dreamTeam.add(Player("Michael Jordan", 6, 6, 1963, 2, 17));
    dreamTeam.add(Player("Charles Barkley", 6, 6, 1963, 2, 20));
    dreamTeam.add(Player("Larry Bird", 6, 9, 1956, 12, 7));
    dreamTeam.add(Player("Magic Johnson", 6, 9, 1959, 8, 14));

    cout << dreamTeam << endl;
    cout << "Average Height: " << dreamTeam.averageHeight() << endl;
    Date today(2022, 4, 27);
    cout << "Average Age on " << today << ": " << dreamTeam.averageAge(today) << endl;

    return 0;
}

