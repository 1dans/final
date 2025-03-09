#pragma once
#include <vector>
#include<iostream>
#include <string>
#include "Matrix.h"
#include "fileInteraction.h"

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
using namespace Statistics;

class notrelated: public Matrix
{
public:
    
    bool canMove(vector<vector<int>> matrix, int size, int x, int y);
    void showText(string text, int t);
    void winning(Statistic stat);
    int defineX(Pos position);
    vector<vector<int>> move(vector<vector<int>> matrix, int size, int x, int y, Zero zero);
    Zero findZero(vector<vector<int>> matrix, int size);
    bool winCheck(vector<vector<int>> matrix, int size);
};