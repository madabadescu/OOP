#include <iostream>
#include <string.h>
#include <iterator>
#include <list>
#include <map>

using namespace std;

list<string> defaultList(){
    list<string> temp;
    temp.push_back("***");
    return temp;
}

class Basics{
public:
    virtual ~Basics(){};
    virtual void citire(istream &in) = 0;
    virtual void afisare(ostream &out) = 0;
    friend istream& operator >> (istream&, Basics&);
    friend ostream& operator << (ostream&, Basics&);
};
istream& operator>> (istream& in, Basics& x){
    x.citire(in);
    return in;
}
ostream& operator<< (ostream& out, Basics& x){
    x.afisare(out);
    return out;
}

class Vaccin:public Basics{
protected:
    string nume;//numele producatorului
    double pret, temp;
    list <string> substante; //lista cu substantele care compun vaccinul
public:
    Vaccin(string nume="***",double pret=0, double temp=1,list<string> a=defaultList()){
        this->nume=nume;
        this->pret=pret;
        this->temp=temp;
        list<string>::iterator i;
        for (i = a.begin(); i != a.end(); ++i) {
            substante.push_back(*i);
        }
        if (*substante.begin() == "***")
            substante.pop_front();
    }
    void citire (istream& in){
        cout<<"Numele producatorului: ";
        getline(in,nume);
        cout<<"Pret: ";
        in>>pret;
        cout<<"Temperatura de pastrare: ";
        in>>temp;
        in.get();
        string substanta;
        int nr;
        cout<<"Nr. substantelor: ";
        in>>nr;
        in.get();
        for (int i=0;i<nr;i++){
            cout<<"Substanta nr. "<<i<<": ";
            getline(in,substanta);
            substante.push_back(substanta);
        }
    }
    void afisare (ostream &out){
        out<<"Vaccinul produs de "<<nume<<" contine: ";
        list<string>::iterator i;
        for (i = substante.begin(); i != substante.end(); ++i) {
            out<<(*i)<<", ";
        }
        out<<"costa "<<pret<<" lei si se pastreaza la temperatura de "<<temp<<" grade Celsius. ";
    }
    friend istream& operator >> (istream& in, Vaccin&v){
        v.citire(in);
        return in;

    }
    friend ostream& operator << (ostream& out, Vaccin&v){
        v.afisare(out);
        return out;
    }
    ~Vaccin(){
        substante.~list<string>();
    }
};

class Antigripal: public Vaccin{
    string tip; //A-H1N1, A-H3N2 sau A-California
    bool recomandari; //0=nu respecta recomandarile OMS; 1=le respecta
public:
    Antigripal(string nume="***",double pret=0, double temp=0, string tip="&&&",bool recomandari=0,list<string> a=defaultList()):Vaccin(nume,pret,temp,a){
        this->tip=tip;
        this->recomandari=recomandari;
    }
    void citire(istream&in){
        Vaccin::citire(in);
        cout<<"Tastati 0 daca nu respecta recomandarile OMS, 1 daca le respecta: ";
        in>>recomandari;
        in.get();
        cout<<"Tulpina virusului: ";
        getline(in, tip);
    }
    void afisare(ostream&out){
        Vaccin::afisare(out);
        out<<"Tipul vaccinului este "<<tip;
        if(recomandari==0)  out<<", dar nu respecta recomandrile OMS.\n";
        else                out<<" si respecta recomandarile OMS.\n";
    }
    friend istream& operator >> (istream&in, Antigripal&g){
        g.citire(in);
        return in;
    }
    friend ostream& operator << (ostream&out, Antigripal&g){
        g.afisare(out);
        return out;
    }
};

class Antihepatic: public Vaccin{
    string tip; //hepatita A, B sau C
    string mod; //intramuscular, subcutanat, intradermic
public:
    Antihepatic(string nume="***",int pret=0, double temp=0, string tip="###",string mod="%%%",list<string> a=defaultList()):Vaccin(nume,pret,temp,a){
        this->tip=tip;
        this->mod=mod;
    }
    void citire(istream&in){
        Vaccin::citire(in);
        cout<<"Tip: ";
        getline(in, tip);
        cout<<"Mod injectare: ";
        getline(in, mod);
    }
    void afisare(ostream&out){
        Vaccin::afisare(out);
        out<<"Vaccinul trateaza "<<tip<<" si trebuie injectat "<<mod<<".\n";

    }
    friend istream& operator >> (istream&in, Antihepatic&h){
        h.citire(in);
        return in;
    }
    friend ostream& operator << (ostream&out, Antihepatic&h){
        h.afisare(out);
        return out;
    }

};

class Anticovid: public Vaccin{
    list <string> reactii; //lista cu reactii adverse
    double eficienta; //rata de eficienta
public:
    Anticovid(string nume="***",double pret=0,double temp=0,double eficienta=0,list<string>a=defaultList(),list<string>b=defaultList())
             :Vaccin(nume,pret,temp,a){
        this->eficienta=eficienta;
        list<string>::iterator i;
        for (i = b.begin(); i != b.end(); ++i) {
            reactii.push_back(*i);
        }
        if (*reactii.begin() == "***")
            reactii.pop_front();
    }
    void citire(istream&in){
        Vaccin::citire(in);
        cout<<"Eficienta: ";
        in>>eficienta;
        int nr;
        cout<<"Nr. reactiilor adverse: ";
        in>>nr;
        string reactia;
        in.get();
        for (int i=0;i<nr;i++){
            cout<<"Reactia nr. "<<i<<": ";
            getline(in,reactia);
            reactii.push_back(reactia);
        }
    }
    void afisare(ostream&out){
        Vaccin::afisare(out);
        out<<"Vaccinul are rata de eficienta de "<<eficienta<<"%, dar poate prezenta urmatoarele reactii advers: ";
        list<string>::iterator i;
        for (i = reactii.begin(); i != reactii.end(); ++i) {
            out<<(*i)<<", ";
        }
    }
    friend istream& operator >> (istream&in, Anticovid&c){
        c.citire(in);
        return in;
    }
    friend ostream& operator << (ostream&out, Anticovid&c){
        c.afisare(out);
        return out;
    }
    ~Anticovid(){
        reactii.~list<string>();
    }
};
class Comanda{
    const int ID;
    int data[3];
    string client;
    map<Vaccin*,int> vaccinuri;
public:
    int valoareComanda(){}
};

int main(){
    Vaccin v;
    //cin>>v;
    //cout<<v;
    Antigripal g;
    Antihepatic h;
    Anticovid c;
    cin>>c;
    cout<<c;
    return 0;
}
