#include <iostream>
#include <chrono> 
#include "header4.h"
using namespace std;
/*
Ejecutar en consola:
g++ -o ej4/main4_ex ej4/main4.cpp ej4/funcs4.cpp
./ej4/main_ex
*/

int main(){
    //Defino los 2 mensajes a comparar con strings y char*
    string word1 = "Los mareados - Ryan: Siempre espera con toda Certeza Cruzárselo, encontrarlo Busca momentos donde nadie la ve Para llamarlo...";
    string word2 = "Los mareados - Ryan: Siempre espera con toda Certeza Cruzárselo, encontrarlo Busca momentos donde nadie la ve Para llamarlo...";
    const char* w1 = "Los mareados - Ryan: Siempre espera con toda Certeza Cruzárselo, encontrarlo Busca momentos donde nadie la ve Para llamarlo...";
    const char* w2 = "Los mareados - Ryan: Siempre espera con toda Certeza Cruzárselo, encontrarlo Busca momentos donde nadie la ve Para llamarlo...";

    //Mido los tiempos de ejecucion de ambos
    auto startTime1 = chrono::high_resolution_clock::now(); 
    bool result1= compare_words_str(word1,word2);
    auto endTime1 = chrono::high_resolution_clock::now(); 
    auto elapsedTime1 = chrono::duration_cast<std::chrono::nanoseconds>(endTime1 - startTime1); 
    cout<<"A comparar strings le tomó: "<<elapsedTime1.count()<<" nanosegundos - Resultado: "<<boolalpha<<result1<<endl; 

    auto startTime2 = chrono::high_resolution_clock::now(); 
    bool result2 = compare_words_char(w1,w2);
    auto endTime2 = chrono::high_resolution_clock::now(); 
    auto elapsedTime2 = chrono::duration_cast<std::chrono::nanoseconds>(endTime2 - startTime2); 
    cout<<"A comparar char* le tomó: "<<elapsedTime2.count()<<" nanosegundos - Resultado: "<<boolalpha<<result2<<endl;

    //Defino los mensajes a comparar usando constexpr
    constexpr const char* w11 = "Los mareados - Ryan: Siempre espera con toda Certeza Cruzárselo, encontrarlo Busca momentos donde nadie la ve Para llamarlo...";
    constexpr const char* w22 = "Los mareados - Ryan: Siempre espera con toda Certeza Cruzárselo, encontrarlo Busca momentos donde nadie la ve Para llamarlo...";
    //Mido el tiempo de ejecucion 
    auto startTime3 = chrono::high_resolution_clock::now(); 
    constexpr bool result3 = b_compare_words_char(w11,w22);
    auto endTime3 = chrono::high_resolution_clock::now(); 
    auto elapsedTime3 = chrono::duration_cast<std::chrono::nanoseconds>(endTime3 - startTime3); 
    cout<<"A comparar char* en compilacion le tomó: "<<elapsedTime3.count()<<" nanosegundos - Resultado: "<<boolalpha<<result3<<endl;
}

/*CONCLUSIONES:
En la primera parte del ejercicio, al comparar el tiempo que tarda en comparar el mismo texto para strings y para char*
Notamos que por amplia diferencia es mucho mas rapido comparar char* que strings. Esto se debe principalmente a que
char evita usar memoria dinamica, por lo que, por mas que pasemos el string por refencia y no por copia, usar char* sigue
siendo mas efectivo en cuanto a uso de recursos y tiempo. 
Luego, en el punto c, en el cual se nos pide ejecutar la comparacion usando constexpr para poder realizarla en tiempo de
compilacion y no tiempo de ejecucion. Para este item, adaptamos la funcion que comparar char* que ya sabemos que es la
mas eficiente de las dos anteriores. Al hacer esta nueva modificacion, notamos que el tiempo de ejecucion se reduce de manera
muy notoria nuevamente, puesto que la comparacion se realiza en el tiempo de compilacion, y cuando se ejecuta el programa,
este ya tiene el resultado listo. 
*/