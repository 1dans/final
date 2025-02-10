#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <iomanip>
#include <fstream>
#define E endl;
#define T cout
#define s Sleep
using namespace std;

void time(string text, int t) {
    for (char i : text) {
        cout << i;
        s(t);
    }
}

vector<vector<int>> shuffle(vector<vector<int>> matrix, int row, int col) {
    vector<int> numbers;
    int index = 0;
    for (int i = 1; i < row * col; ++i) numbers.push_back(i);
    numbers.push_back(0);
    random_shuffle(numbers.begin(), numbers.end());
    for (int i = 0; i < row; ++i) for (int j = 0; j < col; ++j) matrix[i][j] = numbers[index++];
    return matrix;
}

void show_matrix(vector<vector<int>> matrix, int row, int col) {
    T << setw(row==4?15:12) << right << "�'�������" << E
    string colsName[4] = { "a", "b", "c", "d" };
    for (int i = 1; i < row+1; ++i) T << setw(4) << right << i;
    T << E
    if (row == 4) T << setw(16) << right << "-------------" << E
    if (row == 3) T << setw(12) << right << "---------" << E
    for (int i = 0; i < row; ++i) {
        T << setw(3) << left << colsName[i];
        for (int j = 0; j < col; ++j)T << setw(3) << left << matrix[i][j] << ' ';
        T << E
    }
}

void main_process(vector<vector<int>> matrix, int row, int col) {
    cout << "� ��������"; /*����� ������ ���� : ���� ������ ������(��������� �������), �����������(��������� � while (!win) 
    win ��������� ������� ��� �����������, ������� ������������ ��� ���) 
    ����������� ������ ���� ����������� ��� : ������������ �������� ����� ������ ����� �����������(�������� �2) �� ����� ������
    ��������� ������ �����������, �������� �� �����������) ���� ����� �� ����� ����� �� ����� �������������� �������*/
}

void menu(int row, int col) { //�'�������
    vector<vector<int>> matrix(row, vector<int>(col));
    matrix = shuffle(matrix, row, col);
    time("��������� ", 100);
    time("......", 200);
    system("cls");
    show_matrix(matrix, row, col);
}

void welcome() {
    for (int i = 0; i < 60; ++i) cout << '-';
    string beginning[5]{  "³���!", "������� ����� ���� ��� �'�������. ", "1 - (4x4)", "2 - (3x3)", "��� ����: " };
    for (string i : beginning) {
        T << E
        time(i, 40);
    }
}

void get_answer() {
    int row, col, answer=0;
    while (answer != 1 && answer != 2) {
        cin >> answer;
        switch (answer) {
        case 1: row = 4; col = 4; break;
        case 2: row = 3; col = 3; break;
        default:  time("��������� �� ���. ��� ����(1/2): ", 30); break;
        }
    }
    menu(row, col);
    
}

int main()
{
    srand(time(NULL));
    system("chcp 1251>null");
    welcome();
    get_answer();
    
}