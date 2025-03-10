#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <Windows.h>
#include <chrono>

#include "mainProccess.h"
#include "notrelated.h"
#include "Bot.h"
#include "getStarted.h"
#include "fileInteraction.h"

#define s Sleep
#define T cout
#define E endl

using namespace std::chrono;
using namespace std;
using namespace Structures;
using namespace Statistics;

void mainProccess::main_process(vector<vector<int>> matrix, int size)
{
    Bot a;
    getStarted startt;
    int moves = 0;
    auto startPC = steady_clock::now();
    bool quit = false, startBot = false;
    while (!winCheck(matrix, size)) {
        bool canmove = false, errorflag = false;
        int x = 0, y = 0;
        show_matrix(matrix, size);
        Pos position;
        T << "Вписуйте відповідь через пробіл. Спочатку літера, потім число (наприклад: a 1)\nЯкщо хочете передати керування боту, впишіть 'q 1', 'q 2' щоб покинути програму\nЯку клітинку ви хотіли би перемістити?\nПозиція: ";
        while (!canmove) {
            cin >> position.row >> position.col;
            position.col--;
            x = defineX(position);
            y = position.col;
            if (!canMove(matrix, size, x, y) && !errorflag) {
                showText("Спробуйте знову. Вводіть в форматі a 1 (буква відповідає за рядок, цифра за стовпець)", 30);
                cin.clear();
                cin.ignore(10000, '\n');
                errorflag = true;
                break;
            }
            
            else { 
                canmove = true;
                break; 
            }
        }

        if (position.row == 'q' && position.col == 0) {
            startBot = true;
            break;
        }
        if (position.row == 'q' && position.col == 1) {
            quit = true;
            break;
        }
        if (canmove && !errorflag) {
            moves++;
            Zero zero = findZero(matrix, size);
            matrix = move(matrix, size, x, y, zero);
        }
    }
    if (startBot) {
        a.start_bot(matrix, size);
        return;
    }
    if (quit) { 
        startt.menu15(); 
        return;
    }
    auto endPC = steady_clock::now();
    duration<double> elapsedPC = endPC - startPC;
    double time = elapsedPC.count();

    Statistic stat = {time, moves, size};
    
    show_matrix(matrix, size);
    winning(stat);
}
