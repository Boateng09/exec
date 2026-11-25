#include <iostream>
using namespace std;

class Veicolo {
public:
    virtual void muovi() = 0;
    virtual void descrizione() = 0;
};

class Auto : public Veicolo {
public:
    void muovi() {
        cout << "L'auto si muove.\n";
    }

    void descrizione() {
        cout << "Sono un'auto.\n";
    }
};

class Bicicletta : public Veicolo {
public:
    void muovi() {
        cout << "La bicicletta si muove.\n";
    }

    void descrizione() {
        cout << "Sono una bicicletta.\n";
    }
};

class Treno : public Veicolo {
public:
    void muovi() {
        cout << "Il treno si muove.\n";
    }

    void descrizione() {
        cout << "Sono un treno.\n";
    }
};
int main() {
    Auto auto1;
    Bicicletta bici;
    Treno treno;

    std::vector<Veicolo*> veicoli = {&auto1, &bici, &treno};

    for (Veicolo* v : veicoli) {
        v->descrizione();
        v->muovi();
    }

    return 0;
}
