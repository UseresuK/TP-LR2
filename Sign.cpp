#include "Sign.h"
#include "Keeper.h"

Sign::Sign() {
	cout << " Конструктор класса Sign по умолчанию был вызван " << endl;
	name = "Нет данных";
	surname = "Нет данных";
	zodiac = "Нет данных";
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	voz = "Нет данных";
}

Sign::Sign(const Sign& obj) {
	*this = obj;
}

Sign::~Sign() {
	cout << "Деструктор класса Sign был вызван " << endl;
}

Sign& Sign::operator=(const Sign& other) {
	this->name = other.name;
	this->surname = other.surname;
	this->data[0] = other.data[0];
	this->data[1] = other.data[1];
	this->data[2] = other.data[2];
	this->zodiac = other.zodiac;
	this->voz = other.voz;
	return *this;
}

ostream& operator<<(ostream& out, Sign& obj) {
	out << "Имя: " << obj.name << endl;
	out << "Фамилия: " << obj.surname << endl;
	out << "Знак зодиака: " << obj.zodiac << endl;
	out << "День рождения: " << obj.data[0] << endl;
	out << "Месяц рождения: " << obj.data[1] << endl;
	out << "Год рождения: " << obj.data[2] << endl;
	out << "Возраст: " << obj.voz << endl;
	return out;

}

istream& operator>>(istream& in, Sign& obj) {
	cout << "Введите имя: ";
	getchar();
	getline(in, obj.name);

	cout << "Введите фамилию: ";
	getline(in, obj.surname);

	cout << "Введите знак зодиака: ";
	getline(in, obj.zodiac);

	cout << "Введите день рождения: ";
	while (!(in >> obj.data[0]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Попытайтесь снова: ";
	}

	cout << "Введите месяц рождения: ";
	while (!(in >> obj.data[1]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Попытайтесь снова: ";
	}
	cout << "Введите год рождения: ";
	while (!(in >> obj.data[2]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Попытайтесь снова: ";
	}

	if ((2022 - obj.data[2]) < 25)
		obj.voz = "Ребенок";
	else
		obj.voz = "Взрослый";

	return in;

}
	
string Sign::sort(Sign& obj)
{
	string str = zodiac;
	return str;
}
bool Sign::search(Sign& obj, int data)
{
	return data == obj.data[1];
}


ofstream& operator<<(ofstream& fout, Sign& obj) {
	fout << obj.name << endl;
	fout << obj.surname << endl;
	fout << obj.zodiac << endl;
	fout << obj.data[0] << endl;
	fout << obj.data[1] << endl;
	fout << obj.data[2] << endl;
	fout << obj.voz << endl;
	return fout;
}

ifstream& operator>>(ifstream& fin, Sign& obj) {

	fin.get();
	getline(fin, obj.name);
	getline(fin, obj.surname);
	getline(fin, obj.zodiac);
	fin >> obj.data[0];
	fin >> obj.data[1];
	fin >> obj.data[2];
	fin >> obj.voz;
	fin.get();
	return fin;
}

void Sign::redact(Sign& obj)
{
	int index;
	cout << "Что вы хотите отредактировать (1-5) 0-выход: " << endl;
	cin >> index;
	switch (index)
	{
	case 1:
		cout << "Введите новое имя: ";
		getchar();
		getline(cin, obj.name);
		break;
	case 2:
		cout << "Введите новую фамилию: ";
		cin >> obj.surname;
		break;
	case 3:
		cout << "Введите новый знак зодиака: ";
		cin >> obj.zodiac;
		break;
	case 4:
		cout << "Введите новый день рождения: ";
		cin >> obj.data[0];
		cout << "Введите новый месяц рождения: ";
		cin >> obj.data[1];
		cout << "Введите новый год рождения: ";
		cin >> obj.data[2];
		break;
	case 5:
		cout << "Введите новый возраст: ";
		cin >> obj.voz;
		break;
	case 6:
		cout << "Успешное редактирование" << endl;
		break;
	default:
		break;
	}

}