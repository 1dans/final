#include "getStarted.h"
#include "notrelated.h"
#include "mainProccess.h"
#include "fileInteraction.h"
#include "Bot.h"

#include <vector>
#include<iostream>
#include <string>
#include <iomanip>

#define s Sleep
#define T cout
#define E endl

using namespace Structures;
using namespace std;

void getStarted::starting(vector<vector<int>> matrix, int size)
{
    int modeChoice = 0;
    Bot bot;
    string prep[4]{ "������ ����� ������.", "1 - ������ (����������)", "2 - ����'������� (���)", "��� ����: " };
    for (string i : prep) {
        T << E;
        showText(i, 25);
    }
    while (modeChoice != 1 && modeChoice != 2) {
        cin >> modeChoice;
        if (modeChoice == 1) main_process(matrix, size);
        else if (modeChoice == 2) bot.start_bot(matrix, size);
        else { 
            showText("��������� �� ���. ��� ����(1/2): ", 20);
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

void getStarted::initializeMatrix(int size)
{

    vector<vector<int>> matrix(size, vector<int>(size));
    int matrixChoice = 0;
    string prep[4]{ "������ ����� ����������.", "1 - �����", "2 - ����'������", "��� ����: " }; // ��� ����� ������� ����� ���������� � �������� ���, ��� 1
    for (string i : prep) {
        T << E;
        showText(i, 25);
    }
    while (matrixChoice != 1 && matrixChoice != 2) {
        cin >> matrixChoice;
        if (matrixChoice == 1) matrix = shuffleMatrixUser(matrix, size);
        else if (matrixChoice == 2) {
            matrix = shuffleMatrixComputer(matrix, size);
            showText("��������� ", 45);
            showText("......", 250);
            T << E;
        }
        else { 
            showText("��������� �� ���. ��� ����(1/2): ", 20);
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    starting(matrix, size);
}

void getStarted::preparing15()
{
    cout << "\033[2J\033[1;1H";
    for (int i = 0; i < 60; ++i) T << '-';
    string prep[4]{ "������ ����� ����.", "1 - 4 x 4", "2 - 3 x 3", "��� ����: " };
    for (string i : prep) {
        T << E;
        showText(i, 25);
    }
    get15Answer();
}

void getStarted::welcome()
{
    cout << "\033[2J\033[1;1H";
    bool pashalkoUsed = false;
    for (int i = 0; i < 60; ++i) T << '-';
    string beginning[5]{ "³���!", "������� ���", "1 - �'�������", "2 - �����", "��� ����: " };
    for (string i : beginning) {
        T << E;
        showText(i, 25);
    }
    int gameAns = 0;
    while (gameAns != 1 && gameAns != 2) {
        cin >> gameAns;
        if (gameAns == 1)menu15();

        else if (gameAns == 2 && !pashalkoUsed) pashalko();

        else { 
            showText("��������� �� ���. ��� ����(1/2): ", 20);
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

void getStarted::pashalko()
{
    cout << "\033[2J\033[1;1H";
    showText ("� ����� ���� ��������� ��������...\n�������!", 64);
    return;
}

void getStarted::get15Answer()
{
    int size = 0, answer = 0;
    while (answer != 1 && answer != 2) {
        cin >> answer;
        switch (answer) {
        case 1: size = 4; break;
        case 2: size = 3; break;
        default:  
            showText("��������� �� ���. ��� ����(1/2): ", 20);
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
    }
    initializeMatrix(size);

}

void getStarted::menu15()
{
    int choice = 0;
    fileInt file;
    while (choice!=3) {
        menu15Show();
        cin >> choice;
        switch (choice) {
            case 1: preparing15(); break;
            case 2: file.showStats(); break;
            case 3: break;
            default:
                cout << "������ ������� ����" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
        }
    }
    cout << "�� ���������!";
}

void getStarted::menu15Show()
{
    cout << "\033[2J\033[1;1H";
    for (int i = 0; i < 60; ++i) T << '-';
    cout << endl << right << setw(35) << "�'�������";
    string menuText[]{ "������� ����", "1 - �����", "2 - ���������� ���������� ������� ����", "3 - �����", "��� ����: " };
    for (string i : menuText) {
        cout << endl;
        showText(i, 20);
    }
}
