#include<iostream>
#include"Ferma.h"
#include"Boxa.h"
#include"Animale.h"
#include<fstream>
#include<cstring>
using namespace std;

Ferma Guitz;
int ultimpcnp=0;

void istoric(string nrBoxa, int greutate, string data)
{
    ifstream isto;
    isto.open("istoric.txt");
    ofstream aux;
    aux.open("auxiliar.txt");
    string box, tip;
    int nr,i;
    int cnp, g;
    string d;
    char linie[250];

    while (!isto.eof()) {
        isto >> box >> tip >> nr;
        if (!isto.eof()) {
            if (!box.compare(nrBoxa)) {
                aux << box << " " << tip << " " << nr + 1 << endl;
                for (i = 0; i < nr; i++) {
                    isto >> cnp >> g >> d;
                    aux << cnp << " " << g << " " << d << endl;
                }
                aux << ultimpcnp << " " << greutate << " " << data << endl;
                isto.ignore();
                isto.getline(linie, 250);
                while (strcmp(linie, "*"))
                {
                    aux << linie << endl; ////!!!!!!!!!!!!!
                    isto.getline(linie, 250);
                }
                aux << "Am adaugat animalul cnp: " << ultimpcnp << " in data de " << data << endl;
                aux << "*" << endl;
            }
            else {
                aux << box << " " << tip << " " << nr << endl;
                //cout << box << " " << tip << " " << nr << endl;
                for (i = 0; i < nr; i++) {
                    isto >> cnp >> g >> d;
                    aux << cnp << " " << g << " " << d << endl;
                    //cout << cnp << " " << g << " " << d << endl;
                }
                isto.ignore();
                isto.getline(linie, 250);
                while (strcmp(linie, "*"))
                {
                    aux << linie << endl; ////!!!!!!!!!!!!!
                    //cout << linie<<endl;
                    isto.getline(linie, 250);
                }
                aux << "*" << endl;
            }
        }
    }

    isto.close();
    aux.close();
    char filename1[] = "istoric.txt";
    char filename2[] = "auxiliar.txt";
    if (remove(filename1) != 0)
        perror("File deletion failed");
    else
        cout << "File deleted successfully";

        if (rename(filename2, filename1) != 0)
            perror("Error renaming file");
        else
            cout << "File renamed successfully";
}

void registru_adaugare(string nrBoxa, int greutate, string data)
{
    ifstream reg;
    reg.open("registru.txt");
    ofstream aux;
    aux.open("auxiliar.txt");
    string box, tip;
    int nr, i;
    int cnp, g;
    string d;
    char linie[250];
    int a, b, c, z, e, f;
    reg >> a >> b >> c >> z >> e;
    aux << a << " " << Guitz.nrScroafe << " " << Guitz.nrPorci << " " << Guitz.nrPurcelusi <<" "<<e<< endl;

    while (!reg.eof()) {
        reg >> box >> tip >> nr;
        if (!reg.eof()) {
            if (!box.compare(nrBoxa)) {
                aux << box << " " << tip << " " << nr + 1 << endl;
                for (i = 0; i < nr; i++) {
                    reg >> cnp >> g >> d;
                    aux << cnp << " " << g << " " << d << endl;
                }
                aux << ultimpcnp << " " << greutate << " " << data << endl;
            }
            else {
                aux << box << " " << tip << " " << nr << endl;
                for (i = 0; i < nr; i++) {
                    reg >> cnp >> g >> d;
                    aux << cnp << " " << g << " " << d << endl;
                }
            }
        }
    }
    reg.close();
    aux.close();
    char filename1[] = "registru.txt";
    char filename2[] = "auxiliar.txt";
    if (remove(filename1) != 0)
        perror("File deletion failed");
    else
        cout << "File deleted successfully";

    if (rename(filename2, filename1) != 0)
        perror("Error renaming file");
    else
        cout << "File renamed successfully";
}

void inserare() {
    int alegere,i,ok=0;
    cout << "Ce tip de porc doriti sa adaugati?" << endl;
    cout << "1. Pucelusi\n2. Scroafa\n3. Porc" << endl;
    cout << "Alegerea dvs este: "; cin >> alegere;
    vector<int> nr;
    float greutate;
    string data;

    if (alegere == 1) {
        for (i = 0; i < Guitz.listaBoxe.size(); i++)
        {
            if (!Guitz.listaBoxe.at(i).tip.compare("mic"))
            {
                if (Guitz.listaBoxe.at(i).nrPorci < Guitz.nrMaxBoxePorci)
                {
                    cout << Guitz.listaBoxe.at(i).cod << endl;
                    ok = 1;
                    nr.push_back(i);
                }
            }
        }
        if (!ok) {
            cout << "Ne cerem scuze, toate boxele sunt ocupate!";
            return;
        }
        ok = 0;
        cout << "Ce boxa alegeti? Puneti doar numarul boxei.";
        while (!ok)
        {
            cin >> alegere;
            for (i = 0; i < nr.size(); i++) {
                if (alegere == (nr.at(i)+1))
                    ok = 1;
            }
            if (ok == 0)
            {
                cout << "Ati ales un numar gresit. Doriti sa incercati din nou?";
                int optiune;
                cout << "\nAlegeti 0 pt nu, 1 pt da: ";
                cin >> optiune;
                if (optiune == 0) {
                    return;
                }
                cout << "Ce boxa alegeti? Puneti doar numarul boxei.";
            }
        }
        cout << "Introduceti datele animalului: " << endl;
        cout << "Greutate: "; cin >> greutate;
        cout << " Data de astazi: zi/luna/an "; cin >> data;
        ultimpcnp++;
        Animale a("mic",ultimpcnp, greutate, data);
        /*cout << a;*/
        Guitz.listaBoxe.at(alegere-1).SetLista(a);
        Guitz.listaBoxe.at(alegere-1).nrPorci++;
        Guitz.nrPurcelusi++;
    }
    else if (alegere == 2) {
        for (i = 0; i < Guitz.listaBoxe.size(); i++)
        {
            if (!Guitz.listaBoxe.at(i).tip.compare("mediu"))
            {
                if (Guitz.listaBoxe.at(i).nrPorci < Guitz.nrMaxBoxePorci)
                {
                    cout << Guitz.listaBoxe.at(i).cod << endl;
                    ok = 1;
                    nr.push_back(i);
                }
            }
        }
        if (!ok) {
            cout << "Ne cerem scuze, toate boxele sunt ocupate!";
            return;
        }
        ok = 0;
        cout << "Ce boxa alegeti? Puneti doar numarul boxei.";
        while (!ok)
        {
            cin >> alegere;
            for (i = 0; i < nr.size(); i++) {
                if (alegere == (nr.at(i) + 1))
                    ok = 1;
            }
            if (ok == 0)
            {
                cout << "Ati ales un numar gresit. Doriti sa incercati din nou?";
                int optiune;
                cout << "\nAlegeti 0 pt nu, 1 pt da: ";
                cin >> optiune;
                if (optiune == 0) {
                    return;
                }
                cout << "Ce boxa alegeti? Puneti doar numarul boxei.";
            }
        }
        cout << "Introduceti datele animalului: " << endl;
        cout << "Greutate: "; cin >> greutate;
        cout << " Data de astazi: zi/luna/an "; cin >> data;
        ultimpcnp++;
        Animale a("mediu", ultimpcnp, greutate, data);
        /*cout << a;*/
        Guitz.listaBoxe.at(alegere - 1).SetLista(a);
        Guitz.listaBoxe.at(alegere - 1).nrPorci++;
        Guitz.nrScroafe++;
    }
    else if (alegere == 3)
    {
    for (i = 0; i < Guitz.listaBoxe.size(); i++)
    {
        if (!Guitz.listaBoxe.at(i).tip.compare("mare"))
        {
            if (Guitz.listaBoxe.at(i).nrPorci < Guitz.nrMaxBoxePorci)
            {
                cout << Guitz.listaBoxe.at(i).cod << endl;
                ok = 1;
                nr.push_back(i);
            }
        }
    }
    if (!ok) {
        cout << "Ne cerem scuze, toate boxele sunt ocupate!";
        return;
    }
    ok = 0;
    cout << "Ce boxa alegeti? Puneti doar numarul boxei.";
    while (!ok)
    {
        cin >> alegere;
        for (i = 0; i < nr.size(); i++) {
            if (alegere == (nr.at(i) + 1))
                ok = 1;
        }
        if (ok == 0)
        {
            cout << "Ati ales un numar gresit. Doriti sa incercati din nou?";
            int optiune;
            cout << "\nAlegeti 0 pt nu, 1 pt da: ";
            cin >> optiune;
            if (optiune == 0) {
                return;
            }
            cout << "Ce boxa alegeti? Puneti doar numarul boxei.";
        }
    }
    cout << "Introduceti datele animalului: " << endl;
    cout << "Greutate: "; cin >> greutate;
    cout << " Data de astazi: zi/luna/an "; cin >> data;
    ultimpcnp++;
    Animale a("mare", ultimpcnp, greutate, data);
    /*cout << a;*/
    Guitz.listaBoxe.at(alegere - 1).SetLista(a);
    Guitz.listaBoxe.at(alegere - 1).nrPorci++;
    Guitz.nrPorci++;
}
    else {
    cout << "Nu ati ales o optiune valida. Reveniti in functie";
    return;
    }

    istoric(Guitz.listaBoxe.at(alegere-1).cod,greutate,data);
    registru_adaugare(Guitz.listaBoxe.at(alegere - 1).cod, greutate, data);
}

int main()
{
    ifstream inFile;
    inFile.open("registru.txt");
    int Boxe, NrScroafe, NrPorci, NrPorcusori,n;
    string CodBoxa, TipPorc;
    int NrPerBoxa;
    int cnp;
    float kg;
    string dv;
    int sw = 0;
    inFile >> Boxe >> NrScroafe >> NrPorci >> NrPorcusori >> n;
    Ferma aux(NrScroafe,NrPorci,NrPorcusori, Boxe,n);
    Guitz = aux;
    /*cout << Guitz;*/
   /* cout << Boxe << " " << n;*/
    while (!inFile.eof())
    {
        inFile >> CodBoxa >> TipPorc >> NrPerBoxa;
        Boxa b(TipPorc, NrPerBoxa, CodBoxa);
        for (int i = 0; i < NrPerBoxa; i++) {
            inFile >> cnp >> kg >> dv;
            Animale a(TipPorc, cnp, kg, dv);
            b.SetLista(a);
            if (cnp > ultimpcnp)
                ultimpcnp = cnp;
        }
        Guitz.SetLista(b);
    }
    inFile.close();

    //cout << Guitz;
    inserare();
    //cout << Guitz;

	return 0;
}
