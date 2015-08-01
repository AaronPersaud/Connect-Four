#include <string>

class Connect{
    char turn;
    char **board;
    std::string t;
public:
    Connect();
    ~Connect();
    void printBoard();
    void start();
    void makemove(int i);
    void play();
    bool isDraw();
    bool winVert();
    bool winHoriz();
    bool winDiag1();
    bool winDiag2();
};