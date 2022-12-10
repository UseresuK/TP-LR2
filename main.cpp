#include "Keeper.h"
#include "Sign.h"
#include "Menu.h"
#include <clocale>
#include <conio.h>
#include <Windows.h>

int main() {

	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	setlocale(LC_CTYPE, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Keeper<Sign> obj;

	int menu;
	system("cls");
	Menu(obj, "zodiac.txt");
	return 0;
}