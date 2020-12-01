#include <iostream>
#include <string.h>

using namespace std;

class Angajat{
    const int ID_angajat;
    char* nume;//toate numele sunt despartite de _ spre ex: Popa_Ion
    char initialaTata;
    bool gen; //0=barbat; 1=femeie;
    int* dataNastere;
    int varsta;
    double prima;
    char post[100];
    float salariu;
    int zileConcediu[12]; //nr zilelor de concediu luate in fiecare luna
    static int contor;
public:
    Angajat():ID_angajat(0){
        initialaTata='A';
        gen=0;
        varsta=20;
        salariu=0;
        prima=0;
        nume=new char[strlen("Anonim")+1];
        strcpy(nume,"Anonim");
        dataNastere=new int[3];
        for(int i=0;i<3;i++)
            dataNastere[i]=0;
        strcpy(post,"Neangajat");
        for(int i=0;i<12;i++)
            zileConcediu[i]=0;
    }
    Angajat(int id, char* n,char init,bool gen,int* dataN,int v,double prima,char post[100],float salariu, int zileConcediu[12]):ID_angajat(id){
        this->initialaTata=init;
        this->gen=gen;
        this->varsta=v;
        this->salariu=salariu;
        this->prima=prima;
        this->nume=new char[strlen(n)+1];
        strcpy(this->nume,n);
        this->dataNastere=new int[3];
        for(int i=0;i<3;i++)
            this->dataNastere[i]=dataN[i];
        strcpy(this->post,post);
        for(int i=0;i<12;i++)
            this->zileConcediu[i]=zileConcediu[i];
    }
    Angajat(int id, char* n, int* dataN):ID_angajat(id){
        this->nume=new char[strlen(n)+1];
        strcpy(this->nume,n);
        this->dataNastere=new int[3];
        for(int i=0;i<3;i++)
            this->dataNastere[i]=dataN[i];
    }
    void afisare(){
        cout<<"Angajatul cu numele "<<this->nume<<" are varsta de "<<this->varsta<<" de ani si salariul "<<this->salariu<<"lei.\n";
    }
    char* getNume(){
        return this->nume;
    }
    char getInitiala(){
        return this->initialaTata;
    }
    bool getGen(){
        return this->gen;
    }
    int* getDataN(){
        return this->dataNastere;
    }
    int getVarsta(){
        return this->varsta;
    }
    char* getPost(){
        return this->post;
    }
    double getPrima(){
        return this->prima;
    }
    float getSalariu(){
        return this->salariu;
    }
    int* getZileC(){
        return this->zileConcediu;
    }
    void setNume(char* a){
        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume=new char[strlen(a)+1];
        strcpy(this->nume,a);
    }
    void setDataN(int* a){
        if(this->dataNastere!=NULL)
            delete[] this->dataNastere;
        this->dataNastere=new int[3];
        for(int i=0;i<3;i++)
            this->dataNastere[i]=a[i];
    }
    void setZileC(int a[12]){
        for(int i=0;i<12;i++)
            this->zileConcediu[i]=a[i];
    }
    void setVarsta(int a){
        this->varsta=a;
    }
    void setSalariu(float a){
        this->salariu=a;
    }
    void setPrima(double a){
        this->prima=a;
    }
    void setInit(char a){
        this->initialaTata=a;
    }
    void setGen(bool a){
        this->gen=a;
    }
    void setPrima(float a){
        a=double(a);
        this->prima=a;
    }
    void setPost(char a[100]){
        strcpy(this->post,a);
    }
    //functionalitate clasa:
    double salariuAnual(){
        double salariuA;
        salariuA = double(this->salariu)*12+this->prima;
        return salariuA;
    }
    Angajat (const Angajat& ang):ID_angajat(ang.ID_angajat){
        this->varsta=ang.varsta;
        this->gen=ang.gen;
        this->salariu=ang.salariu;
        strcpy(this->post,ang.post);
        this->initialaTata=ang.initialaTata;
        this->nume=new char[strlen(ang.nume)+1];
        strcpy(this->nume, ang.nume);
        this->dataNastere=new int[3];
        for(int i=0;i<3;i++)
            this->dataNastere[i]=ang.dataNastere[i];
        for(int i=0;i<12;i++)
            this->zileConcediu[i]=ang.zileConcediu[i];
    }
    Angajat& operator=(const Angajat& ang){
        if(this!=&ang){
                this->initialaTata=ang.initialaTata;
                this->gen=ang.gen;
                this->varsta=ang.varsta;
                this->prima=ang.prima;
                strcpy(this->post, ang.post);
                this->salariu=ang.salariu;
                if(this->nume!=NULL)
                    delete[] this->nume;
                this->nume=new char[strlen(ang.nume)+1];
                strcpy(this->nume, ang.nume);
                if(this->dataNastere!=NULL)
                   delete[] this->dataNastere;
                this->dataNastere=new int[3];
                for(int i=0;i<3;i++)
                    this->dataNastere[i]=ang.dataNastere[i];
                for(int i=0;i<12;i++)
                    this->zileConcediu[i]=ang.zileConcediu[i];
        }
        return *this;
    }
    friend ostream& operator<< (ostream& out,  const Angajat ang){
        out<<endl<<"Angajatul "<<ang.nume<<" are salariul de "<<ang.salariu<<" lei, este nascut in data de ";
        for(int i=0;i<3;i++)
            out<<ang.dataNastere[i]<<'.';
        out<<" si are "<<ang.varsta<<" ani."<<endl;
        return out;
    }
    friend istream& operator>>(istream &, Angajat&);
    //preincrementare
    const Angajat operator++(){
        this->varsta++;
        return *this;
    }
    //postincrementare
    const Angajat operator++(int){
        Angajat aux(*this);
        this->varsta++;
        return aux;
    }
    bool operator== (Angajat&);
    //ob+int
    Angajat operator+(int a)
    {
        this->salariu=this->salariu+a;
        return *this;
    }
    Angajat operator* (double a)
    {
        this->prima=this->prima*a;
        return *this;
    }
    friend bool operator> (const Angajat &a1, const Angajat &a2);
    int & operator[] (int i){
        return this->zileConcediu[i];
    }
    explicit operator int (){
        return this->varsta;
    }
    ~Angajat(){
        if(this->dataNastere!=NULL)
            delete[] this->dataNastere;
        if(this->nume!=NULL)
            delete[] this->nume;
    }
};
int Angajat::contor=3;

class Client{
    const int ID_Client;
    char* nume;
    bool scop;//0=afaceri, 1=vacanta
    char initialaTata;
    int nrPers;
    int* varstePers;
    float pret;
    double reducere;
    char numeDestinatie[100];
    static int an;
public:
    Client():ID_Client(0){
        nume = new char[strlen("Anonimul")+1];
        strcpy(nume,"Anonimul");
        scop=1;
        initialaTata='B';
        nrPers=0;
        varstePers=new int[1];
        for(int i=0;i<1;i++)
            varstePers[i]=0;
        reducere=0;
        strcpy(numeDestinatie, "Romania");
    }
    Client(int id,char* nume,bool scop,char initialaTata,int nrPers,int* varstePers,float pret,double reducere,char numeDestinatie[100]):ID_Client(id){
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->scop=scop;
        this->initialaTata=initialaTata;
        this->nrPers=nrPers;
        this->pret=pret;
        this->varstePers=new int[nrPers];
        for(int i=0;i<nrPers;i++)
            this->varstePers[i]=varstePers[i];
        this->reducere=reducere;
        strcpy(this->numeDestinatie, numeDestinatie);
    }
    Client(int id, char* nume, char numeDestinatie[100]):ID_Client(id){
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        strcpy(this->numeDestinatie, numeDestinatie);
    }
    Client (const Client& clt):ID_Client(clt.ID_Client){
        this->scop=clt.scop;
        this->initialaTata=clt.initialaTata;
        this->nrPers=clt.nrPers;
        strcpy(this->numeDestinatie,clt.numeDestinatie);
        this->reducere=clt.reducere;
        this->nume=new char[strlen(clt.nume)+1];
        strcpy(this->nume, clt.nume);
        this->varstePers=new int[nrPers];
        for(int i=0;i<nrPers;i++)
            this->varstePers[i]=clt.varstePers[i];
    }
    void afisare(){
        cout<<"Clientul "<<this->nume<<" calatoreste catre "<<this->numeDestinatie<<endl;
    }
    char* getNume(){
        return this->nume;
    }
    bool getScop(){
        return this->scop;
    }
    char getInit(){
        return this->initialaTata;
    }
    int getNrP(){
        return this->nrPers;
    }
    int* getVarsteP(){
        return this->varstePers;
    }
    float getPret(){
        return this->pret;
    }
    double getRed(){
        return this->reducere;
    }
    char* getNumeD(){
        return this->numeDestinatie;
    }
    void setNume(char* a){
        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume=new char[strlen(a)+1];
        strcpy(this->nume,a);
    }
    void setVarsteP(int* a,int b){
        if(this->varstePers!=NULL)
            delete[] this->varstePers;
        this->nrPers=b;
        this->varstePers=new int[b];
        for(int i=0;i<b;i++)
            this->varstePers[i]=a[i];
    }
    void setScop(bool a){
        this->scop=a;
    }
    void setInit(char a){
        this->initialaTata=a;
    }
    void setNrP(int a){
        this->nrPers=a;
    }
    void setPret(float a){
        this->pret=a;
    }
    void setReducere(double a){
        this->reducere=a;
    }
    void setNumeD(char a[100]){
        strcpy(this->numeDestinatie,a);
    }
    Client& operator=(Client&);
    friend ostream& operator<<(ostream &, Client&);
    friend istream& operator>>(istream &, Client&);
    const Client operator--(){
        this->nrPers--;
        return *this;
    }
    const Client operator--(int){
        Client aux(*this);
        this->nrPers--;
        return aux;
    }
    Client operator+(int a)
    {
        int varste[100];
        if(this->varstePers!=NULL)
        {
            for(int i=0; i<this->nrPers; i++)
                varste[i]=this->varstePers[i];
            delete[] this->varstePers;
        }
        this->nrPers++;
        this->varstePers=new int[this->nrPers];
        this->varstePers[this->nrPers-1]=a;
        for(int i=0; i<this->nrPers-1;i++)
            this->varstePers[i]=varste[i];
        this->varstePers[this->nrPers-1]=a;
        return *this;
    }
    Client operator-(int a)
    {
        this->reducere=this->reducere-a;
        return *this;
    }
    bool operator== (Client&);
    friend bool operator< (const Client &c1, const Client &c2);
    int & operator[] (int i){
        return this->varstePers[i];
    }
    explicit operator bool (){
        return this->scop;
    }
    //functionalitate clasa
    float pretFinal(){
        int pretF;
        pretF = this->pret - this->reducere;
        return pretF;
    }
    ~Client(){
        if(this->nume!=NULL)
            delete[] this->nume;
        if(this->varstePers!=NULL)
            delete[] this->varstePers;
    }

};
int Client::an=2020;

class Destinatie{
    const int ID_Dest;
    char* nume;
    bool disponibilitate;//0=ocupat;1=liber
    float pret;//pe zi pentru 1 per
    int capacitate;
public:
    Destinatie():ID_Dest(0){
        nume = new char[strlen("Tara_de_nicaieri")+1];
        strcpy(nume,"Tara_de_nicaieri");
        disponibilitate=1;
        pret=0;
        capacitate=0;
    }
    Destinatie(int id,char* nume,bool disponibilitate,int capacitate,float pret):ID_Dest(id){
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->disponibilitate=disponibilitate;
        this->capacitate=capacitate;
        this->pret=pret;
    }
    Destinatie(int id,char* nume,float pret):ID_Dest(id){
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->pret=pret;
    }
    void afisare(){
        cout<<"La destinatia "<<this->nume<<" o noapte de cazare pentru o persoana are pretul de "<<this->pret<<" lei";
    }
    Destinatie (const Destinatie& dst):ID_Dest(dst.ID_Dest){
        this->disponibilitate=dst.disponibilitate;
        this->pret=dst.pret;
        this->capacitate=dst.capacitate;
        this->nume=new char[strlen(dst.nume)+1];
        strcpy(this->nume, dst.nume);
    }
    Destinatie& operator=(Destinatie&);

    friend ostream& operator<< (ostream& out,  const Destinatie dst){
        out<<endl<<"Destinatia "<<dst.nume<<" are capacitatea de "<<dst.capacitate<<" persoane, pentru pretul de "<<dst.pret<<" lei pe noapte";
        return out;
    }
    friend istream& operator>> (istream &, Destinatie&);
    //functionalitate clasa:
    float pretSapt(){
        int pretS;
        pretS=this->pret*7;
        return pretS;
    }
    ~Destinatie(){
        if(this->nume!=NULL)
            delete[] this->nume;
    }
};
//clasa derivata din Destinatie
class Romania:public Destinatie{
    string judet;
public:
    Romania():Destinatie(){
        this->judet="Judet";
    }
    Romania(int id,char* nume,bool disponibilitate,float pret,int capacitate,string judet):Destinatie(id,nume,disponibilitate,capacitate,pret){
        this->judet=judet;
    }
    Romania(Destinatie d1, string judet):Destinatie(d1){
        this->judet=judet;
    }
    Romania(const Romania& d):Destinatie(d){
        this->judet=d.judet;
    }
    void afisare(){
        Destinatie::afisare();
        cout<<", in judetul "<<this->judet;
    }
    friend ostream& operator<<(ostream& out, const Romania& r){
         out<<(Destinatie&)r;
         out<<", in judetul "<<r.judet;
         return out;
    }
    friend istream& operator>> (istream &, Romania&);
    Romania& operator=(Romania&);
    //metoda noua a clasei
    void afisareEroare(){
        if(judet=="Strainatate")
            cout<<"Destinatia introdusa nu se afla in Romania.\n";
    }
};
class Oferta{
    const int ID_Oferta;
    char* nume;
    int* perioada;
    float reducere;
    bool disponibilitate;
    int pretMaxim;
public:
    Oferta():ID_Oferta(0){
        nume = new char[strlen("Proba")+1];
        strcpy(nume,"Proba");
        disponibilitate=1;
        reducere=0;
        pretMaxim=0;
        perioada=new int[6];
        for(int i=0;i<6;i++)
            perioada[i]=0;
    }
    Oferta(int id, char* nume, int* perioada, float reducere, bool disponibilitate, int pretMaxim):ID_Oferta(id){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->disponibilitate=disponibilitate;
        this->reducere=reducere;
        this->perioada=new int[6];
        this->pretMaxim=pretMaxim;
        for(int i=0;i<6;i++)
            this->perioada[i]=perioada[i];
    }
    Oferta(int id, char* nume,float reducere):ID_Oferta(id){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->reducere=reducere;
    }
    void afisare(){
        cout<<"Oferta "<<this->nume<<" aduce o reducere de "<<this->reducere<<"% din pretul total pentru orice calatorie";
    }
    Oferta (const Oferta& ofr):ID_Oferta(ofr.ID_Oferta){
        this->reducere=ofr.reducere;
        this->disponibilitate=ofr.disponibilitate;
        this->pretMaxim=ofr.pretMaxim;
        this->nume=new char[strlen(ofr.nume)+1];
        strcpy(this->nume, ofr.nume);
        this->perioada=new int[6];
        for(int i=0;i<6;i++)
            this->perioada[i]=ofr.perioada[i];
    }
    Oferta& operator=(Oferta&);
    friend ostream& operator<< (ostream& out,  const Oferta ofr){
        out<<endl<<"Oferta "<<ofr.nume<<" este valabila in perioada ";
        for(int i=0;i<3;i++)
            out<<ofr.perioada[i]<<'.';
        out<<" - ";
        for(int i=3;i<6;i++)
            out<<ofr.perioada[i]<<'.';
        out<<" si ofera o reducere de "<<ofr.reducere<<"%";
        return out;
    }
    friend istream& operator>> (istream &, Oferta&);
    //functionalitate clasa:
    float maxOferta(){
        float maxO;
        maxO=pretMaxim*reducere/100;
        return maxO;
    }
    ~Oferta(){
        if(nume!=NULL)
            delete[] nume;
    }
};
//clasa derivata din Oferte
class SarbatoriIarna:public Oferta{
    string luna;
public:
    SarbatoriIarna():Oferta(){
        this->luna="Iarna";
    }
    SarbatoriIarna(int id,char* nume,int* perioada,float reducere,bool disponibilitate,int pretMaxim,string luna):Oferta(id,nume,perioada,reducere,disponibilitate,pretMaxim){
        this->luna=luna;
    }
    SarbatoriIarna(Oferta o1, string luna):Oferta(o1){
        this->luna=luna;
    }
    SarbatoriIarna(const SarbatoriIarna& o):Oferta(o){
        this->luna=o.luna;
    }
    void afisare(){
        Oferta::afisare();
        cout<<", valabila in luna "<<this->luna;
    }
    friend ostream& operator<<(ostream& out, const SarbatoriIarna& s){
         out<<(Oferta&)s;
         out<<", valabila in luna "<<s.luna;
         return out;
     }
    friend istream& operator>> (istream &, SarbatoriIarna&);
    SarbatoriIarna& operator=(SarbatoriIarna&);
    //metoda noua a clasei
    void afisareEroare(){
        int ok=1;
        if(luna=="Decembrie")
            ok=0;
        else if(luna=="Ianuarie")
            ok=0;
        else if(luna=="Februarie")
            ok=0;
        if(ok==1)
            cout<<"Aceasta oferta nu se aplica iarna.\n";
    }
};
//interfata
class Buget{
public:
    virtual int Salariu()=0;
    virtual float Profit()=0;
};
//clasa abstracta
class Locatie{
protected:
    string nume;
    float pret;
    int minNoptiCazare;
public:
    Locatie(){
        nume="Anonim";
        this->pret=0;
        this->minNoptiCazare=0;
    }
    Locatie(string nume, float pret, int minNoptiCazare){
        this->nume=nume;
        this->pret=pret;
        this->minNoptiCazare=minNoptiCazare;
    }
    virtual float pretMin()=0;
    friend istream& operator >>(istream& in, Locatie &l){
        cout<<"Introduceti numele, pretul si numarul minim de nopti acceptat la locatie:\n";
        in>>l.nume>>l.pret>>l.minNoptiCazare;
        return in;
    }
    friend ostream& operator<<(ostream& out,const Locatie &l){
        out<<"O noapte de cazare costa "<<l.pret<<" lei si se accepta minimul de "<<l.minNoptiCazare<<" nopti in locatia "<<l.nume;
        return out;
    }
};
//clasa pe care o folosim pentru relatia HAS-A
class RestaurantHotel{
    int nrLocuri;
    float pretMediu;
public:
    RestaurantHotel(){
        this->nrLocuri=0;
        this->pretMediu=0;
    }
    RestaurantHotel(int nrLocuri, float pretMediu){
        this->nrLocuri=nrLocuri;
        this->pretMediu=pretMediu;
    }
    float pretFamilie(){
        return 3*pretMediu;
    }
    void afisare(){
        cout<<"Restaurantul are o capacitate de "<<this->nrLocuri<<" locuri si pretul mediu al unei mese este "<<this->pretMediu<<" lei.\n";
    }
    int getNrL() const{
        return this->nrLocuri;
    }
    float getPretM() const{
        return this->pretMediu;
    }
    void setNrL(int a){
        this->nrLocuri=a;
    }
    void setPretM(float a){
        this->pretMediu=a;
    }
    RestaurantHotel (const RestaurantHotel& rh){
        this->nrLocuri=rh.nrLocuri;
        this->pretMediu=rh.pretMediu;
    }
};
class Hotel:public Locatie{
    int nrStele;
    RestaurantHotel ob;
public:
    Hotel():Locatie(),ob(){
        this->nrStele=0;
    }
    Hotel(string nume, float pret, int minNoptiCazare,int nrStele,RestaurantHotel ob1):Locatie(nume,pret,minNoptiCazare){
        this->nrStele=nrStele;
        ob=ob1;
    }
    float pretMin(){
        return pret*minNoptiCazare;
    }
    friend ostream& operator<<(ostream& out,const Hotel& h)
    {
        out<<(Locatie&)h;
        out<<", hotel de "<<h.nrStele<<" stele care are un restaurant cu "<<h.ob.getNrL()<<" locuri.\n";
        return out;
    }
    friend istream& operator >>(istream& in, Hotel &h){
        in>>(Locatie&)h;
        cout<<"Numarul de stele: ";
        in>>h.nrStele;
        return in;
    }
};
class Apartament:public Locatie{
    int nrCamere;
    float reducere;
public:
    Apartament():Locatie(){
        nrCamere=0;
        reducere=0;
    }
    Apartament(string nume, float pret, int minNoptiCazare, int nrCamere, float reducere):Locatie(nume,pret,minNoptiCazare){
        this->nrCamere=nrCamere;
        this->reducere=reducere;
    }
    float pretMin(){
        return pret*minNoptiCazare-reducere;
    }
    friend ostream& operator<<(ostream& out,const Apartament& ap)
    {
        out<<(Locatie&)ap;
        out<<", apartament cu  "<<ap.nrCamere<<" camere caruia i se aplica reducerea de "<<ap.reducere<<" lei.\n";
        return out;
    }
    friend istream& operator >>(istream& in, Apartament &ap){
        in>>(Locatie&)ap;
        cout<<"Numarul camerelor: ";
        in>>ap.nrCamere;
        cout<<"Reducere:";
        in>>ap.reducere;
        return in;
    }
};

int main()
{

    cout<<"-----Despre Angajati-----\n";
    Angajat a1;
    a1.afisare();

    char init1='G';
    char nume1[]={"Balan_Miruna"};
    int dataN1[]={7, 10, 1999};
    char post1[100];
    strcpy(post1,"Manager");
    int zileConcediu[12];
    for(int i=0;i<12;i++)
        zileConcediu[i]=0;
    zileConcediu[3]=15;
    zileConcediu[7]=5;

    Angajat a2(101, nume1, init1, 1, dataN1, 21, 1200.0, post1, 7000, zileConcediu);
    a2.afisare();

    char nume2[]={"Costache_Ana"};
    int dataN2[]={19, 1, 1994};

    Angajat a3(102, nume2, dataN2);
    a3.afisare();

    cout<<endl<<a2.getNume()<<" castiga suma de "<<a2.getSalariu()<<" lei."<<endl;

    char nume3[]={"Costache_Maria"};
    a3.setNume(nume3);
    int dataN3[]={18, 2, 1995};
    a3.setDataN(dataN3);
    a3.setVarsta(26);
    a3.setSalariu(5500);
    a3.afisare();

    cout<<"\n Salariul anual este de "<<a2.salariuAnual()<<" lei.\n";

    Angajat a4(a2);
    a4.afisare();

    Angajat a5;
    a5=a3;
    a5.afisare();

    cout<<a3<<endl<<a4;

    cout<<"Introduceti numele, salariul si varsta angajatului:\n";
    Angajat a6;
    cin>>a6;
    a6.afisare();

    cout<<"Varste: "<<a2.getVarsta()<<' ';
    ++a2;
    cout<<a2.getVarsta()<<' ';
    a2++;
    cout<<a2.getVarsta()<<endl<<endl;

    if(a2==a4)
        cout<<"Da"<<endl;

    a2+600;
    a3+100;
    cout<<"Salarii "<<a2.getSalariu()<<' '<<a3.getSalariu()<<endl;

    a3.setPrima(700.0);
    a2*0.5;
    a3*0.75;
    cout<<"Prime "<<a2.getPrima()<<' '<<a3.getPrima()<<endl;

    a2.setVarsta(65);
    if(a2>a4)
        cout<<"Da"<<endl;

    int varsta_a2=(int)a2;
    cout<<"Varsta "<<varsta_a2<<endl;
    cout<<"Nr zile de concediu "<<a2[3]<<" si ";
    a2[10]=3;
    cout<<a2[10]<<endl;


    cout<<endl<<"\n-----Despre Clienti-----"<<endl;

    Client c;
    c.afisare();

    char numec1[]={"Gabriel_Popescu"};
    int varstePers[]={20, 21, 24};
    char numeDestinatie[100];
    strcpy(numeDestinatie,"Bahamas");
    float pret1=7500;
    Client c1(1, numec1, 1, 'M',3, varstePers, pret1, 500, numeDestinatie);

    char numec2[]={"Marian_Popa"};
    Client c2(2,numec2,"Maldive");
    c2.afisare();

    cout<<endl<<"Clientul "<<c1.getNume()<<" a platit "<<c1.getPret()<<" lei pentru calatoria sa."<<endl;

    Client cc1(c1);
    cc1.afisare();

    if(c1==cc1)
        cout<<"Da"<<endl;

    Client c3=c1;
    c3.afisare();

    cout<<c1;

    cout<<"Introduceti numele clientului, pretul vacantei si numele destinatiei:\n";
    Client c4;
    cin>>c4;
    c4.afisare();

    cout<<"Nr de persoane "<<c1.getNrP()<<' ';
    c1--;
    cout<<c1.getNrP()<<' ';
    --c1;
    cout<<c1.getNrP()<<' '<<endl;

    c1+22;
    cout<<"Varsta "<<*(c1.getVarsteP()+1)<<endl;

    c1-10;
    cout<<"Modificare reducere "<<c1.getRed()<<endl;

    c1.setNrP(3);
    c2.setNrP(5);
    if(c1<c2)
        cout<<"Da"<<endl;
    cout<<"Pretul final este "<<c1.pretFinal()<<endl;

    cout<<"Varste persoane "<<c1[0]<<' ';
    c1[1]=32;
    cout<<c1[1]<<endl;

    bool scopc1=(bool)c1;
    cout<<"Scop "<<scopc1<<endl;


    cout<<endl<<"\n-----Despre Destinatii-----"<<endl;

    Destinatie d;
    d.afisare();
    cout<<endl;

    char numed1[]={"Hotel_Ibis_Cluj"};
    Destinatie d1(1,numed1,1,400,240);
    d1.afisare();
    cout<<endl;
    char numed2[]={"Hotel_Hilton_Praga"};
    Destinatie d2(2,numed2,500);
    d2.afisare();
    cout<<endl;

    Destinatie cd1(d1);
    d1.afisare();
    cout<<endl;

    Destinatie d3=d2;
    d2.afisare();
    cout<<endl;

    cout<<cd1;

    cout<<"\nIntroduceti numele destinatiei, pretul, disponibilitatea si capacitatea:\n";
    Destinatie d4;
    cin>>d4;
    cout<<d4;

    cout<<"Pretul intr-o saptmana este de "<<d1.pretSapt()<<" lei."<<endl<<endl;

    cout<<endl<<"\n-----Despre Destinatiile din Romania-----"<<endl;
    Romania r1;
    r1.afisare();
    cout<<endl;

    char numer2[]={"Hotel_Dana"};
    Romania r2(12, numer2, 1, 135, 34, "Constanta");
    r2.afisare();
    cout<<endl;

    Romania r3(r2);
    r3.afisare();
    cout<<endl;

    Romania r4(d1, "Cluj Napoca");
    r4.afisare();
    cout<<endl;
    cout<<r4<<endl;

    Romania r5;
    cout<<"Introduceti numele destinatiei, pretul, disponibilitatea si capacitatea:\n";
    cin>>r5;
    cout<<r5<<endl;

    Romania r6=r4;
    r6.afisare();
    cout<<endl;

    r4.afisareEroare();
    r5.afisareEroare();


    cout<<endl<<"\n-----Despre Oferte-----"<<endl;

    Oferta o;
    o.afisare();
    cout<<endl;

    char numeo1[]={"Black_Friday"};
    int perioada1[]={20, 11, 2020, 1, 12, 2020};
    Oferta o1(1, numeo1, perioada1, 30, 1, 6000);
    o1.afisare();
    cout<<endl;

    char numeo2[]={"Vine_Craciunul"};
    Oferta o2(2, numeo2, 25);
    o2.afisare();
    cout<<endl;

    Oferta co1(o1);
    co1.afisare();
    cout<<endl;

    Oferta o3=o1;
    o3.afisare();
    cout<<endl;

    cout<<o<<endl<<o1<<endl;

    cout<<"Introduceti numele ofertei, reducerea, disponibilitatea si pretul maxim:\n";
    Oferta o4;
    cin>>o4;
    o4.afisare();

    cout<<"\nReducerea maxima prevazuta de oferta este de "<<o1.maxOferta()<<"lei.\n"<<endl;

    cout<<endl<<"\n-----Despre Ofertele de Sarbatori de Iarna-----"<<endl;
    SarbatoriIarna s1;
    s1.afisare();
    cout<<endl;

    int perioadas2[]={1, 12, 2020, 31, 12, 2020};
    char numes2[]={"Clopotei"};
    SarbatoriIarna s2(13,numes2,perioadas2,15,1,5000,"Decembrie");
    s2.afisare();
    cout<<endl;

    SarbatoriIarna s3(s2);
    s3.afisare();
    cout<<endl;

    SarbatoriIarna s4(o1, "Noiembrie");
    s4.afisare();
    cout<<endl;

    cout<<s4<<endl;

    SarbatoriIarna s5;
    cout<<"Introduceti numele ofertei, reducerea, disponibilitatea si pretul maxim:\n";
    cin>>s5;
    s5.afisare();
    cout<<endl;

    SarbatoriIarna s6=s4;
    s6.afisare();
    cout<<endl;

    s4.afisareEroare();
    s5.afisareEroare();


    cout<<endl<<"\n-----Despre Locatii-----"<<endl;
    Locatie *l[2];

    Hotel h;
    Apartament ap;

    cin>>h>>ap;

    l[0]=new Hotel();
    *l[0]=h;
    cout<<h;

    l[1]=new Apartament();
    *l[1]=ap;
    cout<<ap;

    cout<<l[0]->pretMin()<<" "<<l[1]->pretMin();

    cout<<endl<<"\n-----Despre Restaurantele din Hotel-----"<<endl;
    RestaurantHotel rh;
    rh.afisare();

    RestaurantHotel rh1(50, 65);
    rh1.afisare();

    RestaurantHotel rh2(rh1);
    rh2.afisare();

    cout<<endl<<"\n-----Despre Hoteluri-----"<<endl;
    Hotel h1;
    cout<<h1;
    Hotel h2("Albatrosul", 120, 3, 3, rh1);
    cout<<h2;

    cout<<endl<<"\n-----Despre Apartamente-----"<<endl;
    Apartament ap1;
    cout<<ap1;
    Apartament ap2("Ana Maria", 230, 2, 3, 100);
    cout<<ap2;


    return 0;
}
istream& operator>>(istream & in, Angajat& a)
{
    in>>a.nume>>a.salariu>>a.varsta;
    return in;
}
bool Angajat::operator== (Angajat& ob)
{
    bool ok=1;
    for(int i;i<3;i++)
        if(dataNastere[i]!=ob.dataNastere[i])
            ok=0;
    return strcmp(nume, ob.nume) == 0 && salariu == ob.salariu && ok;
}
bool operator> (const Angajat &a1, const Angajat &a2)
{
    return a1.varsta > a2.varsta;
}
istream& operator>>(istream & in, Client& a)
{
    in>>a.nume>>a.pret>>a.numeDestinatie;
    return in;
}
ostream& operator<<(ostream& out, Client& clt)
{
    out<<endl<<"Clientul "<<clt.nume<<" a platit "<<clt.pret<<" pentru o calatorie pentru "<<clt.nrPers<<" persoane de varstele ";
    for(int i=0;i<clt.nrPers;i++)
        out<<clt.varstePers[i]<<", ";
    out<<"avand o reducere de "<<clt.reducere<<" lei."<<endl;
    return out;
}

Client& Client::operator=(Client& clt)
{
    if(this!=&clt){
        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume=new char[strlen(clt.nume)+1];
        strcpy(this->nume, clt.nume);
        if(this->varstePers!=NULL)
            delete[] this->varstePers;
        this->varstePers=new int[clt.nrPers];
        for(int i=0;i<6;i++)
            this->varstePers[i]=clt.varstePers[i];
        this->initialaTata=clt.initialaTata;
        this->scop=clt.scop;
        this->nrPers=clt.nrPers;
        this->pret=clt.pret;
        strcpy(this->numeDestinatie, clt.numeDestinatie);
        this->reducere=clt.reducere;
        }
        return *this;
}

bool Client::operator== (Client& ob)
{
    bool ok=1;
    for(int i;i<nrPers;i++)
        if(varstePers[i]!=ob.varstePers[i])
            ok=0;
    return strcmp(nume, ob.nume) == 0 && nrPers == ob.nrPers && ok;
}
bool operator< (const Client &c1, const Client &c2)
{
    return c1.nrPers < c2.nrPers;
}
Destinatie& Destinatie::operator=(Destinatie& ob)
{
    if (this != &ob)
    {
        nume = ob.nume;
        pret = ob.pret;
        capacitate = ob.capacitate;
        disponibilitate = ob.disponibilitate;
    }
    return *this;
}
istream& operator>>(istream & in, Destinatie& a)
{
    in>>a.nume>>a.pret>>a.disponibilitate>>a.capacitate;
    return in;
}
Romania& Romania::operator=(Romania& r){
    if(this!=&r){
        Destinatie::operator=(r);
        this->judet=r.judet;
    }
    return *this;
}
istream& operator>>(istream& in, Romania& r){
    in>>(Destinatie&)r;
    cout<<"Introduceti judetul: ";
    in>>r.judet;
    return in;
}
Oferta& Oferta::operator=(Oferta& ob)
{
    if (this != &ob)
    {
        nume = ob.nume;
        reducere = ob.reducere;
        disponibilitate = ob.disponibilitate;
        pretMaxim=ob.pretMaxim;
        for(int i=0;i<6;i++)
            perioada[i]=ob.perioada[i];
    }
    return *this;
}
istream& operator>>(istream & in, Oferta& a)
{
    in>>a.nume>>a.reducere>>a.disponibilitate>>a.pretMaxim;
    return in;
}
SarbatoriIarna& SarbatoriIarna::operator=(SarbatoriIarna& s){
    if(this!=&s){
        Oferta::operator=(s);
        this->luna=s.luna;
    }
    return *this;
}
istream& operator>>(istream& in, SarbatoriIarna& s){
    in>>(Oferta&)s;
    cout<<"Introduceti luna: ";
    in>>s.luna;
    return in;
}

