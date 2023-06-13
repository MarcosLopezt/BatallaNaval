//
// Created by tnovaira on 6/6/2023.
//

#include "tablero.h"
#include "barco.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void tablero::initbarco() {
    b[0].setcas(1);
    b[1].setcas(2);
    b[2].setcas(2);
    b[3].setcas(3);
    b[4].setcas(3);
    b[5].setcas(3);
    b[6].setcas(4);
    //barcos cpu:
    b[7].setcas(1);
    b[8].setcas(2);
    b[9].setcas(2);
    b[10].setcas(3);
    b[11].setcas(3);
    b[12].setcas(3);
    b[13].setcas(4);

    for(int i=0;i<14;i++){
        b[i].setdisp(0);
    }


}


void tablero::posbarc(int index,int posi) { //para poder guardar la posicion del barco.
    b[index].setpos(posi);
}


void tablero::inmatriz()  { //ponemos los valores del tablero en 0;
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            tab[i][j]=0;
        }
    }
}

void tablero::mostrarTablero() {
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            if(tab[i][j]==0 || tab[i][j]==3){
                cout<<" 0 ";
            }

            if(tab[i][j]==1){
                cout<< " 1 ";
            }

            if(tab[i][j]==2){
                cout<< " # ";
            }

        }
        cout << endl;
    }
    cout<<"---------------"<<endl;
}

void tablero::mostrarTableroEn() {
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            if(tab[i][j]==0){
                cout<< " 0 ";
            }

            if(tab[i][j]==1){
                cout<< " 0 ";
            }

            if(tab[i][j]==2){
                cout<< " # ";
            }

            if(tab[i][j]==3){
                cout<< " A ";
            }
        }
        cout << endl;
    }
    cout<<"--------------"<<endl;

}



void tablero::barc1() { //ubicar barco 1, que no puede ser vertical u horizontal.
    int c,f,cont3;

    cout<< "--------------------"<<endl;
    cout<< "UBICACION DE BARCOS."<<endl;
    cout<< "--------------------"<<endl;

    do {
        cout << "Ingrese la coordenada (ej: A1) del barco de 1 casilla: " << endl;
        cout << "Fila: " << endl;
        cin >> f;
        cout << "Columna: " << endl;
        cin >> c;
        if(f>=fil||c>=col){
            cout<< "ERROR. el tablero es mas pequenio. "<<endl;
            cont3=1;
        }else if (f<fil && c<col){
            tab[f][c]=1;
            cont3=0;
        }
    }while(cont3==1); // valida si las coord ingresadas entran en el tabblero.


}




bool tablero::verificado(int index, int x, int y) { //verifica la ubicacion del barco y lo inserta en el tablero
    if((b[index].getpos()==1) && (x+b[index].getcas()>fil)){ //verifica si el largo del barco se va del tablero
        return false;
    }
    if((b[index].getpos()==0) && (y+b[index].getcas()>col)){ //si se va del tablero devuelve false
        return false;
    }

    for (int i=0;i<b[index].getcas();i++){
        if(b[index].getpos()==1){
            if(tab[x+i][y]==1) {
                return false; // si hay barco devuelve false
            }
        }else{
            if(b[index].getpos()==0){
                if(tab[x][y+i]==1){
                    return false;
                }
            }
        }
    }

    for (int i=0;i<b[index].getcas();i++) { //inserta barco
        if (b[index].getpos() == 1) {
            tab[x + i][y] = 1;
        } else if(b[index].getpos()==0){
                tab[x][y + i] = 1;

        }

        b[index].setfil(x); //guarda en el barco sus coordenadas.
        b[index].setcol(y);

    }


    return true;
}

void tablero::disparo(int index,int x, int y) {
int x1=x;
int y1=y;
int ind=index;

    if(tab[x][y]==0 || tab[x][y]==3){
        cout<< "------"<<endl;
        cout<< " AGUA "<<endl;
        tab[x][y]=3;
    }else if(tab[x][y]==1 || tab[x][y]==2){
        cout<< "------"<<endl;
        cout<< " HIT "<<endl;
        tab[x][y]=2;
        if(hundido(ind,x1,y1)==1){
            cout<< "---------"<<endl;
            cout<< " HUNDIDO "<<endl;
            cout<< "---------"<<endl;
        }
    }


}

int tablero::hundido(int index,int x, int y) {
int resultado=0,cont,final;
if(index==0){
    cont=7;
    final=14;
}else{
    cont=0;
    final=7;
}
    for(int i=cont;i<final;i++) {
        int barcoX = b[i].getfil();
        int barcoY = b[i].getcol();
        int casillas = b[i].getcas();
        int orientacion = b[i].getpos();
        int disp = b[i].getdisp();

        if(casillas==1){
            if(x==barcoX && y==barcoY){
                cout<< " Se DISPARO a un barco de 1 casilla. "<<endl;
                resultado=1;
                break;
            }
        }

        if(orientacion==1) {
            if (x >= barcoX && x <= barcoX + casillas && y == barcoY) { //recorre las casillas del barco de manera vertical
                disp++;
                b[i].setdisp(disp);
                cout<< "Se DISPARO a un barco de "<<casillas<< " casillas"<<endl;
                if(disp==casillas){
                    resultado=1;
                    break; //se hunde el barco porque tiene igual cantidad de disparos recibidos que de casillas.
                }
                break;
            }

        } else {
            if (x == barcoX && y >= barcoY && y <= barcoY + casillas) { //recorre las casillas del barco de manera horizontal
                disp++;
                b[i].setdisp(disp);
                cout<< "Se DISPARO a un barco de "<<casillas<< " casillas"<<endl;
                if (disp == casillas) {
                    resultado=1;
                    break; //sale una vez que se hunde barco
                }
                break;
            }
        }

    }

    return resultado;
}

bool tablero::perdio() {
    int cont=0;
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            if(tab[i][j]==1){ //si hay algun barco en el tablero no perdio.
                cont=1;
                break;
            }
        }
    }

   if(cont==0){
       return true;
   }else{
       return false;
   }

}


