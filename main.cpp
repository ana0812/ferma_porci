#include<iostream>
#include"Ferma.h"
#include"Boxa.h"
#include"Animale.h"
#include<fstream>
#include<vector>
using namespace std;

Ferma Guitz;
int ultimpcnp=0;

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

    istoric_adaugare(Guitz.listaBoxe.at(alegere-1).cod,greutate,data);
    registru_adaugare(Guitz.listaBoxe.at(alegere - 1).cod, greutate, data);
}

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
    cout << "Ce boxa alegeti? Puneti doar numarul boxei.";
    while (!ok)
    {
        cin >> boxaaleasa;
        for (i = 0; i < nr.size(); i++) {
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

void stergere() {
    int alegere, i, ok = 0;
    cout << "Ce tip de porc doriti sa stergeti?" << endl;
    cout << "1. Pucelusi\n2. Scroafa\n3. Porc" << endl;
    cout << "Alegerea dvs este: "; cin >> alegere;
    vector<int> nr;

    //verificam pt tipul de porc ales daca se poate sterge vreunul
    //daca se pot sterge pastram in vectorul nr boxele respective
    //afisam boxele din care se pot sterge porci
    if (alegere == 1) {
        for (i = 0; i < Guitz.listaBoxe.size(); i++)
        {
            if (!Guitz.listaBoxe.at(i).tip.compare("mic"))
            {
                if (Guitz.listaBoxe.at(i).nrPorci > 0)
                {
                    cout << Guitz.listaBoxe.at(i).cod << endl;
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
    else if (alegere == 2) {
        for (i = 0; i < Guitz.listaBoxe.size(); i++)
        {
            if (!Guitz.listaBoxe.at(i).tip.compare("mediu"))
            {
                if (Guitz.listaBoxe.at(i).nrPorci > 0)
                {
                    cout << Guitz.listaBoxe.at(i).cod << endl;
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
    else if (alegere == 3) {
        for (i = 0; i < Guitz.listaBoxe.size(); i++)
        {
            if (!Guitz.listaBoxe.at(i).tip.compare("mare"))
            {
                if (Guitz.listaBoxe.at(i).nrPorci > 0)
                {
                    cout << Guitz.listaBoxe.at(i).cod << endl;
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
    else {
        cout << "Nu ati ales o optiune valida. Reveniti in functie";
        return;
    }

    //utilizatorul alege numarul boxei din care vrea sa elibereze porci
    int boxaaleasa = 0;
    if (!alegere_boxa(nr, boxaaleasa)) {
        return;
    }
    //cout << boxaaleasa;

    //aici va trebui sa aleaga porcul pe care vrea sa il elibereze
    stergere_pt2(boxaaleasa-1, alegere);
}

void istoric()
{
    int n, r, i;
    cout << "     Bine ati venit, aici puteti vizualiza istoricul boxelor " << endl;
    cout << "     Istoricul carei boxe doriti sa il vedeti?" << endl;
    for (i = 0; i < Guitz.nrBoxe ; i++)
    {
        cout << "         " << Guitz.listaBoxe.at(i).cod << endl;
    }
    cout << "         0  - Iesire" << endl;
    cout << endl;
    cout << "  Obtiunea dumneavoastra: ";
    cin >> n;
    while (n != 0)
    {
        
        if (n > Guitz.nrBoxe ) cout << "\n   Nu ati introdus o obtiune valida";
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
                    cout << box << " " << tip << " " << nr << endl;
                    for (i = 0; i < nr; i++) {
                        isto >> cnp >> g >> data;
                        cout << cnp << " " << g << " " << data << endl;
                    }
                    isto.ignore();
                    isto.getline(linie, 250);
                    while (strcmp(linie, "*"))
                    {
                        cout << linie << endl; ////!!!!!!!!!!!!!
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
            cout << "\n   Obtiunea dumneavoastra:  ";
            cin >> n;
        }
    }
}

void statisticaBoxe()
{
    int n, r, i, k = 0;
    cout << "     Bine ati venit, aici puteti vizualiza statistici despre boxe " << endl;
    cout << "     Statistica carei tip de boxe doriti sa o vedeti?" << endl;

    cout << "         1  - Mica  -> Purcelusi" << endl;
    cout << "         2  - Medie -> Scroafe" << endl;
    cout << "         3  - Mare  -> Porci" << endl;
    cout << "         0  - Iesire" << endl;
    cout << endl;
    cout << "  Optiunea dumneavoastra: ";
    cin >> n;
    vector <int> box;
    while (n != 0)
    {
        if (n == 0) return;
        else if (n > 3) cout << "\n   Nu ati introdus o optiune valida";
        else
        {
            //textul pentru boxe
            cout << "             STATISTICA" << endl << endl;

            cout << "             Tipul boxei: ";
            if (n == 1) cout << "Mica" << endl;
            else if (n == 2) cout << "Medie" << endl;
            else if (n == 3) cout << "Mare" << endl;

            cout << "             Tipul animalelor: ";
            if (n == 1) cout << "Purcelusi" << endl;
            else if (n == 2) cout << "Scroafe" << endl;
            else if (n == 3) cout << "Porci" << endl;

            int totalporci;
            cout << "             Numarul total animalelor: ";
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

            cout << "             Numarul maxim de animale: " << Guitz.nrMaxBoxePorci << endl;

            cout << "             Numarul boxelor: ";

            if (n == 1) {
                for (i = 0; i < Guitz.nrBoxe; i++)
                {
                    if (!(Guitz.listaBoxe.at(i).tip).compare("mic")) {
                        k++;
                        box.push_back(k);
                    }

                }
            }
            else if (n == 2) {
                for (i = 0; i < Guitz.nrBoxe; i++)
                {
                    if (!(Guitz.listaBoxe.at(i).cod).compare("mediu")) {
                        k++;
                        box.push_back(k);
                    }
                }
            }
            else if (n == 3) {
                for (i = 0; i < Guitz.nrBoxe; i++)
                {
                    if (!(Guitz.listaBoxe.at(i).cod).compare("mare")) {
                        k++;
                        box.push_back(k);
                    }
                }
            }

            cout << k << endl;
            float gmin=500, gmax=0, medie = 0;
            float gr;
            if (k == 0) {
                cout << "Nu exista boxe de acest tip";
            }
            else {
                cout << "Numarul de animale din fiecare boxa: " << endl;

                //parcurg tipul de boxe care ma intereseaza
                for (i = 0; i < box.size(); i++) {
                    cout << Guitz.listaBoxe.at(i).cod << " " << Guitz.listaBoxe.at(i).nrPorci << " animale" << endl;
                    //parcurg animalele din fiecare boxa si retin informatiile care ma intereseaza
                    for (int j = 0; j < Guitz.listaBoxe.at(i).listaAnimale.size(); j++) {
                        gr = Guitz.listaBoxe.at(i).listaAnimale.at(j).greutate;
                        if (gr > gmax) {
                            gmax = gr;
                        }
                        else {
                            gmin = gr;
                        }
                        medie += gr;
                    }
               }
                cout << "Greutatea minima din acest tip de boxa: " << gmin << endl;
                cout << "Greutatea maxima din acest tip de boxa: " << gmax << endl;
                medie /= totalporci;
                cout << "Media greutatilor din acest tip de boxa: " << medie << endl<<endl;

            }

        }

        cout << endl << "   Doriti sa continuati programul si sa alegeti iar DIN LISTA BOXE?\n";
        cout << "     0 - NU\n";
        cout << "     1 - DA\n";
        cout << " Raspunsul dumneavoastra: ";
        cin >> r;
        if (r == 0) n = 0;
        else
        {
            cout << "\n   Optiunea dumneavoastra:  ";
            cin >> n;
        }
    }
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

    //cout << Guitz;
    //inserare();
    //cout << Guitz;
    //stergere();
    //istoric();
    statisticaBoxe();

	return 0;
}
