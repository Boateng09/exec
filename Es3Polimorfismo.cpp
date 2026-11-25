#include <iostream>
#include <vector>
using namespace std;

class MetodoPagamento {
public:
    virtual void paga(double importo) = 0;

    void pagaConCommissione(double importo, double percentuale) {
        double totale = importo + importo * percentuale / 100;
        paga(totale);
    }
};

class CartaCredito : public MetodoPagamento {
public:
    void paga(double importo) {
        cout << "Pagati " << importo << " euro con carta.\n";
    }
};

class PayPal : public MetodoPagamento {
public:
    void paga(double importo) {
        cout << "Pagati " << importo << " euro con PayPal.\n";
    }
};

class Contanti : public MetodoPagamento {
public:
    void paga(double importo) {
        cout << "Pagati " << importo << " euro in contanti.\n";
    }
};

int main() {
    CartaCredito carta;
    PayPal paypal;
    Contanti contanti;

    vector<MetodoPagamento*> metodi;
    metodi.push_back(&carta);
    metodi.push_back(&paypal);
    metodi.push_back(&contanti);

    for (int i = 0; i < metodi.size(); i++) {
        metodi[i]->pagaConCommissione(100, 2);
    }

    return 0;
}
esercizio4.cpp
cpp


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Notifica {
public:
    virtual void invia(string messaggio) = 0;
};

class NotificaEmail : public Notifica {
public:
    void invia(string messaggio) {
        cout << "Email: " << messaggio << "\n";
    }
};

class NotificaSMS : public Notifica {
public:
    void invia(string messaggio) {
        cout << "SMS: " << messaggio << "\n";
    }
};

class NotificaPush : public Notifica {
public:
    void invia(string messaggio) {
        cout << "Push: " << messaggio << "\n";
    }
};

class GestoreNotifiche {
private:
    vector<Notifica*> canali;

public:
    void aggiungi(Notifica* n) {
        canali.push_back(n);
    }

    void inviaATutti(string messaggio) {
        for (int i = 0; i < canali.size(); i++) {
            canali[i]->invia(messaggio);
        }
    }
};
