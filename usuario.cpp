//
// Created by tnovaira on 13/6/2023.
//

#include "usuario.h"
#include <iostream>
using namespace std;


void usuario::ubicarbarco(int repetidor) { //ubica barco de jgadores. si repetidor es 0, es el primer jugador, si repetidor es 1 es el segundo jugador.
    int x1, y1,r;
    int cont = 0;
    bool error, ubicado;

    tj->inmatriz();
    tj->barc1(repetidor);

    for (int i = 1; i < 7; i++) {

        do {

            cout << "Ingrese ubicacion del barco " << i+1 <<endl;
            do {

                cout << "Fila: " << endl;
                cin >> x1;
                error = x1 < 0 || x1 >= tj->getcol();
                if (error) {
                    cout << "ERROR, la fila no puede ser mneor a 0, o mayor a " << tj->getcol() - 1 << " " << endl;
                }
            } while (error);

            do {
                cout << "Columna: " << endl;
                cin >> y1;
                error = y1 < 0 || y1 >= tj->getfil();
                if (error) {
                    cout << "ERROR, la columna no puede ser menor a 0, o mayor a " << tj->getfil() - 1 << " " << endl;
                }
            } while (error);

            do {
                cout << "Decida la orientacion: " << endl;
                cout << "0.Horiziontal. " << endl;
                cout << "1.Vertical.  " << endl;
                cin >> r;
                if (r == 0) {
                    tj->posbarc(repetidor,i,0);
                    cont=0;
                } else if (r == 1) {
                    tj->posbarc(repetidor,i,1); //posicion barco horiz o verti
                    cont=0;
                } else {
                    cont++; //cont para verificar la orientacion.
                }
            } while (cont > 0);

            ubicado=tj->verificado(repetidor,i,x1,y1);
            if(!ubicado){
                cout<< "SU BARCO ESTA MAL UBICADO. "<<endl;
                cout<<endl<<endl;
            }
            tj->mostrarTablero(); //muestra tab desp de ubicar el barco.

        } while (!ubicado);
    }

    cout<< "--------------------"<<endl;
    cout<< "TABLERO FINAL: "<<endl;
    tj->mostrarTablero();

}

void usuario::atacar(tablero* tc,int rep) { //funcion de ataque de jugadores. si repetidor es 0, es el primer jugador, si repetidor es 1 es el segundo jugador
    int f,c; //fila y  columna.
    bool afuera;

    cout<< "-ATAQUE-"<<endl;
    do {
        cout << "Ingrese las coordenadas donde desea disparar: " << endl;
        cout << "Fila: " << endl;
        cin >> f;
        cout << "Columna: " << endl;
        cin >> c;
        afuera=f<0 || f>tj->getfil() ||c<0 ||c>tj->getcol();
        if(afuera){
            cout<< "AFUERA,ingrese coordenadas dentro del tablero. "<<endl;
        }
    }while(afuera);

    tc->disparo(rep,1,f,c); //funcion de disparo.
    tc->mostrarTableroEn(); //muestra el tab del enemigo para ver resultados.

}