#pragma once
#include "notrelated.h"
#include <iostream>
#include <vector>

using namespace std;

class mainProccess: public notrelated
{
public:
	void main_process(vector<vector<int>> matrix, int size);
};

