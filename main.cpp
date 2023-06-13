#include <iostream>
#include "juego.h"

using namespace std;

int main() {
    int rta=0;
    juego batallanaval;
    srand(time(nullptr)); //se inicializa semilla random para la ubic de barcos.

    do {
        cout << "|----------------|" << endl;
        cout << "|  BATALLA NAVAL |" << endl;
        cout << "|----------------|" << endl;
        cout << "MODO DE JUEGO: " << endl;
        cout << "[1]. Usuario vs CPU " << endl;
        cout << "[2]. 2 jugadores " << endl;
        cin >> rta;

        if (rta == 1) {
            batallanaval.start();
        } else if (rta == 2) {
            batallanaval.start2();
        } else {
            rta = 0;
        }

    }while(rta==0);

    return 0;

}