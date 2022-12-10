
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <algorithm>


using namespace std;
template <class T>
class Keeper {

	T* ptr_mas;
	int size;
public:
	Keeper() { size = 0; ptr_mas = nullptr;/* cout << "Object  Keeper created" << endl;*/ };
	~Keeper() { delete[] ptr_mas; /*cout << "Object Keeper deleted" << endl; */ };

	void save(string);
	void read(string);
	void add();
	void del(int index);
	void print();
	void redaction(int index);
	void search_month();
	void sort_sign();
};


template<class T>
void Keeper<T>:: search_month() {
	int smonth;
	int cnt = 0;
	cout << "Введите месяц: ";
	cin >> smonth;
	if (size == 0)
		cout << "Нечего сортировать." << endl;
	else {

		for (int i = 0; i < size; i++) {

			if (ptr_mas[i].search(ptr_mas[i], smonth))
			{
				cout << ptr_mas[i] << endl;
			}
			else {
				cnt++;
			}
		}
	}
	if (cnt == size)
	{
		cout << "Людей, рожденных в этом месяце, не найдено"<< endl;
	}
}

template<class T>
void Keeper<T>::sort_sign() {
	
	if (size == 0) {
		cout << "Нечего сортировать" << endl;
	}
	else {
		T tmp;
		for (int i = 0; i < size; i++) {
			for (int j = (size - 1); j >= (i + 1); j--) {
				if (ptr_mas[j].sort(ptr_mas[j]) < ptr_mas[j - 1].sort(ptr_mas[j - 1])) {
					tmp = ptr_mas[j];
					ptr_mas[j] = ptr_mas[j - 1];
					ptr_mas[j - 1] = tmp;
				}
			}
		}
	}
	cout << "Сортировка выполнена успешно" << endl;
}

template<class T>
void Keeper<T>::redaction(int index) {

	if (size == 0)
		cout << "Нечего редактировать." << endl;
	else {

		try {

			if (index > size - 1 || index < 0)
				throw exception("Невозможно редактировать данные о человеке с таким номером");
		}
		catch (exception& ex) {
			while (index < 0 || index > size - 1) {
				cout << ex.what() << endl;
				cout << "Введите номер снова(начиная с нуля)" << endl;
				cin >> index;
			}
		}

		T* tmp = new T[size];
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (i != index) {
				tmp[j++] = ptr_mas[i];
			}
			else {
				cout << ptr_mas[i] << endl;
				ptr_mas[i].redact(ptr_mas[i]);
			}
		}
		cout << "Данные были успешно отредактированны" << endl;
	}
}

template<class T>
void Keeper<T>::save(string s) {
	ofstream fout(s, ios::out);

	try {
		if (size == 0)
			throw exception("Нет данных для сохранения");

		fout << size << endl;
		for (int i = 0; i < size; i++) {
			fout << ptr_mas[i] << endl;
		}
		cout << "Файл успешно сохранен" << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	fout.close();
}

template<class T>
void Keeper<T>::read(string s) {
	ifstream fin(s, ios::in);

	fin >> size;

	if (ptr_mas != nullptr)
		delete[] ptr_mas;

	ptr_mas = new T[size];

	for (int i = 0; i < size; i++) {
		fin >> ptr_mas[i];
	}

	cout << "Файл успешно прочитан" << endl;
	fin.close();
}

template<class T>
void Keeper<T>::add() {
	T* tmp = new T[size + 1];
	for (int i = 0; i < size; i++) {
		tmp[i] = ptr_mas[i];
	}
	delete[] ptr_mas;
	cin >> tmp[size];
	ptr_mas = tmp;
	size++;
}

template<class T>
void Keeper<T>::del(int index) {
	if (size == 0)
		cout << "Нечего удалять." << endl;
	else {

		try {

			if (index > size - 1 || index < 0)
				throw exception("Невозможно удалить человека с таким номером.");
		}
		catch (exception& ex) {
			while (index < 0 || index > size - 1) {
				cout << ex.what() << endl;
				cout << "Введите номер снова(начиная с нуля):" << endl;
				cin >> index;
			}
		}
		for (int i = 0; i < size; i++) {
			cout << ptr_mas[i] << endl;
		}
		T* tmp = new T[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (i != index)
				tmp[j++] = ptr_mas[i];
		}
		delete[] ptr_mas;
		ptr_mas = tmp;
		size--;
		cout << "Данные были успешно удалены" << endl;
	}
}

template<class T>
void Keeper<T>::print() {
	//sort_sign();
	if (size == 0)
		cout << "Нечего выводить" << endl;
	else
		for (int i = 0; i < size; i++) {
			cout << ptr_mas[i] << endl;
		}
}
