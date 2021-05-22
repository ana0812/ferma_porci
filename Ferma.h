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
	//functie care adauga cate o boxa in vectorul de boxe
	void SetLista(Boxa& a);

	//functii prietene pt functia de inserare
	friend void inserare();
	friend void istoric_adaugare(string, int,string);
	friend void registru_adaugare(string nrBoxa, int greutate, string data, int cnpnou);

	//functii prietene pt functia de stergere
	friend void gasire_boxe_stergere(const string marimeBoxa, vector<int>& nr);
	friend void stergere_pt2(int,const int&);
	friend void registru_stergere(int c, string dp, string nrBoxa);

	//pt istoric
	friend void istoric();
	friend void legenda_istoric(int& n);

	friend void statisticaBoxe();

	//pt desenare
	friend void functie_ale(int& kmic, int& kmediu, int& kmare);
	friend void desenare();

	//pt upgrade
	friend void upgrade();
	friend bool gasire_boxa_upgrade(const string marimeBoxa, vector<int>& nr);
};

