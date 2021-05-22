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

	//adaug un animal in lista de animale
	void SetLista(Animale& a);
	//sterg un animal de pe pozitia primita ca si parametru
	void StergePorc(int);

	friend ostream& operator<<(ostream&, const Boxa&);
	//pt inserare porc nou in ferma
	friend void inserare();
	friend void istoric_adaugare(string, int, string);
	friend void registru_adaugare(string nrBoxa, int greutate, string data, int cnpnou);
	
	//pt eliberare porc din ferma
	friend void gasire_boxe_stergere(const string marimeBoxa, vector<int>& nr);
	friend void stergere_pt2(int, const int&);
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

