//
// Created by tnovaira on 18/5/2023.
//

#ifndef BATALLANAVAL_JUGADOR_H
#define BATALLANAVAL_JUGADOR_H
#include <iostream>
#include "barco.h"
#include "tablero.h"
using namespace std;

class jugador {
    string nom;
    barco* b;
    int cant=7;

public:
    jugador()=default;
    jugador(string& nombre, int cantidad){
        nom=nombre;
        cant=cantidad;
        b= new barco[cant];
    }

    ~jugador(){
        delete[]b;
    }

    void setnom(string& nombre){
        nom=nombre;
    }

    string getnom(){
        return nom;
    }

};




#endif //BATALLANAVAL_JUGADOR_H
