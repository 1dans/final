#include "notrelated.h"
#include "fileInteraction.h"
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
using namespace Statistics;


bool notrelated::canMove(vector<vector<int>> matrix, int size, int x, int y) 
{
    if (x < 0 || x >= size || y < 0 || y >= size) return false;
    else if ((x - 1 >= 0 && matrix[x - 1][y] == 0) ||
        (x + 1 < size && matrix[x + 1][y] == 0) ||
        (y - 1 >= 0 && matrix[x][y - 1] == 0) ||
        (y + 1 < size && matrix[x][y + 1] == 0)) return true;
    return false; // про всяк випадок
}

void notrelated::showText(string text, int t) {
    for (char i : text) {
        T << i;
        s(t);
    }
}

void notrelated::winning(Statistic stat) {
    cin.ignore(10000, '\n');
    T << E;
    int minutes = stat.time / 60;
    showText("Вітаю! Ви виграли, використав ", 30);
    T << stat.moves;
    showText(" ходів, витративши ", 30);
    T << minutes;
    showText(" хвилин та ", 30);
    T << stat.time;
    showText(" секунд", 30);
    T << E;
    fileInt save;
    save.saveToFile(stat, "statistics.txt");
    getStarted start;
    cout << "Нажміть ENTER для повернення в головне меню..." << endl;
    cin.ignore(10000, '\n');
    start.menu15();
}

int notrelated::defineX(Pos position) {
    switch (position.row) {
    case 'a': return 0; break;
    case 'b': return 1; break;
    case 'c': return 2; break;
    case 'd': return 3; break;
    default: return -1; break;
    }
}

vector<vector<int>> notrelated::move(vector<vector<int>> matrix, int size, int x, int y, Zero zero) {
    int x0 = zero.x;
    int y0 = zero.y;
    swap(matrix[x][y], matrix[x0][y0]);
    return matrix;
}

Zero notrelated::findZero(vector<vector<int>> matrix, int size) {
    Zero zero = { 0, 0 };
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] == 0) {
                zero.x = i;
                zero.y = j;
                return zero;
            }
        }
    }
    return zero;
}

bool notrelated::winCheck(vector<vector<int>> matrix, int size) {
    int needed = (size * size) - 1, count = 1, good = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] == count) good++;
            count++;
        }
    }
    if (good == needed) return true;
    else return false;
}