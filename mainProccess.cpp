#include "mainProccess.h"
#include "notrelated.h"
#include "Bot.h"
#include "getStarted.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <Windows.h>


#define s Sleep
#define T cout
#define E endl

using namespace std;
using namespace Structures;

void mainProccess::main_process(vector<vector<int>> matrix, int size)
{
    Bot a;
    getStarted startt;
    int moves = 0;
    while (!winCheck(matrix, size)) {
        int x = 0, y = 0;
        show_matrix(matrix, size);
        Pos position;
        T << "Вписуйте відповідь через пробілю. Спочатку літера, потім число (наприклад: a 1)\nЯкщо хочете передати керування боту, впишіть 'q 0', 'q 1' щоб покинути програму\nЯку клітинку ви хотіли би перемістити?\nПозиція: ";
        while (true) {
            cin >> position.row >> position.col;
            if (position.row == 'q' && position.col == 0) a.start_bot(matrix, size);
            if (position.row == 'q' && position.col == 1) break;
            x = defineX(position); // 
            y = position.col - 1;
            if (!canMove(matrix, size, x, y)) showText("Спробуйте знову. Вводіть в форматі a 1 (буква відповідає за рядок, цифра за стовпець): ", 30);
            else break;
        }
        if (position.row == 'q' && position.col == 1) startt.welcome();
        if (position.row == 'q' && position.col == 0) a.start_bot(matrix, size);
        moves++;
        Zero zero = findZero(matrix, size);
        matrix = move(matrix, size, x, y, zero);
    }
    winning(moves);
}
