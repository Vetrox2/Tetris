#pragma once
#include "Klocki.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include "tests.h"
#include "ScreenFunc.h"
void WpiszKlocek(TStudnia s, int Row, int Col, Klocki klocek);
void UsunKlocek(TStudnia s, int Row, int Col);
bool SprawdzZapis(TStudnia s, int Row, int Col, Klocki klocek);
void ZapiszKlocek(TStudnia s, int Row, int Col, Klocki klocek);
void CheckStudnia(TStudnia s, int row, int col, int& punkty);
bool CheckDefeat(TStudnia s, int& punkty);
void AddToScreen(TStudnia s, int Row, int Col, Klocki klocek, int& punkty);
void start(TStudnia s, int row, int col, Klocki klocek, int& punkty);