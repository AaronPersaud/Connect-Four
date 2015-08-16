#ifndef EASY
#define EASY

#include "computer.h"

class Easy: public Computer{
  public:
  void setBoard(Connect*);
  void makeMove();
};

#endif