#pragma once
#include<iostream>
using namespace std;

class Animale
{
	string tip;
	int cnp;
	float greutate;
	string dataVenirii, dataEliberarii;
	friend class Boxa;
	friend class Ferma;
public:
	Animale(string t = "", int c = 0, float g = 0, string dv = "");
	friend ostream& operator<<(ostream&, const Animale&);
	friend void inserare();
	friend void istoric(string, int, string);
	friend void registru_adaugare(string nrBoxa, int greutate, string data);
};

