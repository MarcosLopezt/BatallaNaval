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

public:
    jugador()=default;
    explicit jugador(string& nombre){
        nom=nombre;
    }

    void setnom(string& nombre){
        nom=nombre;
    }

    string getnom(){
        return nom;
    }

};

class usuario:public jugador{
    int cant=7; //cantidad de barcos.
    tablero tj;
    const barco* bj;

public:
    usuario()=default;
    usuario(string nombre,tablero& tab, int cantidad):jugador(nombre),cant(cantidad),tj(tab){
        cant=cantidad;
        tj=tab;
        bj=new barco[cant];
    }

    ~usuario(){
        delete[]bj;
    }


    void ubicarbarco();
    void atacar(tablero* tc);

};

class cpu : public jugador {
    int cant = 7;
    barco* bc;
    tablero tc;

public:
    cpu() = default;
    cpu(string nombre, const tablero& tab, int cantida)
            : jugador(nombre), cant(cantida), tc(tab), bc(new barco[cant]) {}

    ~cpu() {
        delete[] bc;
    }





    void randubicbarco();
    void randatacar(tablero* tj);


};


#endif //BATALLANAVAL_JUGADOR_H
