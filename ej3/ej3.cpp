#include <iostream>
#include <memory>
using namespace std;

struct node{
    int value;
    shared_ptr<node> next;
};
struct list{
    shared_ptr<node> head;
    size_t size;
};

shared_ptr<node> create_node(int value, shared_ptr<node> next = nullptr){
    shared_ptr<node> new_node = make_shared<node>();
    new_node->value = value;
    new_node->next = next;
    return new_node;
}  

shared_ptr<list> create_list(){
    shared_ptr<list> new_list = make_shared<list>();
    new_list->head = nullptr;
    new_list->size = 0;
    return new_list;
}

void push_front(const shared_ptr<list>& list, int value){ 
    shared_ptr<node> new_node = create_node(value, list->head);
    list->head = new_node;
    list->size++;
}

void push_back(const shared_ptr<list>& list, int value){
    shared_ptr<node> new_node = create_node(value);
    if(!list->head) list->head = new_node;
    else{
        shared_ptr<node> temp = list->head;
        while(temp->next) temp = temp->next;
        temp->next = new_node;
    }
    list->size++;
}

void insert(const shared_ptr<list>& list, int value, int pos){
    if(pos>list->size){
        cout<<"Posicion fuera de rango, se inserto al final de la lista"<<endl;
        push_back(list, value);
        return;
    }
    if(pos==0) {
        push_front(list, value); 
        return;
    }
    shared_ptr<node> new_node = create_node(value);
    shared_ptr<node> temp = list->head;
    for(int i=0; i<pos-1; i++) temp = temp->next;
    new_node->next = temp->next;
    temp->next = new_node;
    list->size++; 
}

void erase(const shared_ptr<list>& list, int pos){
    if(!list->head){
        cout<<"La lista estaba vacia, no se elimino nada"<<endl;
        return;
    }
    if(pos>=list->size){
        cout<<"Posicion fuera de rango, se elimino el ultimo nodo"<<endl;
        pos = list->size -1;
    }
    if(pos==0) list->head = list->head->next;
    else{
        shared_ptr<node> temp = list->head;
        for(int i=0; i<pos-1; i++) temp = temp->next;
        if(!temp->next->next) temp->next = nullptr;
        else temp->next = temp->next->next;
    }
    list->size--;
}

void print_list(const shared_ptr<list>& list){
    shared_ptr<node> temp = list->head;
    while(temp){
        cout<<temp->value;
        if(temp->next)cout<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
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

    cout<<"\nProbando la funcion erase"<<endl;

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
    cout<<"La funcion erase funciona correctamente"<<endl;

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

    cout<<"La funcion insert funciona correctamente"<<endl;
    cout<<"La implementacion funciona correctamente"<<endl;
    return 0;
}

