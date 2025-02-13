#pragma once
#include <vector>
#include<iostream>
#include <string>

namespace Structures {
    typedef struct {
        char row;
        int col;
    } Pos;

    typedef struct {
        int x, y;
    } Zero;
};

using namespace std;
using namespace Structures;

class notrelated
{
public:
    void show_matrix(vector<vector<int>> matrix, int size);
    bool canMove(vector<vector<int>> matrix, int size, int x, int y);
    void showText(string text, int t);
    void winning(int moves);
    int defineX(Pos position);
    vector<vector<int>> shuffleMatrix(vector<vector<int>> matrix, int size);
    vector<vector<int>> move(vector<vector<int>> matrix, int size, int x, int y, Zero zero);
    Zero findZero(vector<vector<int>> matrix, int size);
    bool winCheck(vector<vector<int>> matrix, int size);
};