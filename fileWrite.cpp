#include "fileWrite.h"
#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;

void fileWrite::saveToFile(int moves, string fileName)
{
	ofstream file(fileName, ios::app);
	if (!file) {
		cout << "Помилка відкриття файлу";
		return;
	}
	file << moves;
	
	file.close();
}
