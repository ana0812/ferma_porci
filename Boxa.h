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
	void StergePorc(int);
	friend ostream& operator<<(ostream&, const Boxa&);
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

