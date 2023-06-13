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
    jugador(){};
    jugador(string nombre){
        nom=nombre;
    }

    void setnom(string nombre){
        nom=nombre;
    }

    string getnom(){
        return nom;
    }

};

class usuario:public jugador{
    int cant=7; //cantidad de barcos.
    tablero tj;
    barco* bj;

public:
    usuario(){}
    usuario(string nombre,tablero& tab, int cantidad):jugador(nombre),cant(cantidad),tj(tab){
        cant=cantidad;
        tj=tab;
        bj= new barco[cant];
    }

    ~usuario(){
        delete[]bj;
    }

    void setbj(int indice, int fila,int colu){ //set coord barco jugador
        if(indice>=0 && indice<cant){
            bj[indice].setfil(fila);
            bj[indice].setcol(colu);
        }
    }

    int getbcF(int indice){ // get filas de barco
        if(indice>=0 && indice < cant){
            return bj[indice].getfil();
        }
    }

    int getbcC(int indice){ // get colum de barco
        if(indice>=0 && indice < cant){
            return bj[indice].getcol();
        }
    }

    void settj(tablero& tab){
        tj=tab;
    }

    void ubicarbarco();
    void atacar(tablero* tc);

};

class cpu:public jugador{
    int cant=7;
    barco* bc=new barco[7];
    tablero tc;

public:
    cpu(){};
    cpu(string nombre,tablero tab, int cantida):jugador(nombre),cant(cantida),tc(tab){
        cant=cantida;
        tc=tab;
        bc=new barco[cant];
    }

    ~cpu(){
        delete []bc;
    }

    void setbc(int indice, int filaa,int colu){ //set coordenadas de barco
        if(indice>=0 && indice<cant){
            bc[indice].setfil(filaa);
            bc[indice].setcol(colu);
        }
    }

    int getbcF(int indice){ // get filas de barco
        if(indice>=0 && indice < cant){
            return bc[indice].getfil();
        }
    }

    int getbcC(int indice){ // get colum de barco
        if(indice>=0 && indice < cant){
            return bc[indice].getcol();
        }
    }

    void settc(tablero tab){
        tc=tab;
    }


    void randubicbarco();
    void randatacar(tablero* tj);


};


#endif //BATALLANAVAL_JUGADOR_H
