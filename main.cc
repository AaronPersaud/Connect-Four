#include "connect.h"
#include <iostream>

using namespace std;

int main() {
    Connect c;
    cout << "Welcome to Connect 4! Who's going to start? Type R or Y." << endl;
    c.start();
}