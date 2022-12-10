#pragma once
#include "Keeper.h"
#include "Sign.h"

template <typename T>
void Menu(T& obj, string s) {
	int menu;
	int index;
	string name;
	int flag = 1;
	while (flag) {
		system("cls");
		cout << "1 - Добавить человека " << endl;
		cout << "2 - Удалить человека " << endl;
		cout << "3 - Читать из файла " << endl;
		cout << "4 - Сохранить в файл " << endl;
		cout << "5 - Вывести все данные " << endl;
		cout << "6 - Редактировать данные " << endl;
		cout << "7 - Выбрать по месяцу рождения " << endl;
		cout << "8 - Сортировать в алфавитном порядке по знаку зодиака " << endl;
		cout << "9 - Выход " << endl;

		cout << "Выберите действие: ";
		cin >> menu;
		switch (menu) {
		case 1: obj.add(); break;
		case 2: obj.print(); cout << "Введите номер(начиная с нуля): "; cin >> index; obj.del(index); system("pause"); break;
		case 3: obj.read(s); system("pause"); break;
		case 4: obj.save(s); system("pause"); break;
		case 5: obj.print(); system("pause"); break;
		case 6: obj.print();  cout << "Введите номер(начиная с нуля): "; cin >> index;  obj.redaction(index); system("pause"); break;
		case 7: obj.search_month(); system("pause"); break;
		case 8: obj.sort_sign(); system("pause"); break;
		case 9: flag = 0; break;
		default: cout << "Error" << endl; system("pause"); break;
		}
	}
}
