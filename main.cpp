#include<iostream>
#include"Ferma.h"
#include"Boxa.h"
#include"Animale.h"
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<map>
using namespace std;

Ferma Guitz;
int ultimpcnp=0;

//ADAUGARE
void istoric_adaugare(string nrBoxa, int greutate, string data)
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

void registru_adaugare(string nrBoxa, int greutate, string data,int cnpnou)
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
                aux << cnpnou << " " << greutate << " " << data << endl;
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
    system("cls");
    int alegere,i,ok=0;
    cout << "\t\t\t\t\t\tCe tip de porc doriti sa adaugati?" << endl;
    cout << "\t\t\t\t\t\t1. Purcelusi\n\t\t\t\t\t\t2. Scroafa\n\t\t\t\t\t\t3. Porc\n\n\t\t\t\t\t\t0. Iesire" << endl;
    cout << "Alegerea dvs este: "; cin >> alegere;
    vector<int> nr;
    float greutate;
    string data;
    if (alegere == 0) return;

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

    istoric_adaugare(Guitz.listaBoxe.at(alegere-1).cod,greutate,data);
    registru_adaugare(Guitz.listaBoxe.at(alegere - 1).cod, greutate, data,ultimpcnp);
}

//STERGERE
void istoric_stergere(int c, string dp, string nrBoxa)
{
    ifstream isto;
    isto.open("istoric.txt");
    ofstream aux;
    aux.open("auxiliar.txt");
    string box, tip;
    int nr, i;
    int cnp, g;
    string d,datavenirii;
    char linie[250];

    while (!isto.eof()) {
        isto >> box >> tip >> nr;
        if (!isto.eof()) {
            if (!box.compare(nrBoxa)) {
                aux << box << " " << tip << " " << nr - 1 << endl;
                for (i = 0; i < nr; i++) {
                    isto >> cnp >> g >> d;
                    if (cnp != c)
                        aux << cnp << " " << g << " " << d << endl;
                    else
                        datavenirii = d;
                }
                isto.ignore();
                isto.getline(linie, 250);
                while (strcmp(linie, "*"))
                {
                    aux << linie << endl; ////!!!!!!!!!!!!!
                    isto.getline(linie, 250);
                }
                aux << "Am eliberat animalul cnp: " << c << " in data de " << dp <<" Data venirii: "<<datavenirii<< endl;
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

void registru_stergere(int c, string dp, string nrBoxa) {
    ifstream reg;
    reg.open("registru.txt");
    ofstream aux;
    aux.open("auxiliar.txt");
    string box, tip;
    int nr, i;
    int cnp, g;
    string d;
    char linie[250];
    int a, b, x, z, e, f;
    reg >> a >> b >> x >> z >> e;
    aux << a << " " << Guitz.nrScroafe << " " << Guitz.nrPorci << " " << Guitz.nrPurcelusi << " " << e << endl;

    while (!reg.eof()) {
        reg >> box >> tip >> nr;
        if (!reg.eof()) {
            if (!box.compare(nrBoxa)) {
                aux << box << " " << tip << " " << nr - 1 << endl;
                for (i = 0; i < nr; i++) {
                    reg >> cnp >> g >> d;
                    if(cnp!=c)
                        aux << cnp << " " << g << " " << d << endl;
                }
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

//alegere = nrboxei din care vr sa sterg
//tipul de porc - ca sa stiu sa modific la atributul potrivit din ferma
void stergere_pt2(int alegere, const int&tipporc) {
    cout << "Alegeti cnp-ul porcului: "<<endl;
    vector<int>coduri;
    int i,c,ok=0;

    //pastram in vectorul coduri cnp urile porcurilor pt a valida daca introduce un cnp corect
    for (i = 0; i < Guitz.listaBoxe.at(alegere).listaAnimale.size(); i++) {
        c = Guitz.listaBoxe.at(alegere).listaAnimale.at(i).cnp;
        coduri.push_back(c);
        cout << c << " ";
    }
    
    //alege cnp ul
    while (!ok)
    {
        cout << "Alegerea dvs este: ";
        cin >> c;
        for (i = 0; i < coduri.size(); i++) {
            if (c == coduri.at(i))
                ok = 1;
        }
        if (ok == 0)
        {
            cout << "Ati ales un cnp gresit. Doriti sa incercati din nou?";
            int optiune;
            cout << "\nAlegeti 0 pt nu, 1 pt da: ";
            cin >> optiune;
            if (optiune == 0) {
                return;
            }
            cout << "Alegeti cnp-ul porcului: ";
        }
    }
    string dp;
    cout << "Introduceti data de azi: zi/luna/an ";
    cin >> dp;

    Guitz.listaBoxe.at(alegere).nrPorci--;
    Guitz.listaBoxe.at(alegere).StergePorc(c);
    if (tipporc == 1)
        Guitz.nrPurcelusi--;
    else if (tipporc == 2)
        Guitz.nrScroafe--;
    else
        Guitz.nrPorci--;

    istoric_stergere(c,dp,Guitz.listaBoxe.at(alegere).cod);
    registru_stergere(c, dp, Guitz.listaBoxe.at(alegere).cod);

}

bool alegere_boxa(const vector<int>&nr, int&boxaaleasa){
    int i,ok = 0;
    cout << "\t\t\t\tCe boxa alegeti? Puneti doar numarul boxei.";
    while (!ok)
    {
        cin >> boxaaleasa;
        for (i = 0; i < nr.size(); i++) {
            //verific ca inputul sa fie corect
            if (boxaaleasa == (nr.at(i) + 1))
                ok = 1;
        }
        if (ok == 0)
        {
            cout << "Ati ales un numar gresit. Doriti sa incercati din nou?";
            int optiune;
            cout << "\nAlegeti 0 pt nu, 1 pt da: ";
            cin >> optiune;
            if (optiune == 0) {
                return false;
            }
            cout << "Ce boxa alegeti? Puneti doar numarul boxei.";
        }
    }
}

void gasire_boxe_stergere(const string marimeBoxa, vector<int>& nr) {
    int i,ok = 0;
    for (i = 0; i < Guitz.listaBoxe.size(); i++)
    {
        if (!Guitz.listaBoxe.at(i).tip.compare(marimeBoxa))
        {
            if (Guitz.listaBoxe.at(i).nrPorci > 0)
            {
                cout << "\t\t\t\t"<<Guitz.listaBoxe.at(i).cod << endl;
                ok = 1;
                nr.push_back(i);
            }
        }
    }
    if (!ok) {
        cout << "Ne cerem scuze, nu mai exista porcusori in ferma!";
        return;
    }
}

void stergere() {
    system("cls");
    int alegere, i, ok = 0;
    cout << "\t\t\t\t\t\tCe tip de porc doriti sa stergeti?" << endl;
    cout << "\t\t\t\t\t\t1. Purcelusi\n\t\t\t\t\t\t2. Scroafa\n\t\t\t\t\t\t3. Porc\n\n\t\t\t\t\t\t0. Iesire" << endl;
    cout << "\t\t\t\t\t\tAlegerea dvs este: "; cin >> alegere;
    vector<int> nr;

    if (alegere == 0) return;
    //verificam pt tipul de porc ales daca se poate sterge vreunul
    //daca se pot sterge pastram in vectorul nr boxele respective
    //afisam boxele din care se pot sterge porci
    if (alegere == 1) {
        gasire_boxe_stergere("mic", nr);
    }
    else if (alegere == 2) {
        gasire_boxe_stergere("mediu",nr);
    }
    else if (alegere == 3) {
        gasire_boxe_stergere("mare", nr);
    }
    else {
        cout << "Nu ati ales o optiune valida. Reveniti in functie";
        return;
    }

    //utilizatorul alege numarul boxei din care vrea sa elibereze porci
    int boxaaleasa = 0;
    //transmit ca parametru vectorul de indexi si variabila in care stochez inputul de la tastaura(prin referinta)
    if (!alegere_boxa(nr, boxaaleasa)) {
        return;
    }
    //cout << boxaaleasa;

    //aici va trebui sa aleaga porcul pe care vrea sa il elibereze
    //parametrii: boxa din care vr sa sterg si tipul de boxa din care vr sa sterg
    stergere_pt2(boxaaleasa-1, alegere);
}

//pot adauga si in stergere_pt2 - pt upgrade facuta special
bool alegere_cnp(const vector<int>&coduri, int&c){
    int i,ok = 0;
    while (!ok)
    {
        cout << "Alegerea dvs este: ";
        cin >> c;
        for (i = 0; i < coduri.size(); i++) {
            if (c == coduri.at(i))
                ok = 1;
        }
        if (ok == 0)
        {
            cout << "Ati ales un cnp gresit. Doriti sa incercati din nou?";
            int optiune;
            cout << "\nAlegeti 0 pt nu, 1 pt da: ";
            cin >> optiune;
            if (optiune == 0) {
                return false;
            }
            cout << "Alegeti cnp-ul porcului: ";
        }
    }
    return true;
}


bool gasire_boxa_upgrade(const string marimeBoxa, vector<int>& nr)
{
    int i, ok = 0;
    for (i = 0; i < Guitz.listaBoxe.size(); i++)
    {
        if (!Guitz.listaBoxe.at(i).tip.compare(marimeBoxa))
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
        return false;
    }
    return true;
}

void istoric_update(string nrBoxa, int greutate, string data,int c,string BoxaVeche) {
    ifstream isto;
    isto.open("istoric.txt");
    ofstream aux;
    aux.open("auxiliar.txt");
    string box, tip;
    int nr, i;
    int cnp, g;
    string d,datavenirii;
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
                aux << c << " " << greutate << " " << data << endl;
                isto.ignore();
                isto.getline(linie, 250);
                while (strcmp(linie, "*"))
                {
                    aux << linie << endl; ////!!!!!!!!!!!!!
                    isto.getline(linie, 250);
                }
                aux << "Am mutat animalul cnp: " << c << " in data de " << data << endl;
                aux << "*" << endl;
            }
            else if (!box.compare(BoxaVeche)) {
                aux << box << " " << tip << " " << nr - 1 << endl;
                for (i = 0; i < nr; i++) {
                    isto >> cnp >> g >> d;
                    if (cnp != c)
                        aux << cnp << " " << g << " " << d << endl;
                    else
                        datavenirii = d;
                }
                
                isto.ignore();
                isto.getline(linie, 250);
                while (strcmp(linie, "*"))
                {
                    aux << linie << endl; ////!!!!!!!!!!!!!
                    isto.getline(linie, 250);
                }
                aux << "Animalul cnp: " << c << " a crescut in data de " << data <<", data venirii: "<<datavenirii<< endl;
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

void upgrade() {
    system("cls");
    cout << "Alegeti cnp-ul porcului: " << endl;
    vector<int>coduri;
    int i,j, c, ok = 0;
    //in c ramane cnp ul porcului caruia vr sa i dau upgrade

    map<int, int> harta;
    //pastram in vectorul coduri cnp urile porcurilor pt a valida daca introduce un cnp corect
    for (i = 0; i < Guitz.listaBoxe.size(); i++) {
        if (!Guitz.listaBoxe.at(i).tip.compare("mic"))
        {
            for (j = 0; j < Guitz.listaBoxe.at(i).listaAnimale.size(); j++) {
                c = Guitz.listaBoxe.at(i).listaAnimale.at(j).cnp;
                coduri.push_back(c);
                cout << c << " ";
                harta.insert(pair<int, int>(c, i));
            }
            cout << endl;
        }
    }
    if (!alegere_cnp(coduri, c))
        return;

    int maturitate;
    cout << "Alegeti ce devine porcusorul: \n1. Porc\n2. Scroafa\nAlegerea dvs este: ";
    cin >> maturitate;

    //afisez boxele in care poate fi introdus un porc nou
    vector <int>nr;
    if (maturitate == 1)
    {
        if (!gasire_boxa_upgrade("mare", nr))
            return;
    }
    else if (maturitate == 2) {
        if (!gasire_boxa_upgrade("mediu", nr))
            return;
    }
    else {
        cout << "Nu ati ales o optiune valida. Reveniti in functie";
        return;
    }

    int boxaaleasa = 0;
    //transmit ca parametru vectorul de indexi si variabila in care stochez inputul de la tastaura(prin referinta)
    if (!alegere_boxa(nr, boxaaleasa)) {
        return;
    }

    //trebuie sa folosesc atributele de la animalul cu cnp ul ales
    //ori salvez cumva boxa animalelor, ori fac alta functie de cautare a boxei in functie de cnp
    float gr;
    string mat,dp;
    if (maturitate == 1)
        mat = "mare";
    else
        mat = "mediu";
    

    cout << "Introduceti noua greutate: "; cin >> gr;
    cout << "\nIntroduceti data de astazi: zi/luna/an "; cin >> dp;

    Animale a(mat, c, gr, dp);
    
    Guitz.listaBoxe.at(boxaaleasa - 1).SetLista(a);

    for (i = 0; i < Guitz.listaBoxe.at(harta[c]).listaAnimale.size(); i++)
    {
        if (Guitz.listaBoxe.at(harta[c]).listaAnimale.at(i).cnp == c) {
        
            Guitz.listaBoxe.at(harta[c]).StergePorc(c);
            break;
        }
    }

    if (maturitate == 1) {
        Guitz.nrPorci++;
    }
    else
        Guitz.nrScroafe++;

    Guitz.nrPurcelusi--;
    Guitz.listaBoxe.at(boxaaleasa - 1).nrPorci++;
    Guitz.listaBoxe.at(harta[c]).nrPorci--;

    registru_adaugare(Guitz.listaBoxe.at(boxaaleasa-1).cod, gr, dp,c);
    registru_stergere(c, dp, Guitz.listaBoxe.at(harta[c]).cod);
    istoric_update(Guitz.listaBoxe.at(boxaaleasa - 1).cod, gr, dp, c, Guitz.listaBoxe.at(harta[c]).cod);

}

void legenda_istoric(int& n) {
    int i;
    system("cls");
    cout << "\t\t\t\t\t\tBine ati venit, aici puteti vizualiza istoricul boxelor " << endl;
    cout << "\t\t\t\t\t\tIstoricul carei boxe doriti sa il vedeti?" << endl;
    for (i = 0; i < Guitz.nrBoxe; i++)
    {
        cout << "\t\t\t\t\t\t\t" << Guitz.listaBoxe.at(i).cod << endl;
    }
    cout << "\t\t\t\t\t\t0  - Iesire" << endl;
    cout << endl;
    cout << "\t\t\t\tOptiunea dumneavoastra: ";
    cin >> n;
}


void istoric()
{
    int n, r, i;
    legenda_istoric(n);
    while (n != 0)
    {
        
        if (n > Guitz.nrBoxe ) cout << "\n   Nu ati introdus o optiune valida";
        //else if (n == 0) return;
        else {

            ifstream isto;
            isto.open("istoric.txt");
            string box, tip, data;
            int nr, cnp;
            float g;
            char linie[250];

            while (!isto.eof()) {
                isto >> box >> tip >> nr;
                if (!box.compare(Guitz.listaBoxe.at(n-1).cod)) {
                    cout << "\n\t\t"<<box << " Tip: " << tip << " Nr animale: " << nr << endl<<endl;
                    for (i = 0; i < nr; i++) {
                        isto >> cnp >> g >> data;
                        cout <<"\t\tCNP: "<< cnp << " Greutate: " << g << "kg Data venirii: " << data << endl;
                    }
                    isto.ignore();
                    isto.getline(linie, 250);
                    while (strcmp(linie, "*"))
                    {
                        cout <<"\t\t"<<linie << endl; 
                        isto.getline(linie, 250);
                    }
                    //cout << "Am adaugat animalul cnp: " << ultimpcnp << " in data de " << data << endl;
                    cout << endl;
                    break;
                }
                else {
                    for (i = 0; i < nr; i++) {
                        isto >> cnp >> g >> data;
                    }
                    isto.ignore();
                    isto.getline(linie, 250);
                    while (strcmp(linie, "*"))
                    {
                        isto.getline(linie, 250);
                    }
                }
            }
            isto.close();

        }

        cout << endl << "   Doriti sa continuati programul si sa alegeti iar DIN LISTA BOXE?\n";
        cout << "     0 - NU\n";
        cout << "     1 - DA\n";
        cout << " Raspunsul dumneavoastra: ";
        cin >> r;
        if (r == 0) n = 0;
        else
        {
            legenda_istoric(n);
        }
    }
}

//STATISTICA
void afisare_meniu_stat(int& n) {

    cout << "\t\t\t\tStatistica carei tip de boxe doriti sa o vedeti?" << endl;

    cout << "\t\t\t\t1  - Mica  -> Purcelusi" << endl;
    cout << "\t\t\t\t2  - Medie -> Scroafe" << endl;
    cout << "\t\t\t\t3  - Mare  -> Porci" << endl;
    cout << "\t\t\t\t0  - Iesire" << endl;
    cout << endl;
    cout << "\t\tOptiunea dumneavoastra: ";
    cin >> n;
}

void statisticaBoxe()
{
    system("cls");
    int totalporci,r, i, k = 0,n=0;
    vector <int> box;

    cout << "\t\tBine ati venit, aici puteti vizualiza statistici despre boxe " << endl<<endl;
    afisare_meniu_stat(n);
    
    while (n != 0)
    {
        system("cls");
        if (n == 0) return;
        else if (n > 3) cout << "\n   Nu ati introdus o optiune valida";
        else
        {
            cout << "\t\t\t\t\tSTATISTICA" << endl << endl;

            cout << "\t\t\t\tTipul boxei: ";
            if (n == 1) cout << "Mica" << endl;
            else if (n == 2) cout << "Medie" << endl;
            else if (n == 3) cout << "Mare" << endl;

            cout << "\t\t\t\tTipul animalelor: ";
            if (n == 1) cout << "Purcelusi" << endl;
            else if (n == 2) cout << "Scroafe" << endl;
            else if (n == 3) cout << "Porci" << endl;

            cout << "\t\t\t\tNumarul total animalelor: ";
            //il am salvat in clasa ferma, il salvez doar in totalporci
            if (n == 1) {
                
                totalporci = Guitz.nrPurcelusi;
                cout << totalporci << endl;
            }
            else if (n == 2) {
                totalporci = Guitz.nrScroafe;
                cout << totalporci << endl;
            }
            else if (n == 3) {
                totalporci = Guitz.nrPorci;
                cout << totalporci << endl;
            }

            cout << "\t\t\t\tNumarul maxim de animale/boxa: " << Guitz.nrMaxBoxePorci << endl;
            cout << "\t\t\t\tNumarul boxelor: ";

            //parcurg lista de boxe si cresc contorul cand gasesc o boxa de tipul dorit
            //in vectorul box retin pozitiile boxelor cu tipul dorit
            k = 0;
            if (n == 1) {
                for (i = 0; i < Guitz.nrBoxe; i++)
                {
                    if (!(Guitz.listaBoxe.at(i).tip).compare("mic")) {
                        k++;
                        box.push_back(i);
                    }
                }
            }
            else if (n == 2) {
                for (i = 0; i < Guitz.nrBoxe; i++)
                {
                    if (!(Guitz.listaBoxe.at(i).tip).compare("mediu")) {
                        k++;
                        box.push_back(i);
                    }
                }
            }
            else if (n == 3) {
                for (i = 0; i < Guitz.nrBoxe; i++)
                {
                    if (!(Guitz.listaBoxe.at(i).tip).compare("mare")) {
                        k++;
                        box.push_back(i);
                    }
                }
            }

            cout << k << endl;
            float gr,gmin=500, gmax=0, medie = 0;
            if (k == 0) {
                cout << "Nu exista boxe de acest tip";
            }
            else {
                cout << "\t\t\t\tNumarul de animale din fiecare boxa: " << endl;

                //parcurg tipul de boxe care ma intereseaza - fac asta accesand boxele cu pozitiile ddin vectorul box
                for (i = 0; i < box.size(); i++) {
                    cout <<"\t\t\t\t\t"<< Guitz.listaBoxe.at(box.at(i)).cod << " " << Guitz.listaBoxe.at(box.at(i)).nrPorci << " animale" << endl;
                    //parcurg animalele din fiecare boxa si retin informatiile care ma intereseaza
                    for (int j = 0; j < Guitz.listaBoxe.at(box.at(i)).listaAnimale.size(); j++) {
                        gr = Guitz.listaBoxe.at(box.at(i)).listaAnimale.at(j).greutate;
                        if (gr > gmax) {
                            gmax = gr;
                        }
                        if(gr<gmin){
                            gmin = gr;
                        }
                        medie += gr;
                    }
               }
                cout << "\t\t\t\tGreutatea minima din acest tip de boxa: " << gmin << endl;
                cout << "\t\t\t\tGreutatea maxima din acest tip de boxa: " << gmax << endl;
                medie /= totalporci;
                cout << "\t\t\t\tMedia greutatilor din acest tip de boxa: " << medie << endl<<endl;
                box.clear();
            }

        }

        cout << endl << "\t\tDoriti sa continuati programul si sa alegeti iar DIN LISTA BOXE?\n";
        cout << "\t\t0 - NU\n";
        cout << "\t\t1 - DA\n";
        cout << "\t\tRaspunsul dumneavoastra: ";
        cin >> r;
        if (r == 0) n = 0;
        else
        {
            system("cls");
            afisare_meniu_stat(n);
        }
    }
}

//PT DESENAT
void functie_ale(int&kmic, int&kmediu, int&kmare) {
    kmic = 0; kmediu = 0; kmare = 0;
    for (int i = 0; i < Guitz.nrBoxe; i++)
    {
        if (!(Guitz.listaBoxe.at(i).tip).compare("mic")) 
            kmic++;
        else if (!(Guitz.listaBoxe.at(i).tip).compare("mediu"))
            kmediu++;
        else if (!(Guitz.listaBoxe.at(i).tip).compare("mare"))
            kmare++;
    }
}

//INIT
void initializareFerma() 
{
    ifstream inFile;
    inFile.open("registru.txt");
    int Boxe, NrScroafe, NrPorci, NrPorcusori, n;
    string CodBoxa, TipPorc;
    int NrPerBoxa;
    int cnp;
    float kg;
    string dv;
    int sw = 0;
    inFile >> Boxe >> NrScroafe >> NrPorci >> NrPorcusori >> n;
    Ferma aux(NrScroafe, NrPorci, NrPorcusori, Boxe, n);
    Guitz = aux;
    while (!inFile.eof())
    {
        inFile >> CodBoxa >> TipPorc >> NrPerBoxa;
        if (!inFile.eof()) {

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
    }
    inFile.close();
}

//PT DESENAT
void lungimeMic(int r1)
{
    int i;
    for (i = 0; i < r1; i++)
        cout << "~";
}
void lungimeMediu(int r2)
{
    int i;
    for (i = 0; i < r2; i++)
        cout << "~";
}
void lungimeMare(int r3)
{
    int i;
    for (i = 0; i < r3; i++)
        cout << "~";
}
void sus(int r1a, int r1b, int r1c, int La, int Lb, int Lc)
{
    int i, j;
    cout << endl;
    cout << "   ";//cele 3 sparii de la inceput
    for (j = 0; j < r1a; j++)
    {
        cout << "|";//prima linie din desen
        for (i = 0; i < La; i++) cout << " ";
        cout << "|";
        cout << " ";
    }
    for (j = 0; j < r1b; j++)
    {
        cout << "|";//prima linie din desen
        for (i = 0; i < Lb; i++) cout << " ";
        cout << "|";
        cout << " ";
    }
    for (j = 0; j < r1c; j++)
    {
        cout << "|";//prima linie din desen
        for (i = 0; i < Lc; i++) cout << " ";
        cout << "|";
        cout << " ";
    }
}
void sussus(int r1a, int La, int r1b, int Lb, int r1c, int Lc)
{
    int i;
    cout << "    ";//3 spatii intre margine si de unde incepe hala
    for (i = 0; i < r1a; i++)
    {
        lungimeMic(La);
        cout << "   ";// 3 saptii intre boxe
    }
    //pana acum avem 3   +16+3+16+3=38
    for (i = 0; i < r1b; i++)
    {
        lungimeMediu(Lb);
        cout << "   ";// 3 saptii intre boxe
    }
    // 38+ 24+3=65
    for (i = 0; i < r1c; i++)
    {
        lungimeMare(Lc);
        cout << "   ";// 3 saptii intre boxe
    }
    //65+  32+3+32+3=135 //da bine
}
void desenare() {
    system("cls");
    int i, j;
    int h = 5, La = 16, Lb = 24, Lc = 32;
    int r1, r2, r3;
    functie_ale(r1,r2,r3);
    int r1a = r1 / 2; //2
    int r1b = r2 / 2; //1
    int r1c = Guitz.nrBoxe / 2 - (r1a + r1b); //5-3=2
    int lungime = r1a * La + r1b * Lb + r1c * Lc + (r1a + r1b + r1c) * 3;
    for (i = 0; i < lungime / 2; i++) cout << " ";
    cout << "Schita halei noastre" << endl<<endl<<endl<<endl;
    sussus(r1a, La, r1b, Lb, r1c, Lc);
    ///
    /// A doua linie
    ///
    for (i = 0; i < h / 2; i++)
        sus(r1a, r1b, r1c, La, Lb, Lc);
    cout << endl;//linia 2
    cout << "   ";//cele 3 sparii de la inceput
    for (j = 0; j < r1a; j++)
    {
        int NR = Guitz.listaBoxe.at(j).nrPorci;
        cout << "|";//prima linie din desen
        for (i = 0; i < La / 2 - 1; i++) cout << " ";
        if (NR >= 10) cout << NR; //////////////////////////////////////////////ATENTIE
        else cout << "0" << NR;
        for (i = 0; i < La / 2 - 1; i++) cout << " ";
        cout << "|";
        cout << " ";
    }
    for (j = 0; j < r1b; j++)
    {
        int NR2= Guitz.listaBoxe.at(r1+j).nrPorci;
        cout << "|";//prima linie din desen
        for (i = 0; i < Lb / 2 - 1; i++) cout << " ";
        if (NR2 >= 10) cout << NR2; //////////////////////////////////////////////ATENTIE
        else cout << "0" << NR2;
        for (i = 0; i < Lb / 2 - 1; i++) cout << " ";
        cout << "|";
        cout << " ";
    }
    for (j = 0; j < r1c; j++)
    {
        int NR3= Guitz.listaBoxe.at(r1+r2+j).nrPorci;
        cout << "|";//prima linie din desen
        for (i = 0; i < Lc / 2 - 1; i++) cout << " ";
        if (NR3 >= 10) cout << NR3; //////////////////////////////////////////////ATENTIE
        else cout << "0" << NR3;
        for (i = 0; i < Lc / 2 - 1; i++) cout << " ";
        cout << "|";
        cout << " ";
    }
    //cout<<endl;
    for (i = 0; i < h / 2; i++)
    {
        sus(r1a, r1b, r1c, La, Lb, Lc);
        //cout<<endl;
    }
    //
    // ultima linie
    //
    cout << endl;
    sussus(r1a, La, r1b, Lb, r1c, Lc);
    /////////
    /////////////// cararea
    /////////
    cout << endl << endl << endl;
    cout << "   ";
    for (i = 0; i < lungime; i++) cout << "_";
    cout << "   ";
    cout << endl;
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < lungime + 3; i++)
            if (i < 3)cout << " ";
            else cout << ".";
        cout << endl;
    }
    cout << "   ";
    for (i = 0; i < lungime; i++) cout << "_";
    cout << endl << endl << endl;
    /////////
    /////////////// gata
    /////////
    r1a = r1 - r1a;
    r1b = r2 - r1b;
    r1c = r2 - r1c;
    //cout<<r1a<<" "<<r1b<<" "<<r1c;
    sussus(r1a, La, r1b, Lb, r1c, Lc);
    lungime = r1a * La + r1b * Lb + r1c * Lc + (r1a + r1b + r1c) * 3;
    ///
    /// A doua linie
    ///
    for (i = 0; i < h / 2; i++)
    {
        sus(r1a, r1b, r1c, La, Lb, Lc);
        //cout<<endl;
    }
    cout << endl;//linia 2
    cout << "   ";//cele 3 sparii de la inceput
    for (j = 0; j < r1a; j++)
    {
        int NR= Guitz.listaBoxe.at(j+r1a).nrPorci;
        cout << "|";//prima linie din desen
        for (i = 0; i < La / 2 - 1; i++) cout << " ";
        if (NR >= 10) cout << NR; //////////////////////////////////////////////ATENTIE
        else cout << "0" << NR;
        for (i = 0; i < La / 2 - 1; i++) cout << " ";
        cout << "|";
        cout << " ";
    }
    for (j = 0; j < r1b; j++)
    {
        int NR2 = Guitz.listaBoxe.at(j +r1+r1a-1).nrPorci;
        cout << "|";//prima linie din desen
        for (i = 0; i < Lb / 2 - 1; i++) cout << " ";
        if (NR2 >= 10) cout << NR2; //////////////////////////////////////////////ATENTIE
        else cout << "0" << NR2;
        for (i = 0; i < Lb / 2 - 1; i++) cout << " ";
        cout << "|";
        cout << " ";
    }
    for (j = 0; j < r1c; j++)
    {
        int NR3 = Guitz.listaBoxe.at(j + r1+r2+r1a).nrPorci;
        cout << "|";//prima linie din desen
        for (i = 0; i < Lc / 2 - 1; i++) cout << " ";
        if (NR3 >= 10) cout << NR3; //////////////////////////////////////////////ATENTIE
        else cout << "0" << NR3;
        for (i = 0; i < Lc / 2 - 1; i++) cout << " ";
        cout << "|";
        cout << " ";
    }
    for (i = 0; i < h / 2; i++)
    {
        sus(r1a, r1b, r1c, La, Lb, Lc);

    }
    //
    // ultima linie
    //
    cout << endl;
    sussus(r1a, La, r1b, Lb, r1c, Lc);
    cout << endl << endl;
    cout << endl << endl;

    cout << Guitz;

    system("pause");
    
}

//FUNCTII SPECIALE - desenat
void AfisarePorc()
{
    system("cls");
    cout << "                _,--.       ,--." << endl;
    cout << "                /  > ---- <    / " << endl;
    cout << "                `-.        .-'" << endl;
    cout << "                  / `e___e` \"" << endl;
    cout << "                 (   (o o)   )" << endl;
    cout << "                 _\_  `='  _/_" << endl;
    cout << "                / /|`-._.-'|\\ \\" << endl;
    cout << "               / /||_______||\\ \\" << endl;
    cout << "             _/ /_||=======||_\\ \\_" << endl;
    cout << "            / _/==||       ||==\\_ \\" << endl;
    cout << "            `'(   ^^       ^^   )`'" << endl;
    cout << "               \\               /" << endl;
    cout << "                \\______|______/" << endl;
    cout << "                |______|______|" << endl;
    cout << "                  )__|   |__(" << endl;
    cout << "                 /   ]   [   \"" << endl;
    cout << "                 `--'     `--'" << endl;
}
void AfisareScroafa()
{
    system("cls");
    cout << "                _,--.       ,--._" << endl;
    cout << "                \\  > `|>o<|' <  /" << endl;
    cout << "                 `-.         .-'" << endl;
    cout << "                   / 'e___e` \\" << endl;
    cout << "                  (   (o o)   )" << endl;
    cout << "                  _\\_  `='  _/_" << endl;
    cout << "                 / /(`-._.-')\\ \\" << endl;
    cout << "                / /  `.___,'  \\_\\" << endl;
    cout << "              _/ /    _____    \\ \\_" << endl;
    cout << "             / _(_,--'     `--._)_ \\" << endl;
    cout << "             `'  )______@______(  `'" << endl;
    cout << "                /               \\" << endl;
    cout << "               /_________________\\" << endl;
    cout << "                  \\     )(     /" << endl;
    cout << "                   \\   /  \\   /" << endl;
    cout << "                    )  |  |  (" << endl;
    cout << "                   /`-']  [`-'\\" << endl;
    cout << "                   `--'    `--'" << endl;
}
void AfisarePorcusor()
{
    system("cls");
    cout << "                        " << endl;
    cout << "                  <`--'\>______" << endl;
    cout << "                  /. .  `'     \\" << endl;
    cout << "                 (`')  ,        @" << endl;
    cout << "                  `-._,        /" << endl;
    cout << "                     )-)_/--( > " << endl;
    cout << "                     ''''  ''''" << endl;
}
void legenda_artistic(int& n) {
    system("cls");
    cout << "\t\t\t\t\t\tBine ati venit, aici puteti observa vizualizarea artistica a animalelor " << endl;
    cout << "\t\t\t\t\t\tCe tip de animal doriti sa vedeti?" << endl;
    cout << "\t\t\t\t\t\t1  - Porcusori" << endl;
    cout << "\t\t\t\t\t\t2  - Scroafe" << endl;
    cout << "\t\t\t\t\t\t3  - Porci" << endl;
    cout << "\t\t\t\t\t\t0  - Iesire" << endl;
    cout << endl;
    cout << " Optiunea dumneavoastra: ";
    cin >> n;
}
void artistic()
{
    int n, r;
    legenda_artistic(n);
    while (n != 0)
    {
        if (n == 1)
        {
            AfisarePorcusor();
        }
        else if (n == 2)
        {
            AfisareScroafa();
        }
        else if (n == 3)
        {
            AfisarePorc();
        }
        else if (n == 0) break;
        else cout << "\n   Nu ati introdus o obtiune valida";

        cout << endl << "   Doriti sa continuati programul si sa alegeti iar DIN LISTA DE ANIMALE?\n";
        cout << "     0 - NU\n";
        cout << "     1 - DA\n";
        cout << " Raspunsul dumneavoastra: ";
        cin >> r;
        if (r == 0) n = 0;
        else
        {
            system("cls");
            legenda_artistic(n);
        }
    }
}

//MENIU
void legenda(int&n) {
    cout << "\t\t\t\t\t\tMeniu " << endl;
    cout << "\t\t\t\t\t\t1) Adaugare animal" << endl;
    cout << "\t\t\t\t\t\t2) Eliberare animal" << endl;
    cout << "\t\t\t\t\t\t3) Actualizare animal" << endl;
    cout << "\t\t\t\t\t\t4) Statistica dupa tipurile de boxe" << endl;
    cout << "\t\t\t\t\t\t5) Istoric boxe" << endl;
    cout << "\t\t\t\t\t\t6) Vizualizarea continut hala" << endl;
    cout << "\t\t\t\t\t\t7) Vizualizarea artistica a animalelor" << endl;
    cout << "\t\t\t\t\t\t0) Iesire";
    cout << endl;
    cout << " Optiunea dumneavoastra: ";
    cin >> n;
}
void meniu()
{
    int n;
    legenda(n);
    while (n != 0)
    {
        if (n == 1) inserare();
        else if (n == 2) stergere();
        else if (n == 3) upgrade();
        else if (n == 4) statisticaBoxe();
        else if (n == 5) istoric();
        else if (n == 6) desenare();
        else if (n == 7) artistic();
        else if (n == 0) break;
        else cout << "\n   Nu ati introdus o optiune valida";

        system("cls");
        legenda(n);
    }
}

int main()
{
    initializareFerma();
    meniu();
    //upgrade();
    //cout <<Guitz;

	return 0;
}
