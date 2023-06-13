//
// Created by tnovaira on 18/5/2023.
//

#include "jugador.h"
#include "tablero.h"
#include "barco.h"
#include <iostream>
using namespace std;


void usuario::ubicarbarco(int repetidor) { //ubica barco de jgadores. si repetidor es 0, es el primer jugador, si repetidor es 1 es el segundo jugador.
    int x1, y1,r;
    int cont = 0;
    bool error, ubicado;
    //auto *b = new barco[7];

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
            tj->mostrarTablero();

        } while (!ubicado);
    }

    cout<< "--------------------"<<endl;
    cout<< "TABLERO FINAL: "<<endl;
    tj->mostrarTablero();

    //delete[] b;
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

void cpu::randatacar(tablero* tj){ //funcion random para generar ataques de CPU
    int f,c;
    //srand(time(nullptr));

    cout<< "-ATACA CPU-"<<endl;
    int limitex=tc.getfil();
    int limitey=tc.getcol();
    //coordenadas random de disparos
    f = rand() % (limitex);
    c = rand() % (limitey);


    tj->disparo(0,0,f,c);
    tj->mostrarTablero(); //muestra tab de jugador, para ver donde le han pegado
}


void cpu::randubicbarco() { //funcion rand para ubicar barco de CPU

    //  srand(time(nullptr));
    int rep=0;
    tc.inmatriz();

    for (int i=7;i<14;i++){
        bool ubicado=false;
        while (!ubicado) {
            int fi = rand() % tc.getfil(); // numero random para fila.
            int co = rand() % tc.getcol();
            int po = rand() % 2; // num random para pos
            tc.posbarc(rep,i, po);
            ubicado = tc.verificado(rep,i, fi, co);
        }
    }

    cout<<"TABLERO CPU: "<<endl;
    tc.mostrarTablero(); //se muestra tab de CPU, solo para verificar si funciona. borrar.

}