#pragma once
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
const int RowCount = 20, ColCount = 15;
typedef int TStudnia [RowCount][ColCount];
typedef int TUklad[4][4];

class Klocki {
public:
	TUklad uklad[4]; //4 uklady, wymiar 4/4
	int CurrentUklad = 0;
	void TurnLeft();
	void TurnRight();
	Klocki(string FileName);
};