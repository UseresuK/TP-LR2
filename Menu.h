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
		cout << "1 - �������� �������� " << endl;
		cout << "2 - ������� �������� " << endl;
		cout << "3 - ������ �� ����� " << endl;
		cout << "4 - ��������� � ���� " << endl;
		cout << "5 - ������� ��� ������ " << endl;
		cout << "6 - ������������� ������ " << endl;
		cout << "7 - ������� �� ������ �������� " << endl;
		cout << "8 - ����������� � ���������� ������� �� ����� ������� " << endl;
		cout << "9 - ����� " << endl;

		cout << "�������� ��������: ";
		cin >> menu;
		switch (menu) {
		case 1: obj.add(); break;
		case 2: obj.print(); cout << "������� �����(������� � ����): "; cin >> index; obj.del(index); system("pause"); break;
		case 3: obj.read(s); system("pause"); break;
		case 4: obj.save(s); system("pause"); break;
		case 5: obj.print(); system("pause"); break;
		case 6: obj.print();  cout << "������� �����(������� � ����): "; cin >> index;  obj.redaction(index); system("pause"); break;
		case 7: obj.search_month(); system("pause"); break;
		case 8: obj.sort_sign(); system("pause"); break;
		case 9: flag = 0; break;
		default: cout << "Error" << endl; system("pause"); break;
		}
	}
}
