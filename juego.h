//
// Created by tnovaira on 18/5/2023.
//

#ifndef BATALLANAVAL_JUEGO_H
#define BATALLANAVAL_JUEGO_H
#include "jugador.h"
#include <iostream>

class juego {
    usuario j1;
    cpu c1;

public:
    juego(){};
    juego(usuario jugador1,cpu cpuObj){
        j1=jugador1;
        c1=cpuObj;
    }

    void start();

};


#endif //BATALLANAVAL_JUEGO_H
