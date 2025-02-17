#include "fileInteraction.h"
#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>
#define E endl
using namespace std;

void fileInt::saveToFile(int moves, string fileName)
{
	ofstream file(fileName, ios::app);
	if (!file) {
		cout << "Помилка відкриття файлу" << E;
		return;
	}
	file << moves;
	file.close(); 
	cout << "Дані записані.";
}

void fileInt::getFromFile(string fileName)
{
	ifstream file(fileName);
	if (!file) {
		cout << "Помилка відкриття файлу" << E;
		return;
	}
	string line = "";
	while (getline(file, line)) {
		cout << line << E;
	}
	file.close();
	cout << "Дані отримані.";
}


