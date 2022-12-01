#include "Klocki.h"

void Klocki::TurnLeft() {
	CurrentUklad++;
	if (CurrentUklad > 3)
		CurrentUklad = 0;
}
void Klocki::TurnRight() {
	CurrentUklad--;
	if (CurrentUklad < 0)
		CurrentUklad = 3;
}
Klocki::Klocki(string FileName) {
	int wrzuc = 0;
	ifstream x(FileName);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int h = 0; h < 4; h++) {
				x >> wrzuc;
				uklad[i][j][h] = wrzuc;
			}
		}
	}
}
