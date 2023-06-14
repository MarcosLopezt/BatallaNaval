//
// Created by tnovaira on 13/6/2023.
//

#ifndef BATALLANAVAL_USUARIO_H
#define BATALLANAVAL_USUARIO_H
#include "jugador.h"

class usuario:public jugador{
    //int cant=7; //cantidad de barcos.
    tablero* tj;
    //barco* bj;

public:
    usuario()=default;
    usuario(string nombre,tablero* tab, int cantidad):jugador(nombre,cantidad),tj(tab) {
        tj = tab;
    }

    void ubicarbarco(int repetidor);
    void atacar(tablero* tc,int rep);

};



#endif //BATALLANAVAL_USUARIO_H
