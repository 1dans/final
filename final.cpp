#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define E endl;
#define T cout
using namespace std;


void menu() { //П'ятнашки
    T << "П'ятнашки" << E
    vector<vector<int>> matrix(3, vector<int>(3));
    vector<int> numbers;
    for (int i = 1; i <= 8; ++i) numbers.push_back(i);
    numbers.push_back(0);
    random_shuffle(numbers.begin(), numbers.end());
    int index = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = numbers[index++];
            T << matrix[i][j] << ' ';
        }
        T << E
    }
}


int main()
{
    srand(time(NULL));
    system("chcp 1251>null");
    menu();
}

