//
// Created by tnovaira on 18/5/2023.
//

#ifndef BATALLANAVAL_BARCO_H
#define BATALLANAVAL_BARCO_H


class barco {
    int cas;
    int disp;
    int fil;
    int col;
    int pos; //horizontal(0) o vertical(1)

public:
    barco(){};
    barco(int casillas,int fila, int columna, int posicion, int disparos){
        cas=casillas;
        fil=fila;
        col=columna;
        pos=posicion;
        disp=disparos;
    }

    void setcas(int casillas){
        cas=casillas;
    }
    void setfil(int fila){
        fil=fila;
    }
    void setcol(int columna){
        col=columna;
    }
    void setpos(int posicion){
        pos=posicion;
    }
    void setdisp(int disparos){
        disp=disparos;
    }

    int getdisp(){
        return disp;
    }
    int getcas(){
        return cas;
    }
    int getfil(){
        return fil;
    }
    int getcol(){
        return col;
    }
    int getpos(){
        return pos;
    }







};


#endif //BATALLANAVAL_BARCO_H
