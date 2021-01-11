/* Badescu Madalina 211
 GNU GCC COMPILER
 Szmeteanca Eduard */

#include <iostream>
#include <string.h>
#include <vector>
#include <iterator>
#include <list>
#include <map>

using namespace std;
/*
Constructorii, destructorii si supra incarcarile operatorilor sunt luate din proiect, dupa modele din curs si laborator
Template-ul pentru lista este gasit intr-un model de rezolvare de colocviu de la seria 13, dar nu stiu din ce an (am primit fisierul de la colegi)
*/

list<string> defaultList(){
    list<string> temp;
    temp.push_back("***");
    return temp;
}

class Vaccin{
protected:
    string numeProd;
    int pret;
    double temp;
    vector <string> substante;
public:
    Vaccin(string numeProd="***",int pret=0, double temp=0){
        this->numeProd=numeProd;
        this->pret=pret;
        this->temp=temp;
    }
    /*
    Vaccin (const Vaccin& v){
        this->pret=pret;
        this->temp=temp;

    }
    */
    void adaugaSubstante(){
        cout<<"Introduceti nr. de subtante:\n";
        int n;
        string substanta;
        cin>>n;
        for(int i=1;i<=n;i++){
            cout<<"Introduceti numele subtantei nr."<<n<<endl;
            cin>>substanta;
            substante.push_back(substanta);
        }
    }
    friend ostream& operator<< (ostream& out,  const Vaccin& v){
        out<<v.pret<<" ; "<<v.temp;
        vector <string> :: iterator it;
        //for (it =substante.begin(); it != substante.end(); ++ir)
            //cout << (*it)->getNume() << "; ";
        return out;
    }


    friend istream& operator>>(istream &, Vaccin&);
    virtual void afisareSchemaVaccinare()=0;
    virtual string getNumeVaccin()=0;

};
istream& operator>>(istream & in, Vaccin& v)
{
    in>>v.numeProd>>v.pret>>v.temp;
    return in;
}
class VaccinAntigripal: public Vaccin{
    string tulpina;
    bool respecta; //0= nu respecta recomandarile; 1= respecta recomandarile
public:
    VaccinAntigripal(string numeProd="***",int pret=0, double temp=0, string tulpina="&&&",bool respecta=0):Vaccin(numeProd,pret,temp){
        this->tulpina=tulpina;
        this->respecta=respecta;
    }
    friend ostream& operator<< (ostream& out,  const VaccinAntigripal& v){
        out<<v.pret<<" ; "<<v.temp;
        vector <string> :: iterator it;
        //for (it =v.substante.begin(); it != v.substante.end(); ++it)
         //   cout << (*it) << "; ";
        out<<v.tulpina<<" ; "<<v.respecta<<".\n";
        return out;
    }
    void afisareSchemaVaccinare(){
        cout<<"Vaccinul Antigripal se administreaza la adulti o doza de 0.5 ml, iar la copii si adolescenti o doza de 0.3 ml, repetandu-se din 2 in 2 an.\n";
    }
    friend istream& operator>>(istream &, VaccinAntigripal&);
    string getNumeVaccin(){ return "Antigripal";}
};
istream& operator>>(istream & in, VaccinAntigripal& v)
{
    in>>v.numeProd>>v.pret>>v.temp>>v.tulpina>>v.respecta;
    return in;
}

class VaccinAntihepatic: public Vaccin{
    string tip;
    string mod;
public:
    VaccinAntihepatic(string numeProd="***",int pret=0, double temp=0, string tip="###",string mod="%%%"):Vaccin(numeProd,pret,temp){
        this->tip=tip;
        this->mod=mod;
    }
    friend ostream& operator<< (ostream& out,  const VaccinAntihepatic& v){
        out<<v.pret<<" ; "<<v.temp;
        vector <string> :: iterator it;
        //for (it =substante.begin(); it != substante.end(); ++ir)
        //    cout << (*it)->getNume() << "; ";
        out<<v.tip<<" ; "<<v.mod<<".\n";
        return out;
    }
    void afisareSchemaVaccinare(){
        cout<<"Antihepatită A și B, la copii cu vârstă mai mică de 1 an se adminstrează 2 injectări la un interval de o lună, a treia injectare după 6 luni de la prima administrare, la adulți conform schemei de imunizare recomandată de medic Antihepatită C doar la recomandarea medicului.\n";
    }
    friend istream& operator>>(istream &, VaccinAntihepatic&);
    string getNumeVaccin(){ return "Antihepatic";}
};
istream& operator>>(istream & in, VaccinAntihepatic& v)
{
    in>>v.numeProd>>v.pret>>v.temp>>v.tip>>v.mod;
    return in;
}

class VaccinAntiSarsCov2: public Vaccin{
    vector <string> reactii;
    double rataEf;
    vector <string> medicamente;
public:
    VaccinAntiSarsCov2(string numeProd="***",int pret=0, double temp=0,double rataEf=0,list<string> a=defaultList(), list<string> b=defaultList()):Vaccin(numeProd,pret,temp){
        list<string>::iterator i;
        for (i = a.begin(); i != a.end(); ++i) {
            reactii.push_back(*i);
        }
        this->rataEf=rataEf;
        list<string>::iterator j;
        for (j = b.begin(); i != b.end(); ++j) {
            medicamente.push_back(*j);
        }

    }
    friend ostream& operator<< (ostream& out,  const VaccinAntiSarsCov2& v){
        out<<v.pret<<" ; "<<v.temp;
        vector <string> :: iterator it;
        //for (it =substante.begin(); it != substante.end(); ++ir)
        //    cout << (*it)->getNume() << "; ";
        out<<v.rataEf<<".\n";
        return out;
    }
    void afisareSchemaVaccinare(){
        cout<<"Vaccinul anti Sars-Cov2 se administrează persoanelor cu vârstă de peste 16 ani, 2 doze la o perioadă de 21 zile.\n";
    }
    friend istream& operator>>(istream &, VaccinAntiSarsCov2&);
    string getNumeVaccin(){ return "Antigripal";}
};
istream& operator>>(istream & in, VaccinAntiSarsCov2& v)
{
    in>>v.numeProd>>v.pret>>v.temp>>v.rataEf;
    return in;
}
class Comanda{
    static int ID;
    int id;
    string data;
    string nume;
    string tipVaccin;
    int cantitate;
    map <Vaccin*,int> listaVaccinuri;
public:
    Comanda(string data="0", string nume="@@@", string tipVaccin="???", int cantitate=0){
        this->data=data;
        this->nume=nume;
        this->tipVaccin=tipVaccin;
        this->cantitate=cantitate;
        ID++;
        id=ID;
        //imi apare bad alloc daca il las sa ruleze
        /*
        Vaccin* a = nullptr;
        if (tipVaccin == "AntiSarsCov2") a = new VaccinAntiSarsCov2;
        else if (tipVaccin == "Antihepatic") a = new VaccinAntihepatic;
        else if (tipVaccin == "Antigripal") a = new VaccinAntigripal;
        listaVaccinuri.insert(pair<Vaccin*,int>(a,this->cantitate));
        */
    }

    void afisareComanda(){
        cout<<nume<<" a comandat ";
        map <Vaccin*,int> :: iterator i;
        for(i=listaVaccinuri.begin();i!=listaVaccinuri.end();i++)
            cout<<i->second<<" de doze de vaccin "<<(i->first)->getNumeVaccin()<<", ";
    }
    int getID(){return id;}
};
int Comanda::ID=0;

class ListaComenzi{
    vector <Comanda*> lista;
public:
    Lista(Comanda c){
        lista.push_back(&c);
    }/*
    Lista& operator=(const Lista& l){
        if(this!=&l){

        }
    }*/
    ListaComenzi operator+(Comanda c)
    {
        this->lista.push_back(&c);
        return *this;
    }
    friend ostream& operator<< (ostream& out,  const ListaComenzi& l){
        vector <Comanda*> :: iterator it;
        //for (it =lista.begin(); it != lista.end(); ++ir)
        //    out<<(*it)->getID();
        return out;
    }
};
int main(){

    VaccinAntigripal a;
    VaccinAntihepatic b;
    VaccinAntiSarsCov2 c;
    cin>>a>>b>>c;
    cout<<a<<b<<c;
    Vaccin* lista[3];
    lista[0]=new VaccinAntigripal();
    lista[1]=new VaccinAntihepatic ();
    lista[2]=new VaccinAntiSarsCov2();
    for(int i=0; i<3; i++)
        lista[i]-> afisareSchemaVaccinare();

    Comanda com1("20-12-2020", "SpitalX", "AntiSarsCov2", 20);
    com1.afisareComanda();

    ListaComenzi lista1;
    lista1=lista1+com1;
    cout<<lista[0];

    return 0;
 }
