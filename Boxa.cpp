#include "Boxa.h"

Boxa::Boxa(string t, int nrP, string c)
	:tip(t), nrPorci(nrP), cod(c)
{}

void Boxa::SetLista(Animale& a)
{
	listaAnimale.push_back(a);
}

void Boxa::StergePorc(int cnp)
{
	for (int i = 0; i < listaAnimale.size(); i++) {
		if (listaAnimale.at(i).cnp == cnp)
		{
			listaAnimale.erase(listaAnimale.begin() + i);
			break;
		}	
	}
}


ostream& operator<<(ostream& os, const Boxa&b)
{
	// TODO: insert return statement here
	os << "Tip: " << b.tip<<endl;
	if (b.listaAnimale.size()) {
		for (int i = 0; i < b.listaAnimale.size(); i++) {
			os << b.listaAnimale.at(i) << endl;
		}
	}
	else {
		os << "Boxa goala" << endl;
	}
	return os;
}
