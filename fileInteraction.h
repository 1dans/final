#pragma once
#include <iostream>
#include <vector>
using namespace std;


namespace Statistics {
	typedef struct {
		double time;
		int moves, size;
	} Statistic;
}

using namespace Statistics;

class fileInt
{
public:
	void saveToFile(Statistic stats, string fileName);
	vector<Statistic> getFromFile(string fileName);
	void showStats();
};



