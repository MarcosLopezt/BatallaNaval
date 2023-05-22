//
// Created by tnovaira on 18/5/2023.
//

#ifndef BATALLANAVAL_BARCO_H
#define BATALLANAVAL_BARCO_H


class barco {
    int fil;
    int col;
    int pos; //horizontal o vertical

public:
    barco(){};
    barco(int fila, int columna, int posicion){
        fil=fila;
        col=columna;
        pos=posicion;
    }

};


#endif //BATALLANAVAL_BARCO_H
