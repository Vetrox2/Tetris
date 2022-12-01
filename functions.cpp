#include "functions.h"


void WpiszKlocek(TStudnia s, int Row, int Col, Klocki klocek) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if(Col+j<15)
                if (s[Row + i][Col + j] == 0)
                    s[Row + i][Col + j] = klocek.uklad[klocek.CurrentUklad][i][j];
        }
    }
}
void UsunKlocek(TStudnia s, int Row, int Col) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (Col + j < 15)
                if (s[Row + i][Col + j] == 1)
                    s[Row + i][Col + j] = 0;
        }
    }
}
bool SprawdzZapis(TStudnia s, int Row, int Col, Klocki klocek) {
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (Col + j < 15)
                if (klocek.uklad[klocek.CurrentUklad][i][j] == 1 && (s[Row + i + 1][5] == 10 || s[Row + i + 1][Col+j] == 5)) {
                    return true;
                }
        }
    }
    return false;
}
void ZapiszKlocek(TStudnia s, int Row, int Col, Klocki klocek) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (Col + j < 15)
                if (klocek.uklad[klocek.CurrentUklad][i][j] == 1)
                    s[Row + i][Col + j] = 5;
        }
    }
}
void CheckStudnia(TStudnia s, int row, int col, int& punkty) {
    for (int i = 19; i >= 0; i--) {
        bool t = true;
        for (int j = 1; j < 14; j++) {
            if (s[i][j] != 5)
                t = false;
        }
        if (t) {
            punkty++;
            for (int j = 1; j < 14; j++)
                s[i][j] = 0;
            for (int h = i; h > 0; h--) {
                for (int j = 1; j < 14; j++) {
                    if (s[h - 1][j] == 5) {
                        s[h][j] = 5;
                        s[h - 1][j] = 0;
                    }
                }
            }
            i++;
        }
    }
}
bool CheckDefeat(TStudnia s, int& punkty) {
        for (int j = 1; j < 14; j++) {
            if (s[1][j] == 5) {
                DefeatScreen(punkty);
                punkty = 0;
                return true;
            }
        }
        return false;
}
void ClearStudnia(TStudnia s) {
    for (int i = 0; i < 19; i++) {
        for (int j = 1; j < 14;j++) {
            s[i][j] = 0;
        }
    }
}
void AddToScreen(TStudnia s, int Row, int Col, Klocki klocek, int& punkty) {
    WpiszKlocek(s, Row, Col, klocek);
    wyswietl(s, punkty);
    UsunKlocek(s, Row, Col);
}

void start(TStudnia s, int row, int col, Klocki klocek, int& punkty) {
    while (true) {
        while (_kbhit())
            _getch();
        AddToScreen(s, row, col, klocek, punkty);
        Sleep(300);
        bool changedrow = false;
        int licznik = 0;
        while (_kbhit()) {
            bool changed = false;
            changedrow = false;
            char button = _getch();
            switch (button)
            {
            case 'q': 
                klocek.TurnLeft(); 
                if (TestTurn(s, row, col, klocek)) 
                    { klocek.TurnRight(); } 
                else changed = true; 
                break;
            case 'e': 
                klocek.TurnRight(); 
                if (TestTurn(s, row, col, klocek)) 
                { klocek.TurnLeft(); }
                else changed = true;
                break;
            case 'a': if (TestMoveLeft(s, row, col, klocek)) { col--; changed = true;} break;
            case 'd': if (TestMoveRight(s, row, col, klocek)) { col++; changed = true;} break;
            case 's': if (TestMoveDown(s, row, col, klocek)) { row++; } changedrow = true; break;
            default:
                break;
            }
            if (changed) {
                licznik++;
                AddToScreen(s, row, col, klocek, punkty);
                Sleep(100);
            }
            if (SprawdzZapis(s, row, col, klocek)) {
                ZapiszKlocek(s, row, col, klocek);
                CheckStudnia(s, row, col, punkty);
                if (CheckDefeat(s, punkty)) {
                    ClearStudnia(s);
                    menu();
                    return;
                }
                return;
            }
            if (changedrow) {
                changedrow = false;
                AddToScreen(s, row, col, klocek, punkty);
                Sleep(50);
            }
            if (licznik > 2)
                break;
        }
        if (SprawdzZapis(s, row, col, klocek)) {
            ZapiszKlocek(s, row, col, klocek);
            CheckStudnia(s, row, col, punkty);
            if (CheckDefeat(s, punkty)) {
                ClearStudnia(s);
                menu();
                return;
            }
            return;
        }
        row++;
    }
}