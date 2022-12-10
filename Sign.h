#pragma once
#include "Keeper.h"

class Sign {
protected:
	string name;
	string surname;
	string zodiac;
	int data[3];
	string voz;

public:
	
	Sign();
	Sign(const Sign& obj);
	~Sign();

	Sign& operator= (const Sign& other);
	void redact(Sign&);
	string sort(Sign&);
	bool search(Sign&, int);
	friend ostream& operator<<(ostream&, Sign&);
	friend istream& operator>>(istream&, Sign&);
	friend ofstream& operator<<(ofstream&, Sign&);
	friend ifstream& operator>>(ifstream&, Sign&);
};