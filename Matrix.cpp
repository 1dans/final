#include "Matrix.h"
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

void Matrix::show_matrix(vector<vector<int>> matrix, int size)
{
    system("cls");
    int count = 1;
    string green = "\033[32m", clean = "\033[0m", purple = "\033[35m";
    T << setw(size == 4 ? 15 : 12) << right << "П'ятнашки" << E;
    string colsName[4] = { "a", "b", "c", "d" };
    for (int i = 1; i < size + 1; ++i) T << purple << setw(4) << right << i << clean;
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

vector<vector<int>> Matrix::shuffleMatrixComputer(vector<vector<int>> matrix, int size)
{
    vector<int> numbers;
    int index = 0;
    for (int i = 1; i < size * size; ++i) numbers.push_back(i);
    numbers.push_back(0);
    random_shuffle(numbers.begin(), numbers.end());
    for (int i = 0; i < size; ++i) for (int j = 0; j < size; ++j) matrix[i][j] = numbers[index++];
    return matrix;
}

vector<vector<int>> Matrix::shuffleMatrixUser(vector<vector<int>> matrix, int size)
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = 0;
        }
    int count = 1, x = 0, y = 0;
    Pos position;
    notrelated d;
    while (count!=size*size){
            show_matrix(matrix, size);
            cout << "Куди розмістити число " << count << "? ";
            cin >> position.row >> position.col;
            y = position.col - 1;
            x = d.defineX(position);
            if (x > size - 1 || y > size - 1 || y < 0 || x < 0) { 
                cout << "Помилка, спробуйте ще раз"; 
                s(750);
            }
            else if (matrix[x][y] != 0) { cout << "Ця клітинка вже зайнята" << E; s(750); }
            else {
                matrix[x][y] = count;
                count++;
            }
        }
    return matrix;
}
