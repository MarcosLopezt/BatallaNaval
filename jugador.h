//
// Created by tnovaira on 18/5/2023.
//

#ifndef BATALLANAVAL_JUGADOR_H
#define BATALLANAVAL_JUGADOR_H
#include <iostream>
using namespace std;

class jugador {
    string nom;

public:
    jugador(){};
    jugador(string nombre){
        nom=nombre;
    }

};

class usuario:public jugador{
    

};


#endif //BATALLANAVAL_JUGADOR_H
