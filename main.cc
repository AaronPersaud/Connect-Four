#include "connect.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "easy.h"

using namespace std;

int main() {
    srand(time(NULL));
    int players;
    Connect c;
    cout << "How many players are playing? Please enter 1 or 2" << endl;
    while(true) {
      cin >> players;
      if(cin.eof()) {
        break;
      }
      if(players > 2 || players < 1 || cin.fail()) {
        cin.ignore();
        cin.clear();
        cout << "Invalid Number. Please try again." << endl;
        continue;
      }
      if(players == 1) {
        cout << "Please enter difficulty: easy, medium, or hard" << endl;
        string difficulty;
        while(true) {
          cin >> difficulty;
          if(cin.eof()){
            break;
          }
          if (difficulty == "easy") {
            Easy *cpu = new Easy;
            c.setComputer(cpu);
            cpu->setBoard(&c);
            c.chooseToken();
            break;
          }
          else if(difficulty == "medium"|| difficulty == "hard") {
            cout << "Sorry, not implemented yet. Please try again." << endl;
            continue;
          }
          else if(cin.fail()) {
            cout << "Please try again" << endl;
            continue;
          }
          else{
            cout << "Please try again" << endl;
            continue;
          }
        }
        break;
      }
      else if(players == 2) {
        c.setComputer(NULL);
        c.setToken('0');
        break;
      }
      else{
        cin.ignore();
        cin.clear();
        cout << "Please try again." << endl;
        continue;
      }
    }
    cout << "Welcome to Connect 4! Who's going to start? Type R or Y." << endl;
    c.start();
}