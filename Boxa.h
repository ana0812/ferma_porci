#pragma once
#include<iostream>
#include"Animale.h"
#include<vector>
using namespace std;
class Boxa
{
	string tip,cod;
	int nrPorci;
	vector <Animale> listaAnimale;
	friend class Ferma;
public:
	Boxa(string t="", int nrP=0, string c="");
	void SetLista(Animale& a);
	friend ostream& operator<<(ostream&, const Boxa&);
	friend void inserare();
	friend void istoric(string, int, string);
	friend void registru_adaugare(string nrBoxa, int greutate, string data);
};

