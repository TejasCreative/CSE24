#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include<cstdlib>
using namespace std;
ifstream fin;
ofstream fout;


int main(){
    vector<string> listOfWords;
    vector<string> user;
    string input;
    string adder;
    bool checker = false;
    string selection;
    int correct = 0;
    string answer;
    int val;
    char guess;
    bool trigger = false;
    int wrong = 0;
    fin.open("words.txt");
    fin >> selection;
    listOfWords.push_back(selection);
    while(!fin.eof()){
        fin >> selection;
        listOfWords.push_back(selection);
    }
    fout.open("words.txt");
    for (int i = 0; i < listOfWords.size(); i++){
        fout << listOfWords.at(i) << endl;
    }

    cout << "Say Play to play the game, or Add to add words " << flush;
    cin >> input;
    if(input == "Play"){
        int random = (rand() % listOfWords.size());
        answer = listOfWords.at(random);
        val = answer.length();
        for(int i = 0; i< val; i++){
            user.push_back("-");
        }
        while(wrong < 6){
            for(int i = 0; i < user.size(); i++){
                cout << user.at(i) << flush;
            }
            cout << endl;
            cout << "Guess letter: " << flush;
            cin >> guess;
            for(int i = 0; i < val; i++){
                if(guess == answer[i]){
                    trigger = true;
                    user.at(i) = guess;
                    correct++;
                    cout << "Correct!" << endl;
                }
            }

            if(trigger == false){
                cout << "Wrong" << endl;
                wrong++;
                cout << "Incorrect Guesses: " << wrong << endl;
            }
            trigger = false;
            if(correct == val){
                cout << "You Won!" << endl;
                checker = true;
                break;
            }
        }
        if(checker == false){
            cout << "You lost!" << endl;
            cout << "The word was: " << answer << endl;
        }
    }
    else{
        cout << "What word do you want to add: " << flush;
        cin >> adder;
        fout << adder;
        cout << "Added!" << flush;
    }

    fin.close();
    fout.close();

    return 0;
}