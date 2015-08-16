#include "easy.h"
#include "connect.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void Easy::setBoard(Connect* connect) {
  theBoard = connect;
}

void Easy::makeMove() {
  int x  = rand()%7 + 1;
  if (theBoard->getState(x-1,0) != '-') {
    makeMove();
  }
  else{
    cout << "The computer plays " << x << "." << endl;
    theBoard->makemove(x-1);
  }
}