#include <iostream>
#include "header1.h"
using namespace std;
/*
Ejecutar en consola:
g++ -o ej1/main_ex ej1/main1.cpp ej1/funcs1.cpp
./ej1/main_ex
*/

int main(){
    //Le pido al usuario que ingrese el tamaño de la matriz
    int size;
    cout<<"Indice el tamaño de su matriz cuadrada: ";
    cin>>size;

    //Verifico que se haya pasado un valor correcto:
    if(cin.fail() || size<1){
        cerr<<"Error, se detuvo la ejecucion porque se ingreso un parametro invalido"<<endl;
        return 1;
    }

    //Llamo a mi funcion para crear la matriz
    int** mtx = createMtx(size);
    //Llamo a la funcion para imprimir la matriz
    printMtx(mtx,size);

    //Como estoy usando memoria dinamica, me aseguro de liberarla antes de terminar el codigo
    for(int i=0; i<size; i++) delete[] mtx[i];
    delete[] mtx;
    return 0;
}