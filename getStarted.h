#pragma once
#include "notrelated.h"
#include "mainProccess.h"
#include <vector>
#include<iostream>
#include <string>

using namespace std;

class getStarted: public mainProccess
{
public:
    void starting(vector<vector<int>> matrix, int size);
    void initializeMatrix(int size);
    void preparing15();
    void get15Answer();
    void menu15();
    void welcome();
};

