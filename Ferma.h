#pragma once
#include<iostream>
#include"Boxa.h";
#include<vector>
using namespace std;

class Ferma
{
	string nume;
	string locatie;
	int nrScroafe, nrPorci, nrPurcelusi;
	int nrBoxe, nrMaxBoxePorci;
	vector <Boxa> listaBoxe;
public:
	Ferma(int nrScr=0, int nrPor=0, int nrPurc=0, int nrB=0, int n=0);
	Ferma(const Ferma&);
	friend ostream& operator<<(ostream&, const Ferma&);
	void SetLista(Boxa& a);
	friend void inserare();
	friend void istoric(string, int,string);
	friend void registru_adaugare(string nrBoxa, int greutate, string data);
};

