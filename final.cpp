#include <iostream>
#include "getStarted.h"

using namespace std;

int main()
{
    getStarted start;
    srand(time(NULL));
    system("chcp 1251>null");
    start.welcome();
}