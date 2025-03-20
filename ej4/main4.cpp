#include <iostream>
#include <chrono> 
#include "header4.h"
using namespace std;


int main(){
    string word1 = "h";
    string word2 = "hola como estas";
    const char* w1 = "h";
    const char* w2 = "hola como estas";

    auto startTime1 = chrono::high_resolution_clock::now(); 
    bool result1= compare_words_str(word1,word2);
    auto endTime1 = chrono::high_resolution_clock::now(); 
    auto elapsedTime1 = chrono::duration_cast<std::chrono::nanoseconds>(endTime1 - startTime1); 
    cout<<"A comparar strings le tomó: "<<elapsedTime1.count()<<" nanosegundos - Resultado: "<<result1<<endl; 

    auto startTime2 = chrono::high_resolution_clock::now(); 
    bool result2 = compare_words_char(w1,w2);
    auto endTime2 = chrono::high_resolution_clock::now(); 
    auto elapsedTime2 = chrono::duration_cast<std::chrono::nanoseconds>(endTime2 - startTime2); 
    cout<<"A comparar char* le tomó: "<<elapsedTime2.count()<<" nanosegundos - Resultado: "<<result2<<endl;
}