#pragma once
#include "functions.h"
#include "Klocki.h"

bool TestMoveLeft(TStudnia s, int row, int col, Klocki klocek);
bool TestMoveRight(TStudnia s, int row, int col, Klocki klocek);
bool TestMoveDown(TStudnia s, int row, int col, Klocki klocek);
bool TestTurn(TStudnia s, int row, int col, Klocki klocek);