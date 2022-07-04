#ifndef MAP_UTILS
#define MAP_UTILS

// ============================== NEAREST NEIGHBOR ==============================

// This function takes in an index of a location on the map and finds its nearest neighbor.
// The index of the nearest neighboring location should be returned as an int.

// index:       the starting location index as an int
// map:         a 4x4 array of int with distances between every pair of locations

int nearestNeighbor(int index, int map[4][4]){
    int i = index;
    int min;
    int returnable;
    if(i != 0){
        min = map[i][0];
    }
    else{
        min = map[i][1];
    }
    for(int j = 0; j<4; j++){
        if(i != j){
            if(map[i][j]<min){
                min = map[i][j];
                returnable = j;

            }
        }
    }
    return returnable;
}

// =========================== NEAREST UNSEEN NEIGHBOR ===========================

// This function works much the same way as the one above, but it also accepts
// a list of locations we have already visited. Find the nearest neighbor that
// has not yet been visited, in other words, it does not appear in the seen list.

// index:       the starting location index as an int
// map:         a 4x4 array of int with distances between every pair of locations

bool finder(std::vector<int> finders, int element){
    for(int i = 0; i< finders.size(); i++){
        if(finders[i] == element){
            return true;
        }
    }
    return false;
}

int nearestUnseenNeighbor(int index, int map[4][4], std::vector<int> seen){
    int i = index;
    int returnable = 0;
    int min;
    if(i != 0){
        min = map[i][0];
        returnable = 0;
    }
    else{
        min = map[i][1];
        returnable = 1;
    }
    for(int j = 0; j<4; j++){
        if(i != j){
            if(map[i][j]<min && !(finder(seen, j))){
                min = map[i][j];
                returnable = j;
            }
        }
    }
    return returnable;
}

// ============================= GREEDY TRIP PLANNER =============================

// This function computes a sequence of locations in such a way that we start
// from a given location (startIndex) and we visit all the other locations and
// come back to the starting location. Each other location can only be visited
// once. 

// Your function should work as follows:
// From the starting location, visit nearest location that you have not been to yet
// Repeat above step until you have visited all locations
// Return to the original starting location, thereby completing the cycle

// You may use any of the functions that you have implemented above, if you want

// Function parameters:
// startIndex:  the index of the starting location as an int (should be a value between 0 and 3)
// map:         a 4x4 array of int with distances between every pair of locations
// names:       an array of string, giving names to each numbered location
// size:        the number of locations we have as an int, it will always be 4 in this lab

std::vector<std::string> planTrip(int startIndex, int map[4][4], std::string* names, int size){
    std::vector<std::string> user;
    std::vector<int> job;
    int current = startIndex;
    job.push_back(current);
    user.push_back(*(names + current));
    for(int i = 0; i<size; i++){
        current = nearestUnseenNeighbor(current, map, job);
        if(current != startIndex){
            job.push_back(current);
            user.push_back(*(names + current));
        }
    }
    user.push_back(*(names + startIndex));
    return user;
    // Your code here
}

#endif
