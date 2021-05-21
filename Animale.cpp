#include "Animale.h"

Animale::Animale(string t, int c, float g, string dv)
	: cnp(c), greutate(g), dataVenirii(dv), dataEliberarii("NULL")
{
	if (!t.compare("mic")) {
		tip = "porcusor";
	}
	else if (!t.compare("mediu")) {
		tip = "scroafa";
	}
	else if (!t.compare("mare")) {
		tip = "porc";
	}
}

ostream& operator<<(ostream& os, const Animale&a)
{
	os << "Animal: " << a.tip << " CNP: " << a.cnp << endl;
	return os;
}
