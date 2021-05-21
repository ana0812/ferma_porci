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
	friend void istoric_adaugare(string, int,string);
	friend void registru_adaugare(string nrBoxa, int greutate, string data);
	friend void stergere();
	friend void stergere_pt2(int,const int&);
	//friend void istoric_stergere(int c, string dp, string codBoxa);
	friend void registru_stergere(int c, string dp, string nrBoxa);
	friend void istoric();
	friend void statisticaBoxe();
};

