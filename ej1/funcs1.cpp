#include "header1.h" 
#include <iostream>
using namespace std;
//TRY Y CATCH AL ASIGNAR MEMORIAAAAA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int** createMtx(int size){
    //La funcion crea una matriz de array of arrays en memoria dinamica
    //Creo mi array principal que va a contener las filas de la matriz
    int** mtx= new int*[size];
    //Creo las correspondientes filas de la matriz y las asigno a mi array principal
    for(int i=0; i<size; i++){
        mtx[i] = new int[size];
    }
    //Relleno la matriz con los valores correspondientes
    int val=1; //me guardo la variable que asigna el valor
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){ 
            mtx[i][j]=val; //voy recorriendo la matriz en orden creciente y asignado los valores
            val+=1;
        }
    }
    return mtx;
}
void printMtx(int** mtx, int size){
    /*La funcion requiere printear la matriz de atras para adelante
    Parametros: matriz int** (array of arrays) y tamaño de la misma
    Sabemos que la matriz es siempre cuadrada. 
    Logica del codigo: 
        Creo un indice regresivo para cada casilla de la matriz ==> i = (size*size)-1
        Sabiendo que la division entera trunca siempre el valor, podemos establecer que las filas
        siempre seran la division entera de mi indice por el tamaño de la matriz.
        A su vez, el resto de esta division (hacer modulo) sera el valor de la columna que se encuentra
        Luego, para cada indice, calculo su fila (row) y columna(col) y lo imprimo.
    */
    for(int i=(size*size)-1; i>=0; i--){
        int row = (i / size);
        int col = (i % size);
        cout<<"M["<<row<<"]["<<col<<"] = "<<mtx[row][col]<<endl;
    }
}