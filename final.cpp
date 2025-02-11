#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <iomanip>
#include <fstream>
#define E endl
#define T cout
#define s Sleep
using namespace std;

typedef struct {
    char row;
    int col;
} Pos;

typedef struct {
    int x, y;
} Zero;

void time(string text, int t) {
    for (char i : text) {
        T << i;
        s(t);
    }
}

vector<vector<int>> shuffle(vector<vector<int>> matrix, int size) {
    vector<int> numbers;
    int index = 0;
    for (int i = 1; i < size * size; ++i) numbers.push_back(i);
    numbers.push_back(0);
    random_shuffle(numbers.begin(), numbers.end());
    for (int i = 0; i < size; ++i) for (int j = 0; j < size; ++j) matrix[i][j] = numbers[index++];
    return matrix;
}

void show_matrix(vector<vector<int>> matrix, int size) {
    system("cls");
    int count = 1;
    string green = "\033[32m", clean = "\033[0m";
    T << setw(size == 4 ? 15 : 12) << right << "П'ятнашки" << E;
    string colsName[4] = { "a", "b", "c", "d" };
    for (int i = 1; i < size+1; ++i) T << setw(4) << right << i;
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

int defineX(Pos position) {
    switch (position.row) {
    case 'a': return 0; break;
    case 'b': return 1; break;
    case 'c': return 2; break;
    case 'd': return 3; break;
    default: return -1; break;
    }
}

vector<vector<int>> move(vector<vector<int>> matrix, int size, int x, int y, Zero zero) {
    int x0 = zero.x;
    int y0 = zero.y;
    swap(matrix[x][y], matrix[x0][y0]);
    return matrix;
}

Zero findZero(vector<vector<int>> matrix, int size) {
    Zero zero = {0, 0};
    for (int i = 0; i < size; ++i) {
        for(int j = 0; j<size; ++j) {
            if (matrix[i][j] == 0) {
                zero.x = i;
                zero.y = j;
                return zero;
            }
        }
    }
}

bool canMove(vector<vector<int>> matrix, int size, int x, int y) {
    if (x < 0 || x >= size || y < 0 || y >= size) return false;
    else if ((x - 1 >= 0 && matrix[x - 1][y] == 0) ||
        (x + 1 < size && matrix[x + 1][y] == 0) ||
        (y - 1 >= 0 && matrix[x][y - 1] == 0) ||
        (y + 1 < size && matrix[x][y + 1] == 0)) return true;
    return false; // про всяк випадок
    
}

bool winCheck(vector<vector<int>> matrix, int size){
    int needed = (size * size) - 1, count=1, good=0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] == count) good++;
            count++;
        }
    }
    if (good == needed) return true;
    else return false;
}

void main_process(vector<vector<int>> matrix, int size) {
    while (!winCheck(matrix, size)) {
        int x, y;
        show_matrix(matrix, size);
        Pos position;
        T << "Яку клітинку ви хотіли би перемістити?\nНапишіть позицію (через пробіл, спочатку літера, потім число(наприклад: a 1)) : ";
        while (true) {
            cin >> position.row >> position.col;
            x = defineX(position);
            y = position.col - 1;
            if (!canMove(matrix, size, x, y)) time("Спробуйте знову. Вводіть в форматі a 1 (буква відповідає за рядок, цифра за стовпець): ", 30);
            else break;
        }
        Zero zero = findZero(matrix, size);
        matrix = move(matrix, size, x, y, zero);
        show_matrix(matrix, size);
    }
}

void start(int size) { //П'ятнашки
    vector<vector<int>> matrix(size, vector<int>(size));
    matrix = shuffle(matrix, size);
    time("Перемішуємо ", 60);
    time("......", 250);
    main_process(matrix, size);
}

void welcome() {
    for (int i = 0; i < 60; ++i) T << '-';
    string beginning[5]{  "Вітаю!", "Виберіть розмір поля для п'ятнашек. ", "1 - (4x4)", "2 - (3x3)", "Ваш вибір: " };
    for (string i : beginning) {
        T << E;
        time(i, 25);
    }
}

void get_answer() {
    int size = 0, answer = 0;
    while (answer != 1 && answer != 2) {
        cin >> answer;
        switch (answer) {
        case 1: size = 4; break;
        case 2: size = 3; break;
        default:  time("Спробуйте ще раз. Ваш вибір(1/2): ", 20); break;
        }
    }
    start(size);
    
}

int main()
{
    srand(time(NULL));
    system("chcp 1251>null");
    welcome();
    get_answer();
    
}