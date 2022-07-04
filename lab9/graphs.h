#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>

void print(int** adjlist, int nodes, int* sizes){
    
    for(int i = 0; i<nodes; i++){
        std::cout << i << ": " << std::flush;
        for(int j = 0; j<sizes[i]; j++){
                std::cout << adjlist[i][j] << " " << std::flush;
            
        }
        std::cout << std::endl;
    }
}

bool friends(int** cdgraph, int* sizes, int x, int y){
    bool a = false;
    bool b = false;
    for(int i = 0; i< sizes[x]; i++){
        if(cdgraph[x][i] == y){
            a = true;
        }
    }
    for(int j = 0; j< sizes[y]; j++){
        if(cdgraph[y][j] == x){
            b = true;
        }
    }
    if(a && b){
        return true;
    }
    return false;
}

bool mutual(int** graph, int* sizes, int x, int y){
    int test = sizes[x];
    int info [test];
    for(int i = 0; i< sizes[x]; i++){
            info[i] = graph[x][i];
        }
    
    for(int j = 0; j< sizes[y]; j++){
        for(int k = 0; k < test;k++){
            if(graph[y][j]==info[k]){
                return true;
            }
        }
    }
    return false;
}

#endif
