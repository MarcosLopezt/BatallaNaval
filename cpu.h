//
// Created by tnovaira on 13/6/2023.
//

#ifndef BATALLANAVAL_CPU_H
#define BATALLANAVAL_CPU_H
#include "jugador.h"

class cpu : public jugador {
    tablero* tc;

public:
    cpu() = default;
    cpu(string nombre,tablero* tab, int cantidad):jugador(nombre,cantidad),tc(tab){
        tc=tab;
    }

    void randubicbarco();
    void randatacar(tablero* tj);


};



#endif //BATALLANAVAL_CPU_H
