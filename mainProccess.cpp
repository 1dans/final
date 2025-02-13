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
        int x, y;
        show_matrix(matrix, size);
        Pos position;
        T << "якщо хочете передати керуванн€ боту, впиш≥ть 'q 0' та 'q 1' щоб покинути програму";
        T << "яку кл≥тинку ви хот≥ли би перем≥стити?\nЌапиш≥ть позиц≥ю (через проб≥л, спочатку л≥тера, пот≥м число(наприклад: a 1)) : ";
        while (true) {
            cin >> position.row >> position.col;
            if (position.row == 'q' && position.col == 0) a.start_bot();
            if (position.row == 'q' && position.col == 1) break;
            x = defineX(position);
            y = position.col - 1;
            if (!canMove(matrix, size, x, y)) showText("—пробуйте знову. ¬вод≥ть в формат≥ a 1 (буква в≥дпов≥даЇ за р€док, цифра за стовпець): ", 30);
            else break;
        }
        if (position.row == 'q' && position.col == 1) startt.welcome();
        moves++;
        Zero zero = findZero(matrix, size);
        matrix = move(matrix, size, x, y, zero);
    }
    winning(moves);
}
