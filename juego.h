//
// Created by tnovaira on 18/5/2023.
//

#ifndef BATALLANAVAL_JUEGO_H
#define BATALLANAVAL_JUEGO_H
#include "jugador.h"
#include "usuario.h"
#include "cpu.h"
#include <iostream>

class juego {
    usuario j1;
    usuario j2;
    cpu c1;

public:
    juego(){};
    juego(usuario jugador1,cpu cpuObj, usuario jugador2){
        j1=jugador1;
        c1=cpuObj;
        j2=jugador2;
    }

    void start();
    void start2();


};


#endif //BATALLANAVAL_JUEGO_H
