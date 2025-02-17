#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Matrix
{
public:
	void show_matrix(vector<vector<int>> matrix, int size);
	vector<vector<int>> shuffleMatrixComputer(vector<vector<int>> matrix, int size);
	vector<vector<int>> shuffleMatrixUser(vector<vector<int>> matrix, int size);
};

