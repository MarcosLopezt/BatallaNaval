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
    barco()=default;
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

    int getdisp() const{
        return disp;
    }
    int getcas() const{
        return cas;
    }
    int getfil() const{
        return fil;
    }
    int getcol() const{
        return col;
    }
    int getpos() const{
        return pos;
    }







};


#endif //BATALLANAVAL_BARCO_H
