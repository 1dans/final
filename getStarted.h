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
    void starting(int size);
    void get_answer();
    void welcome();
};

