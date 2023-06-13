//
// Created by tnovaira on 18/5/2023.
//

#include "juego.h"
#include "jugador.h"
#include "tablero.h"
#include <iostream>
using namespace std;

void juego::start() {
    int n,r;
    string p;


    //tablero t(9, 9);
    //tablero te(9, 9); //tab enemigo

    cout<< "JUGADOR 1: "<<endl;
    cout<< "Nombre: "<<endl;
    cin>>p;

    cout << "Elegir el tamanio del tablero (minimo 9x9)" << endl;
    do {
        cout << "Filas: " << endl;
        cin >> n;
        if (n < 9) {
            cout << "Minimo tiene que tener 9 filas. " << endl;
            cout << endl;
        }
    } while (n < 9);
    do {
        cout << "Columnas: " << endl;
        cin >> r;
        if (r < 9) {
            cout << "Minimo tiene que tener 9 columnas. " << endl;
            cout << endl;
        }
    } while (r < 9);

    tablero t(n,r);
    tablero te(n,r);

    usuario u(p, t, 7);
    cpu c("cpu", te, 7);
    t.initbarco();
    te.initbarco();
    u.ubicarbarco();
    c.randubicbarco();

    string x;
    while(true) {
        u.atacar(&te);
        if(te.perdio()){
            cout<< "HAS HUNDIDO TODOS LOS BARCOS. "<<endl;
            cout<< "GANASTE"<<endl;
            break;
        }
        c.randatacar(&t);
        if(t.perdio()){
            cout<< "TE HAN HUNDIDO TODOS LOS BARCOS. "<<endl;
            cout<< "PERDISTE"<<endl;
            break;
        }
    }
}
