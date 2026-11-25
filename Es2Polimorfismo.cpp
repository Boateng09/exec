#include <iostream>
#include <vector>
using namespace std;

class Personaggio {
public:
    virtual void attacca() = 0;
    virtual void presentati() = 0;
};

class Guerriero : public Personaggio {
public:
    void attacca() {
        cout << "Attacco con la spada!\n";
    }

    void presentati() {
        cout << "Sono un guerriero.\n";
    }
};

class Mago : public Personaggio {
public:
    void attacca() {
        cout << "Lancio una magia!\n";
    }

    void presentati() {
        cout << "Sono un mago.\n";
    }
};

class Arciere : public Personaggio {
public:
    void attacca() {
        cout << "Scocco una freccia!\n";
    }

    void presentati() {
        cout << "Sono un arciere.\n";
    }
};

void turno(Personaggio* p) {
    p->presentati();
    p->attacca();
}
