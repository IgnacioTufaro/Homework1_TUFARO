#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<memory>
using namespace std;

//Defino mis estructuras
struct node{
    int value;
    shared_ptr<node> next;
};
struct list{
    shared_ptr<node> head;
    size_t size;
};

//Defino mis funciones
shared_ptr<node> create_node(int value, shared_ptr<node> next = nullptr);

shared_ptr<list> create_list();

void push_front(const shared_ptr<list>& list, int value);

void push_back(const shared_ptr<list>& list, int value);

void insert(const shared_ptr<list>& list, int value, int pos);

void erase(const shared_ptr<list>& list, int pos);

void print_list(const shared_ptr<list>& list);

#endif