#include "header3.h"

shared_ptr<node> create_node(int value, shared_ptr<node> next){
    //Creo un nodo con el valor asignado y devuelve un smart pointer al nodo
    shared_ptr<node> new_node = make_shared<node>();
    //Le asigno sus valores
    new_node->value = value;
    new_node->next = next;
    return new_node;
}  

shared_ptr<list> create_list(){
    //Crea una lista vacia y devuelve un smart pointer a la misma
    shared_ptr<list> new_list = make_shared<list>();
    new_list->head = nullptr;
    new_list->size = 0;
    return new_list;
}

void push_front(const shared_ptr<list>& list, int value){ 
    //Insertar un elemento en la cabeza de lista
    //Creo el nodo a insertar, le paso como parametro de next la cabeza actual de la lista
    shared_ptr<node> new_node = create_node(value, list->head);
    list->head = new_node; //Asigno la cabeza de lista al nuevo nodo
    list->size++;
}

void push_back(const shared_ptr<list>& list, int value){
    //Insertar un elemento al final de la lista
    //Creo el nuevo nodo con next = nullptr
    shared_ptr<node> new_node = create_node(value); 
    //Si la lista esta vacia, el nodo creado sera la cabeza e unico nodo de la misma
    if(!list->head) list->head = new_node;
    else{ 
        //Caso contrario, recorro la lista hasta al final, y le asigno al ultimo nodo el nuevo nodo
        shared_ptr<node> temp = list->head;
        while(temp->next) temp = temp->next; //Freno en el ultimo nodo
        temp->next = new_node; //conecto el ultimo nodo con mi nuevo final de lista
    }
    list->size++;
}

void insert(const shared_ptr<list>& list, int value, int pos){
    //Insetar un nodo en una posicion X en la lista
    //Si la posicion es mas grande que el tamaño de la lista lo inserto al final
    if(pos>list->size){
        cout<<"Posicion fuera de rango, se inserto al final de la lista"<<endl;
        push_back(list, value); //Reutilizo mi funcion previa
        return;
    }
    //Si la posicion es 0, lo inserto en la cabeza de la lista
    if(pos==0) {
        push_front(list, value); //Reutilizo mi funcion previa
        return;
    }
    //En cualquier otro caso, creo mi nuevo nodo
    shared_ptr<node> new_node = create_node(value);
    //Recorro la lista hasta frenarme una posicion antes de la que tiene que ir mi nuevo nodo
    shared_ptr<node> temp = list->head;
    for(int i=0; i<pos-1; i++) temp = temp->next;
    //Conecto a mi nuevo nodo el resto de la lista
    new_node->next = temp->next;
    //Conecto al previo a la posicion X requerida con mi nuevo nodo
    temp->next = new_node;
    list->size++; 
}

void erase(const shared_ptr<list>& list, int pos){
    //Eliminar un nodo en una posicion X en la lista
    //Si la lista estaba vacia no hay que eliminar nada
    if(!list->head){
        cout<<"La lista estaba vacia, no se elimino nada"<<endl;
        return;
    }
    //Si la poisicion esta fuera del rango de la lista, se tiene que eliminar el ultimo
    if(pos>=list->size){
        cout<<"Posicion fuera de rango, se elimino el ultimo nodo"<<endl;
        pos = list->size -1; //Reasigno la posicion a borrar directamente a la posicion del ultimo nodo
    }
    //Si la posicion es 0 tengo que borrar la cabeza de lista
    if(pos==0) list->head = list->head->next; //simplemente digo que la cabeza va a ser el proximo
    else{
        //Recorro la lista hasta frenarme uno antes de la posicion a borrar
        shared_ptr<node> temp = list->head;
        for(int i=0; i<pos-1; i++) temp = temp->next;
        //Si estoy borrando el ultimo nodo (temp->next->next == nullptr)
        //Entonces le asigno al nodo en el que me frene nullptr, y este pasa a ser el ultimo nodo
        if(!temp->next->next) temp->next = nullptr;
        //Caso contrario, simplemente le digo que el proximo del que me frene lo asigne al proximo del proximo
        else temp->next = temp->next->next;
    }
    list->size--;
}

void print_list(const shared_ptr<list>& list){
    //Imprime la lista
    //Recorro todo los nodos de la lista
    shared_ptr<node> temp = list->head;
    while(temp){
        cout<<temp->value; //Imprimo cada valor
        if(temp->next)cout<<"->"; //Si no estoy en el ultimo nodo, tmb imprimo el separador
        temp=temp->next;
    }
    cout<<endl;
}