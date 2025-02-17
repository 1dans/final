#pragma once
#include "notrelated.h"
#include <iostream>
#include <vector>
#include "getStarted.h"
using namespace std;

class Bot:public getStarted
{
public:
	void start_bot(vector<vector<int>> matrix, int size);
};

