#include "Sign.h"
#include "Keeper.h"

Sign::Sign() {
	cout << " ����������� ������ Sign �� ��������� ��� ������ " << endl;
	name = "��� ������";
	surname = "��� ������";
	zodiac = "��� ������";
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	voz = "��� ������";
}

Sign::Sign(const Sign& obj) {
	*this = obj;
}

Sign::~Sign() {
	cout << "���������� ������ Sign ��� ������ " << endl;
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
	out << "���: " << obj.name << endl;
	out << "�������: " << obj.surname << endl;
	out << "���� �������: " << obj.zodiac << endl;
	out << "���� ��������: " << obj.data[0] << endl;
	out << "����� ��������: " << obj.data[1] << endl;
	out << "��� ��������: " << obj.data[2] << endl;
	out << "�������: " << obj.voz << endl;
	return out;

}

istream& operator>>(istream& in, Sign& obj) {
	cout << "������� ���: ";
	getchar();
	getline(in, obj.name);

	cout << "������� �������: ";
	getline(in, obj.surname);

	cout << "������� ���� �������: ";
	getline(in, obj.zodiac);

	cout << "������� ���� ��������: ";
	while (!(in >> obj.data[0]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //���������� ���� ������, ���� ������� ����
		in.ignore(1000, '\n'); //���������� ���������� � ������ ������
		cout << "����������� �����: ";
	}

	cout << "������� ����� ��������: ";
	while (!(in >> obj.data[1]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //���������� ���� ������, ���� ������� ����
		in.ignore(1000, '\n'); //���������� ���������� � ������ ������
		cout << "����������� �����: ";
	}
	cout << "������� ��� ��������: ";
	while (!(in >> obj.data[2]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //���������� ���� ������, ���� ������� ����
		in.ignore(1000, '\n'); //���������� ���������� � ������ ������
		cout << "����������� �����: ";
	}

	if ((2022 - obj.data[2]) < 25)
		obj.voz = "�������";
	else
		obj.voz = "��������";

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
	cout << "��� �� ������ ��������������� (1-5) 0-�����: " << endl;
	cin >> index;
	switch (index)
	{
	case 1:
		cout << "������� ����� ���: ";
		getchar();
		getline(cin, obj.name);
		break;
	case 2:
		cout << "������� ����� �������: ";
		cin >> obj.surname;
		break;
	case 3:
		cout << "������� ����� ���� �������: ";
		cin >> obj.zodiac;
		break;
	case 4:
		cout << "������� ����� ���� ��������: ";
		cin >> obj.data[0];
		cout << "������� ����� ����� ��������: ";
		cin >> obj.data[1];
		cout << "������� ����� ��� ��������: ";
		cin >> obj.data[2];
		break;
	case 5:
		cout << "������� ����� �������: ";
		cin >> obj.voz;
		break;
	case 6:
		cout << "�������� ��������������" << endl;
		break;
	default:
		break;
	}

}