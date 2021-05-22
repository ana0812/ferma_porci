#include "Ferma.h"

Ferma::Ferma(int nrScr, int nrPor, int nrPurc, int nrB, int n)
	:nume("Puff-Farm"), locatie("Strada Fericirii"), nrScroafe(nrScr), nrPorci(nrPor), nrPurcelusi(nrPurc), nrBoxe(nrB), nrMaxBoxePorci(n)
{}

Ferma::Ferma(const Ferma&f)
	:nume(f.nume), locatie(f.locatie), nrScroafe(f.nrScroafe), nrPorci(f.nrPorci), nrPurcelusi(f.nrPurcelusi),nrBoxe(f.nrBoxe),nrMaxBoxePorci(f.nrMaxBoxePorci)
{}

void Ferma::SetLista(Boxa & b)
{
	listaBoxe.push_back(b);
}

ostream& operator<<(ostream& st, const Ferma& f) {
	st << "Nume: " << f.nume << " Locatie: " << f.locatie << endl;
	st << "Nr Porci: " << f.nrPorci << " " << f.nrScroafe << " " << f.nrPurcelusi << endl;
	st << "Nr de boxe: " << f.nrBoxe <<" Nr max boxa: " << f.nrMaxBoxePorci << endl;
	if (f.listaBoxe.size()) {
		for (int i = 0; i < f.listaBoxe.size(); i++) {
			st << f.listaBoxe.at(i) << endl;
		}
	}
	else {
		st << "Boxa goala" << endl;
	}
	return st;
}