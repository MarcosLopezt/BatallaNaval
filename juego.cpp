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
    int n,r,continuar;
    string p;
    barco b;

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
    b.mostrarbarcos();
    cout<< "PRESIONE CUALQUIER NUMERO PARA CONTINUAR A UBICARLOS"<<endl;
    cin>>continuar;
    cout<<endl;
    u.ubicarbarco(0);
    cout<<endl<<endl;
    cout<< "CPU ubica sus barcos. "<<endl;
    c.randubicbarco();
    cout<<endl<<endl<<endl<<endl<<endl;

    string x;
    while(true) {
        cout<< "PRESIONE CUALQUIER NUMERO PARA CONTINUAR: "<<endl;
        cin>>continuar;

        u.atacar(&te,0);
        if(te.perdio()){
            cout<< "HAS HUNDIDO TODOS LOS BARCOS. "<<endl;
            cout<< "GANASTE"<<endl;
            break;
        }

        cout<< "PRESIONE CUALQUIER NUMERO PARA CONTINUAR: "<<endl;
        cin>>continuar;
        cout<<endl<<endl<<endl<<endl<<endl;

        c.randatacar(&t);
        if(t.perdio()){
            cout<< "TE HAN HUNDIDO TODOS LOS BARCOS. "<<endl;
            cout<< "PERDISTE"<<endl;
            break;
        }

        cout<< "Resultados del ataque de CPU "<<endl;
        cout<<endl;
    }
}

void juego::start2() { //juego con dos jugadores
    int n,r,s=0,continuar;
    barco b;
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
    b.mostrarbarcos();
    cout<< "PRESIONE CUALQUIER NUMERO PARA CONTINUAR A UBICARLOS"<<endl;
    cin>>continuar;
    cout<<endl;
    cout<< "---------------"<<endl;
    cout<< "JUGADOR 1: "<<u.getnom()<<endl;
    u.ubicarbarco(0);
    cout<< "---------------"<<endl;
    cout<< "JUGADOR 2: "<<u2.getnom()<<endl;
    u2.ubicarbarco(1);

    string x;
    while(true) {
        cout<< "PRESIONE CUALQUIER NUMERO PARA CONTINUAR: "<<endl;
        cin>>continuar;
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<< "TURNO JUGADOR 1: "<<u.getnom()<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"| "<<u2.getnom()<< " NO MIRES |"<<endl;
        cout<<"-----------------------"<<endl;
        do {
            s=1;
            cout << "YA SE FUE " << u2.getnom() << " ? " << endl;
            cout << "[1].SI " << endl;
            cout << "[2].NO " << endl;
            cin>>s;
            if(s==2){
                cout<< "Por favor "<<u2.getnom()<< " vayase, NO ES SU TURNO. "<<endl;
                cout<<endl;
            }
        }while(s!=1);
        cout<< "Tablero de "<<u.getnom()<< " : "<<endl;
        t.mostrarTablero();
        cout<< "PRESIONE CUALQUIER NUMERO PARA CONTINUAR: "<<endl;
        cin>>continuar;
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<< "TABLERO ENEMIGO: "<<endl;
        te.mostrarTableroEn();
        cout<< "ATACA JUGADROR 1: "<<u.getnom()<<endl;
        u.atacar(&te,0);
        if(te.perdio()){
            cout<< "|----------------"<<endl;
            cout<< "|GANO "<<u.getnom()<<"!!!!!"<<endl;
            cout<< "|----------------"<<endl;
            break;
        }
        cout<< "PRESIONE CUALQUIER NUMERO PARA CONTINUAR: "<<endl;
        cin>>continuar;
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<< "TURNO JUGADOR 2: "<<u2.getnom()<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"| "<<u.getnom()<< " NO MIRES |"<<endl;
        cout<<"-----------------------"<<endl;
        do {
            s=1;
            cout << "YA SE FUE " << u.getnom() << " ? " << endl;
            cout << "[1].SI " << endl;
            cout << "[2].NO " << endl;
            cin>>s;
            if(s==2){
                cout<< "Por favor "<<u.getnom()<< ", vayase, NO ES SU TURNO. "<<endl;
                cout<<endl;
            }
        }while(s!=1);
        cout<< "Tablero de "<<u2.getnom()<< " : "<<endl;
        te.mostrarTablero();
        cout<< "PRESIONE CUALQUIER NUMERO PARA CONTINUAR: "<<endl;
        cin>>continuar;
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<< "TABLERO ENEMIGO: "<<endl;
        t.mostrarTableroEn();
        cout<< "ATACA JUGADOR 2: "<<u2.getnom()<<endl;
        u2.atacar(&t,1);
        if(t.perdio()){
            cout<< "|----------------"<<endl;
            cout<< "|GANO "<<u2.getnom()<<"!!!!!"<<endl;
            cout<< "|----------------"<<endl;
            break;
        }
    }
}
