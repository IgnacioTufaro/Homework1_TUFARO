#include <iostream>
#include <chrono> 
#include "header4.h"
using namespace std;


int main(){
    string word1 = "Siempre espera con toda Certeza Cruzárselo, encontrarlo Busca momentos donde nadie la ve Para llamarlo";
    string word2 = "Siempre espera con toda Certeza Cruzárselo, encontrarlo Busca momentos donde nadie la ve Para llamarlo";
    const char* w1 = "Siempre espera con toda Certeza Cruzárselo, encontrarlo Busca momentos donde nadie la ve Para llamarlo";
    const char* w2 = "Siempre espera con toda Certeza Cruzárselo, encontrarlo Busca momentos donde nadie la ve Para llamarlo";

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

    constexpr const char* w11 = "Siempre espera con toda Certeza Cruzárselo, encontrarlo Busca momentos donde nadie la ve Para llamarlo";
    constexpr const char* w22 = "Siempre espera con toda Certeza Cruzárselo, encontrarlo Busca momentos donde nadie la ve Para llamarlo";

    auto startTime3 = chrono::high_resolution_clock::now(); 
    constexpr bool result3 = b_compare_words_char(w11,w22);
    auto endTime3 = chrono::high_resolution_clock::now(); 
    auto elapsedTime3 = chrono::duration_cast<std::chrono::nanoseconds>(endTime3 - startTime3); 
    cout<<"A comparar char* en compilacion le tomó: "<<elapsedTime3.count()<<" nanosegundos - Resultado: "<<result3<<endl;

}