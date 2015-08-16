#ifndef COMPUTER
#define COMPUTER

class Connect;

class Computer{
  protected:
  Connect* theBoard;
  public:
  virtual void makeMove() = 0;
  virtual void setBoard(Connect*) = 0;
};

#endif
