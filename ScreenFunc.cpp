#include "ScreenFunc.h"
void EnterScreen() {
    system("Color 0A");
    cout << "WELCOME\n  TO\nTETRIS 2.0" << endl;
    Sleep(2000);
    system("Color 0D");
    cout << "press anything to continue" << endl;
    _getch();
    system("cls");
    system("Color 07");
}
void menu() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(out, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\tTETRIS 2.0\n";
    SetConsoleTextAttribute(out, 0 | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    cout << "1.Start game\n2.Customise(not working yet)\n3.Exit\n";
    switch (_getch())
    {
    case '1': system("cls"); return;  break;
    case '2': exit(0); break;
    case '3': exit(0); break;
    default:
        exit(0); break;
    }
}
void ShowNextK(int NextK, HANDLE out) {
    string FileName;
    switch (NextK) {
    case 1: FileName = "klocek1.txt"; break;
    case 2: FileName = "klocek2.txt"; break;
    case 3: FileName = "klocek3.txt"; break;
    case 4: FileName = "klocek4.txt"; break;
    case 5: FileName = "klocek5.txt"; break;
    case 6: FileName = "klocek6.txt"; break;
    }
    ifstream odc(FileName);
    int odc1;
    short x = 20, y = 6;
    SetConsoleCursorPosition(out, { x, y });
    cout << "NEXT KLOCEK";
    y++;
    SetConsoleCursorPosition(out, { x, y });
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            odc >> odc1;
            switch (odc1)
            {
            case 1: SetConsoleTextAttribute(out, BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_GREEN); cout << "*"; break;
            case 0: SetConsoleTextAttribute(out, 0); cout << " "; break;
            default: SetConsoleTextAttribute(out, 0); cout << " "; break;
            }
        }
        y++;
        SetConsoleCursorPosition(out, { x, y });

    }
    SetConsoleTextAttribute(out, 0 | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}
void wyswietl(TStudnia s, int& punkty) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(out, { 0,0 });
    cout << "Punkty: " << punkty << endl << endl;
    for (int i = 0; i < RowCount; i++) {
        for (int j = 0; j < ColCount; j++) {
            switch (s[i][j])
            {
            case 1: SetConsoleTextAttribute(out, BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_GREEN); cout << "*"; break;
            case 5: SetConsoleTextAttribute(out, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN); cout << "#"; break;
            case 10: SetConsoleTextAttribute(out, BACKGROUND_RED | FOREGROUND_RED); cout << "|"; break;
            case 0: SetConsoleTextAttribute(out, 0); cout << " "; break;
            default: SetConsoleTextAttribute(out, 0); cout << " "; break;
            }
        }
        cout << endl;
    }
    SetConsoleTextAttribute(out, 0 | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}
void DefeatScreen(int& punkty) {
    system("cls");
    cout << "DEFEAT" << endl;
    cout << "Ilosc zdobytych punktow: " << punkty << endl;
    cout << "press anything to continue" << endl;
    _getch();
    system("cls");
}