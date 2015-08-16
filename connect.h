#ifndef CONNECT
#define CONNECT

#include <string>
#include "easy.h"
#include "computer.h"

class Connect{
protected:
    char turn;
    char **board;
    char computer;
    std::string t;
    Computer *AI;
public:
    Connect();
    ~Connect();
    void switchTurn();
    void chooseToken();
    void setToken(char);
    void setComputer(Computer*);
    void printBoard();
    void start();
    void makemove(int i);
    char getState(int,int);
    void play();
    bool isDraw();
    bool winVert();
    bool winHoriz();
    bool winDiag1();
    bool winDiag2();
};

#endif