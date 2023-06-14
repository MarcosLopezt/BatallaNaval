//
// Created by tnovaira on 13/6/2023.
//

#include "cpu.h"
#include <iostream>
using namespace std;

void cpu::randatacar(tablero* tj){ //funcion random para generar ataques de CPU
    int f,c;
    //srand(time(nullptr));

    cout<< "-ATACA CPU-"<<endl;
    int limitex=tc->getfil();
    int limitey=tc->getcol();
    //coordenadas random de disparos
    f = rand() % (limitex);
    c = rand() % (limitey);


    tj->disparo(0,0,f,c);
    tj->mostrarTablero(); //muestra tab de jugador, para ver donde le han pegado
}


void cpu::randubicbarco() { //funcion rand para ubicar barco de CPU

    //  srand(time(nullptr));
    int rep=0;
    tc->inmatriz();

    for (int i=7;i<14;i++){
        bool ubicado=false;
        while (!ubicado) {
            int fi = rand() % tc->getfil(); // numero random para fila.
            int co = rand() % tc->getcol();
            int po = rand() % 2; // num random para pos
            tc->posbarc(rep,i, po);
            ubicado = tc->verificado(rep,i, fi, co);
        }
    }

    cout<<"TABLERO CPU: "<<endl;
    tc->mostrarTablero(); //se muestra tab de CPU, solo para verificar si funciona. borrar.

}