#include <iostream>
#include "juego.h"


using namespace std;



int main() {
    int r=0;
    juego batallanaval;
    srand(time(nullptr));

    do {
        cout << "|----------------|" << endl;
        cout << "|  BATALLA NAVAL |" << endl;
        cout << "|----------------|" << endl;
        cout << "MODO DE JUEGO: " << endl;
        cout << "[1]. Usuario vs CPU " << endl;
        cout << "[2]. 2 jugadores " << endl;
        cin >> r;

        if (r == 1) {
            batallanaval.start();
        } else if (r == 2) {
            batallanaval.start2();
        } else {
            r = 0;
        }

    }while(r==0);


    return 0;



}