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
    while (!winCheck(matrix, size)) {
        int x = 0, y = 0;
        show_matrix(matrix, size);
        Pos position;
        T << "�������� ������� ����� ������. �������� �����, ���� ����� (���������: a 1)\n���� ������ �������� ��������� ����, ������� 'q 0', 'q 1' ��� �������� ��������\n��� ������� �� ����� �� ����������?\n�������: ";
        while (true) {
            cin >> position.row >> position.col;
            if (position.row == 'q' && position.col == 0) a.start_bot(matrix, size);
            if (position.row == 'q' && position.col == 1) break;
            x = defineX(position); 
            y = position.col - 1;
            if (!canMove(matrix, size, x, y)) showText("��������� �����. ������ � ������ a 1 (����� ������� �� �����, ����� �� ��������): ", 30);
            else break;
        }
        if (position.row == 'q' && position.col == 1) startt.welcome();
        if (position.row == 'q' && position.col == 0) a.start_bot(matrix, size);
        moves++;
        Zero zero = findZero(matrix, size);
        matrix = move(matrix, size, x, y, zero);
    }
    auto endPC = steady_clock::now();
    duration<double> elapsedPC = endPC - startPC;
    double time = elapsedPC.count();
    Statistic stat = {time, moves, size};
    show_matrix(matrix, size);
    winning(stat);
}
