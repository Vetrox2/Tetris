#include "tests.h"

bool TestMoveLeft(TStudnia s, int row, int col, Klocki klocek) {
    col--;
    if (col < 0)
        return false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((s[row + i][col + j] == 10 || s[row + i][col + j] == 5) && klocek.uklad[klocek.CurrentUklad][i][j] == 1)
                return false;
        }
    }
    return true;
}
bool TestMoveRight(TStudnia s, int row, int col, Klocki klocek) {
    col++;
    if (col == 13)
        return false;
    if (col < 13) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (col + j < 15)
                    if ((s[row + i][col + j] == 10 || s[row + i][col + j] == 5) && klocek.uklad[klocek.CurrentUklad][i][j] == 1)
                        return false;
            }
        }
    }
    return true;
}
bool TestMoveDown(TStudnia s, int row, int col, Klocki klocek) {
    row++;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((s[row + i][col + j] == 10 || s[row + i][col + j] == 5) && klocek.uklad[klocek.CurrentUklad][i][j] == 1)
                return false;
        }
    }
    return true;
}
bool TestTurn(TStudnia s, int row, int col, Klocki klocek) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((s[row + i][col + j] == 10 || s[row + i][col + j] == 5) && klocek.uklad[klocek.CurrentUklad][i][j] == 1)
                return true;
        }
    }
    return false;
}