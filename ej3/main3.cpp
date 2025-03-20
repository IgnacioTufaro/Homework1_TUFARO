#include <iostream>
#include "header3.h"
using namespace std;

/*
Ejecutar en consola:
g++ -o ej3/main3_ex ej3/main3.cpp ej3/funcs3.cpp
valgrind --leak-check=full ./ej3/main3_ex
*/


int main(){
    cout<<"Comenzando tests: \n"<<endl;
    shared_ptr<list> lista = create_list();
    cout<<"lista creada con exito"<<endl;

    cout<<"Probando push_back con valores 4-5-6"<<endl;
    cout<<"Resultado esperado: 4->5->6\nTamaño esperado = 3"<<endl;
    push_back(lista,4);
    push_back(lista,5);
    push_back(lista,6);
    cout<<"Resultado obtenido: ";
    print_list(lista);
    cout<<"Tamaño de lista = "<<lista->size<<endl;

    cout<<"\nProbando Push_front con valores 3-2-1"<<endl;
    cout<<"Resultado esperado: 1->2->3->4->5->6\nTamaño esperado = 6"<<endl;
    push_front(lista,3);
    push_front(lista,2);
    push_front(lista,1);
    cout<<"Resultado obtenido: ";
    print_list(lista);
    cout<<"Tamaño de lista = "<<lista->size<<endl;

    cout<<"\nLas funciones push_front y push_back funcionan correctamente"<<endl;

    cout<<"\nProbando la funcion erase:"<<endl;

    cout<<"\nEliminando el primer elemento"<<endl;
    cout<<"Resultado esperado: 2->3->4->5->6\nTamaño esperado = 5"<<endl;
    erase(lista,0);
    cout<<"Resultado obtenido: ";
    print_list(lista);
    cout<<"Tamaño de lista = "<<lista->size<<endl;

    cout<<"\nEliminando el ultimo elemento"<<endl;
    cout<<"Resultado esperado 2->3->4->5\nTamaño esperado = 4"<<endl;
    erase(lista,4);
    cout<<"Resultado obtenido: ";
    print_list(lista);
    cout<<"Tamaño de list = "<<lista->size<<endl;

    cout<<"\nEliminando un elemento intermedio"<<endl;
    cout<<"Resultado esperado 2->3->5\nTamaño esperado = 3"<<endl;
    erase(lista,2);
    cout<<"Resultado obtenido: ";
    print_list(lista);
    cout<<"Tamaño de lista = "<<lista->size<<endl;
    
    cout<<"\nEliminanado nuevo elemento intermedio"<<endl;
    cout<<"Resultado esperado 2->5\nTamaño esperado = 2"<<endl;
    erase(lista,1);
    cout<<"Resultado obtenido: ";
    print_list(lista);
    cout<<"Tamaño de lista = "<<lista->size<<endl;

    cout<<"\nEliminando un elemento fuera de rango(elimina el ultimo)"<<endl;
    cout<<"Resultado esperado: 2\nTamaño esperado = 1"<<endl;
    erase(lista,10);
    cout<<"Resultado obtenido: ";
    print_list(lista);
    cout<<"Tamaño de lista = "<<lista->size<<endl;
    
    cout<<"\nElimino el ultimo elemento de la lista"<<endl;
    erase(lista,0);
    cout<<"Lista actual: ";
    print_list(lista);
    cout<<"Tamaño de lista = "<<lista->size<<endl;

    cout<<"\nProbando eliminar un elemento de una lista vacia"<<endl;
    erase(lista,0);
    cout<<"\nLa funcion erase funciona correctamente"<<endl;

    cout<<"\nProbando la funcion insert"<<endl;

    cout<<"\nInserto los valores 1-3-5 en las posiciones 0-1-2"<<endl;
    cout<<"Resultado esperado: 1->3->5\nTamaño espeado = 3"<<endl;
    insert(lista,1,0);
    insert(lista,3,1);
    insert(lista,5,2);
    cout<<"Resultado obtenido: ";
    print_list(lista);
    cout<<"Tamaño de lista = "<<lista->size<<endl;

    cout<<"\nInserto el valor 6 en una posicion fuera de rango (lo inserta al final)"<<endl;
    cout<<"Resultado esperado 1->3->5->6\nTamaño esperado = 4"<<endl;
    insert(lista,6,10);
    cout<<"Resultado obtenido: ";
    print_list(lista);
    cout<<"Tamaño de lista = "<<lista->size<<endl;

    cout<<"\nInserto valores entremedio - 2 en la posicion 1 y 4 en la posicion 3"<<endl;
    cout<<"Resultado esperado 1->2->3->4->5->6\nTamaño esperado = 6"<<endl;
    insert(lista,2,1);
    insert(lista,4,3);
    cout<<"Resultado obtenido: ";
    print_list(lista);
    cout<<"Tamaño de lista  = "<<lista->size<<endl;

    cout<<"\nLa funcion insert funciona correctamente"<<endl;
    cout<<"\nLa implementacion funciona correctamente"<<endl;
    return 0;
}

