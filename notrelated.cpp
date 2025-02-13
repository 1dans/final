#include "notrelated.h"
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

void notrelated::show_matrix(vector<vector<int>> matrix, int size)
{
        system("cls");
        int count = 1;
        string green = "\033[32m", clean = "\033[0m";
        T << setw(size == 4 ? 15 : 12) << right << "П'ятнашки" << E;
        string colsName[4] = { "a", "b", "c", "d" };
        for (int i = 1; i < size + 1; ++i) T << setw(4) << right << i;
        T << E;
        if (size == 4) T << setw(16) << right << "-------------" << E;
        else if (size == 3) T << setw(12) << right << "---------" << E;
        for (int i = 0; i < size; ++i) {
            T << setw(3) << left << colsName[i];
            for (int j = 0; j < size; ++j) {
                if (matrix[i][j] == count) {
                    T << green << setw(3) << left << matrix[i][j] << clean << ' ';
                }
                else T << setw(3) << left << matrix[i][j] << ' ';
                count++;
            }
            T << E;
        }
}

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

void notrelated::winning(int moves) {
    system("cls");
    showText("Вітаю! Ви виграли, використав ", 30);
    T << moves;
    showText(" ходів.", 30);
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

vector<vector<int>> notrelated::shuffleMatrix(vector<vector<int>> matrix, int size) {
    vector<int> numbers;
    int index = 0;
    for (int i = 1; i < size * size; ++i) numbers.push_back(i);
    numbers.push_back(0);
    random_shuffle(numbers.begin(), numbers.end());
    for (int i = 0; i < size; ++i) for (int j = 0; j < size; ++j) matrix[i][j] = numbers[index++];
    return matrix;
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