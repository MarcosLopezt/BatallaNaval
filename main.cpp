#include <iostream>
#include "juego.h"


using namespace std;



int main() {
    juego batallanaval;
    srand(time(nullptr));

    cout<< "|----------------|"<<endl;
    cout<< "|  BATALLA NAVAL |"<<endl;
    cout<< "|----------------|"<<endl;
    batallanaval.start();


    return 0;



}