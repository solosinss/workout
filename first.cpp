#include <iostream>
#include <string>

using namespace std;

class Angajat 
{
    private:
        string nume;
        string prenume;
        unsigned int varsta;
        void schimba_nume();
    public:
        Angajat()
        {
            cout << "Constructor" << endl;
        }
        ~Angajat()
        {
            cout << "Destructor" << endl;
        }
        void seteazaNume(string n);
        void seteazaPrenume(string p);
        void seteazaVarsta(unsigned int v);

        void daNume();
        void daPrenume();
        void daVarsta();
};

void Angajat::seteazaNume(string n)
{
    cout << "Seteaza nume" <<endl;
    nume = n;
}

void Angajat::seteazaPrenume(string p)
{
    cout << "Seteaza prenume" <<endl;
    prenume = p;
}

void Angajat::seteazaVarsta(unsigned int v)
{
    cout << "Seteaza varsta" <<endl;
    varsta = v;
}

void Angajat::daNume()
{
    cout << nume <<endl;
}

void Angajat::daPrenume()
{
    cout << prenume <<endl;
}

void Angajat::daVarsta()
{
    cout << varsta <<endl;
}

int main()
{
    std::cout << "Enter 2 numbers:" << std::endl;
    int n1, n2;
    std::cin >> n1 >> n2;
    std::cout << "Sun of the numbers is " << n1 + n2 << std::endl;

    using std::cout;
    if (n1 > n2)
        cout << "n1 is greater"<< std::endl;
    else
        cout << "n2 is greater"<< std::endl;

    Angajat a;
    string nume;
    string prenume;
    unsigned int varsta;

    cout << "Nume: " <<endl;
    cin >> nume;
    a.seteazaNume(nume);

    cout << "Prenume: " <<endl;
    cin >> prenume;
    a.seteazaPrenume(prenume);

    cout << "Varsta: " <<endl;
    cin >> varsta;
    a.seteazaVarsta(varsta);

    a.daNume();
    
    a.daPrenume();
    
    a.daVarsta();
    
    return 0;
}
