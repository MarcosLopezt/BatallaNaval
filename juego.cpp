//
// Created by tnovaira on 18/5/2023.
//

#include "juego.h"
#include "jugador.h"
#include "tablero.h"
#include "usuario.h"
#include "cpu.h"
#include <iostream>
using namespace std;

void juego::start() { //juego vs CPU
    int n,r;
    string p;

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

    tablero t(n,r); //tablero del jugador;
    tablero te(n,r); //tab del cpu;

    usuario u(p, &t, 7);
    cpu c("cpu", &te, 7);
    t.initbarco();
    te.initbarco();
    u.ubicarbarco(0);
    c.randubicbarco();

    string x;
    while(true) {
        u.atacar(&te,0);
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

void juego::start2() { //juego con dos jugadores
    int n,r;
    string p;
    string p2;

    cout<< "JUGADOR 1: "<<endl;
    cout<< "Nombre: "<<endl;
    cin>>p;

    cout<< "JUGADOR 2: "<<endl;
    cout<< "Nombre: "<<endl;
    cin>>p2;

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
    tablero te(n,r); //tab jugador 2

    usuario u(p, &t, 7);
    usuario u2(p2, &te, 7);
    t.initbarco();
    te.initbarco();
    cout<< "-----------"<<endl;
    cout<< "JUGADOR 1: "<<u.getnom()<<endl;
    u.ubicarbarco(0);
    cout<< "-----------"<<endl;
    cout<< "JUGADOR 2: "<<u2.getnom()<<endl;
    u2.ubicarbarco(1);

    string x;
    while(true) {
        cout<< "ATACA JUGADOR 1: "<<u.getnom()<<endl;
        cout<< "Tablero de "<<u.getnom()<< " : "<<endl;
        t.mostrarTablero();
        u.atacar(&te,0);
        if(te.perdio()){
            cout<< "GANO "<<p<<endl;
            break;
        }
        cout<< "ATACA JUGADOR 2: "<<u2.getnom()<<endl;
        cout<< "Tablero de "<<u2.getnom()<< " : "<<endl;
        te.mostrarTablero();
        u2.atacar(&t,1);
        if(t.perdio()){
            cout<< "GANO "<<p2<<endl;
            break;
        }
    }
}
