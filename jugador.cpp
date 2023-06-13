//
// Created by tnovaira on 18/5/2023.
//

#include "jugador.h"
#include "tablero.h"
#include "barco.h"
#include <iostream>
using namespace std;


void usuario::ubicarbarco() {
    int x1, y1,r;
    int cont = 0;
    bool error, ubicado;
    //auto *b = new barco[7];

    tj.inmatriz();
    tj.barc1();

    for (int i = 1; i < 7; i++) {

        do {

            cout << "Ingrese ubicacion del barco " << i+1 <<endl;
            do {

                cout << "Fila: " << endl;
                cin >> x1;
                error = x1 < 0 || x1 >= tj.getcol();
                if (error) {
                    cout << "ERROR, la fila no puede ser mneor a 0, o mayor a " << tj.getcol() - 1 << " " << endl;
                }
            } while (error);

            do {
                cout << "Columna: " << endl;
                cin >> y1;
                error = y1 < 0 || y1 >= tj.getfil();
                if (error) {
                    cout << "ERROR, la columna no puede ser menor a 0, o mayor a " << tj.getfil() - 1 << " " << endl;
                }
            } while (error);

            do {
                cout << "Decida la orientacion: " << endl;
                cout << "0.Horiziontal. " << endl;
                cout << "1.Vertical.  " << endl;
                cin >> r;
                if (r == 0) {
                    tj.posbarc(i,0);
                    cont=0;
                } else if (r == 1) {
                    tj.posbarc(i,1); //posicion barco horiz o verti
                    cont=0;
                } else {
                    cont++;
                }
            } while (cont > 0);

            ubicado=tj.verificado(i,x1,y1);
            if(!ubicado){
                cout<< "SU BARCO ESTA MAL UBICADO. "<<endl;
                cout<<endl<<endl;
            }
            tj.mostrarTablero();

        } while (!ubicado);
    }

    cout<< "--------------------"<<endl;
    cout<< "TABLERO FINAL: "<<endl;
    tj.mostrarTablero();

    //delete[] b;
}

void usuario::atacar(tablero* tc) {
    int f,c;
    bool afuera;

    cout<< "-ATAQUE-"<<endl;
    do {
        cout << "Ingrese las coordenadas donde desea disparar: " << endl;
        cout << "Fila: " << endl;
        cin >> f;
        cout << "Columna: " << endl;
        cin >> c;
        afuera=f<0 || f>tj.getfil() ||c<0 ||c>tj.getcol();
        if(afuera){
            cout<< "AFUERA,ingrese coordenadas dentro del tablero. "<<endl;
        }
    }while(afuera);

    tc->disparo(1,f,c);
    tc->mostrarTableroEn();

}

void cpu::randatacar(tablero* tj){
    int f,c;
    srand(time(nullptr));

    cout<< "-ATACA CPU-"<<endl;

    //coordenadas random de disparos
    f = rand() % (tc.getfil() + 1);
    c = rand() % (tc.getcol() + 1);

    tj->disparo(0,f,c);
    tj->mostrarTablero();
}


void cpu::randubicbarco() {

    srand(time(nullptr));

    tc.inmatriz();

    for (int i=7;i<14;i++){
        bool ubicado=false;
        while (!ubicado) {
            int fi = rand() % tc.getfil(); // numero random para fila.
            int co = rand() % tc.getcol();
            int po = rand() % 2; // num random para pos
            tc.posbarc(i, po);
            ubicado = tc.verificado(i, fi, co);
        }
    }

    cout<<"TABLERO CPU: "<<endl;
    tc.mostrarTablero();

}