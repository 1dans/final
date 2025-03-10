#include "fileInteraction.h"
#include "getStarted.h"

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>

#define E endl
using namespace std;
using namespace Statistics;

void fileInt::saveToFile(Statistic stats, string fileName)
{
	ofstream file(fileName, ios::app);
	if (!file) {
		cout << "Помилка відкриття файлу" << E;
		return;
	}
	file << stats.moves << ' ' << stats.time << ' ' << stats.size << E;
	file.close(); 
	cout << "Дані записані" << E;
}

vector<Statistic> fileInt::getFromFile(string fileName)
{	
	vector<Statistic> stats;
	ifstream file(fileName);
	if (!file) {
		cout << "Помилка відкриття файлу" << E;
		return stats;
	}
	
	Statistic stat;
	int size;
	while (file>>stat.moves>>stat.time>>stat.size) {
		stats.push_back(stat);
	}
	file.close();
	cout << "Дані отримані." << E;
	return stats;
}

void fileInt::showStats()
{
	cin.ignore();
	cout << "\033[2J\033[1;1H";
	vector<Statistic> stats;
	stats = getFromFile("statistics.txt");
	cout << "Усі дані з файлу: \n";
	int count = 1;
	for (auto i : stats) {
		cout << "Гра " << count << ": Зроблено ходів " << i.moves << ". Пройдено за " << int(i.time / 60) << " хвилин та " << i.time - (int(i.time / 60))*60 << " секунд." << " Розмір поля: " << i.size << 'x' << i.size << endl;
		count++;
	}
	cout << "Введіть ENTER, щоб повернутися в головне меню...";
	cin.ignore();
	getStarted start;
	start.menu15Show();
}


