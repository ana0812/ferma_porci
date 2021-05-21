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
	friend void istoric_adaugare(string, int, string);
	friend void registru_adaugare(string nrBoxa, int greutate, string data);
	friend void stergere();
	friend void stergere_pt2(int, const int&);
	//friend void istoric_stergere(int c, string dp, string codBoxa);
	friend void registru_stergere(int c, string dp, string nrBoxa);
	friend void istoric();
	friend void statisticaBoxe();
};

