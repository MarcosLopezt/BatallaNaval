//
// Created by tnovaira on 6/6/2023.
//

#ifndef BATALLANAVAL_TABLERO_H
#define BATALLANAVAL_TABLERO_H
#include <iostream>
#include "barco.h"
using namespace std;

class tablero {

int fil;
int col;
barco* b= new barco[14];
int** tab;


public:
    tablero(){};
    tablero(int filas, int columnas){
        this->fil=filas;
        this->col=columnas;
        b=new barco[14];
        tab=new int* [fil];

        for(int i=0;i<fil;i++){
            tab[i]= new int[col];
        }
    }

    ~tablero(){
       //liberar memoria asignad
       for (int i=0;i<fil;i++){
           delete[]tab[i];
       }
       delete[]tab;
       delete[]b;
    }

    void setcol(int columnas){
        col=columnas;
    }
    void setfil(int filas){
        fil=filas;
    }

    int getcol(){
        return col;
    }
    int getfil() {
        return fil;
    }

    bool verificado(int index, int x, int y);
    void inmatriz();
    void mostrarTablero();
    void mostrarTableroEn();
    void initbarco();
    void posbarc(int index,int posi);
    void barc1();
    void disparo(int index,int x,int y);
    int hundido(int index,int x, int y);
    bool perdio();


};


#endif //BATALLANAVAL_TABLERO_H
