#include "connect.h"
#include <iostream>

using namespace std;

Connect::Connect() {
        board = new char *[7];
        for (int i = 0; i < 7; ++i)
        {
                board[i] = new char[6];
                for (int j = 0; j < 6; ++j)
                {
                        board[i][j] = '-';
                }
        }
}

Connect::~Connect() {
  for (int i = 0; i < 7; ++i) {
    delete [] board[i];
  }
  delete [] board;
}

void Connect::setToken(char c) {
 computer = c;
}

void Connect::chooseToken() {
  cout << "Please choose R or Y" <<  endl;
  char c;
  while(true) {
    cin >> c;
    if(cin.eof()) {
      break;
    }
    else if(c == 'R') {
      computer = 'Y';
      break;
    }
    else if(c == 'Y') {
      computer = 'R';
      break;
    }
    else{
      cout << "Try Again" << endl;
      continue;
    }
  }
}

void Connect::setComputer(Computer* c) {
  AI = c;
}

char Connect::getState(int x,int y) {
  return board[x][y];
}

bool Connect::isDraw() {
  return (board[0][0]!= '-' && board[1][0]!= '-' && board[2][0]!= '-' && board[3][0]!= '-' && board[4][0]!= '-' && board[5][0]!= '-' && board[6][0]!= '-');
}

bool Connect::winVert() {
  for (int i = 0; i < 7; ++i) {
    for (int j = 0; j < 3; ++j) {
        if (board[i][j]==board[i][j+1] && board[i][j+1] == board[i][j+2] && board[i][j+2] == board[i][j+3] && board[i][j] != '-')
        {
          cout << board[i][j] << " is the winner!!" << endl;
          return true;
        }
    }
  }
  return false;
}

bool Connect::winHoriz() {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 6; ++j) {
        if (board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j] && board[i+2][j] == board[i+3][j] && board[i][j] != '-')
        {
           cout << board[i][j] << " is the winner!!" <<  endl;
           return true;
        }
      }
    }
    return false;
}

bool Connect::winDiag1() {
  for (int i = 0; i < 4; ++i) {
    for (int j = 3; j < 6; ++j) {
      if (board[i][j]==board[i+1][j-1] && board[i+1][j-1] == board[i+2][j-2] && board[i+2][j-2] == board[i+3][j-3] && board[i][j] != '-')
      {
        cout << board[i][j] << " is the winner!!" << endl;
        return true;
      }
    }
  }
  return false;
}

bool Connect::winDiag2() {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (board[i][j]==board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2] && board[i+2][j+2] == board[i+3][j+3] && board[i][j] != '-')
      {
        cout << board[i][j] << " is the winner!!" << endl;
        return true;
      }
    }
  }
  return false;
}

void Connect::printBoard() {
        for (int j = 0; j < 6; ++j) {
            for (int i = 0; i < 7 ; ++i) {
                cout << board[i][j];
            }
      cout << endl;
    }
}

void Connect::makemove(int i) {
    int x = 5;
    while(x >= 0) {
        if (board[i][x] == '-') {
            break;
        }
        else {
            x--;
        }
    }
    board[i][x] = turn;
}

void Connect::start() {
    cin >> turn;
    if (cin.eof()) {
      return;
    }
    if (turn == 'R')
    {
      t = "Red";
      play();
    }
    else if (turn == 'Y')
    {
      t = "Yellow";
      play();
    }
    else {
      cout << "Error. Please type R or Y." << endl;
      start();
    }
}

void Connect::switchTurn() {
      if (turn == 'R')
      {
         turn = 'Y';
         t = "Yellow";
      }
      else {
        turn = 'R';
        t = "Red";
      }
}

void Connect::play() {
    printBoard();
    while(true) {
      if (cin.eof()) {
        break;
      }
      if(winVert()||winHoriz()||winDiag1()||winDiag2()) {
        break;
      }
      if(isDraw()) {
        cout << "It's a tie!" << endl;
        break;
      }
      if(cin.fail()) {
        cout << "You did not enter a number." << endl;
        cin.clear();
        cin.ignore();
        continue;
      }
      if(AI != NULL && turn == computer) {
       AI->makeMove();
       printBoard();
       switchTurn();
       continue;
      }
      int move;
      cout << t << ", give me a number from 1-7." << endl;
      cin >> move;
      if (move < 1 || move > 7) {
        cout << "Number outside of range. Please try again." << endl;
        continue;
      }
      if(board[move-1][0] != '-') {
        cout << "Cannot make move in this column. Please try again." << endl;
        continue;
      }
      makemove(move-1);
      printBoard();
      switchTurn();
    }
}

