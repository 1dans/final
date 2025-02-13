#include "getStarted.h"
#include "notrelated.h"
#include "mainProccess.h"
#include <vector>
#include<iostream>
#include <string>

#define s Sleep
#define T cout
#define E endl

using namespace Structures;
using namespace std;

void getStarted::starting(int size)
{

    vector<vector<int>> matrix(size, vector<int>(size));
    matrix = shuffleMatrix(matrix, size);
    showText("Перемішуємо ", 45);
    showText("......", 250);
    main_process(matrix, size);
}

void getStarted::welcome()
{
    system("cls");
    for (int i = 0; i < 60; ++i) T << '-';
    string beginning[5]{ "Вітаю!", "Виберіть розмір поля для п'ятнашек. ", "1 - (4x4)", "2 - (3x3)", "Ваш вибір: " };
    for (string i : beginning) {
        T << E;
        showText(i, 25);
    }
    get_answer();
}

void getStarted::get_answer()
{
    int size = 0, answer = 0;
    while (answer != 1 && answer != 2) {
        cin >> answer;
        switch (answer) {
        case 1: size = 4; break;
        case 2: size = 3; break;
        default:  showText("Спробуйте ще раз. Ваш вибір(1/2): ", 20); break;
        }
    }
    starting(size);

}
