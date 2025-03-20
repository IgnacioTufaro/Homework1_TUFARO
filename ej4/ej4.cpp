#include <iostream>
#include <chrono> 
using namespace std;

bool compare_words_str(const string word1,const string word2, int idx=0){
    if(word1.length() != word2.length()) return false;
    if(word1[idx] != word2[idx]) return false;

    if(idx == word1.length()) return true;

    return compare_words_str(word1, word2, idx+1);
}

bool compare_words_char(const char* word1, const char* word2, int idx=0){
    if(word1[idx]=='\0' && word2[idx]=='\0') return true;

    if(word1[idx] != word2[idx]) return false;
    
    return compare_words_char(word1, word2, idx+1);
}


int main(){
    string word1 = "hola como estas";
    string word2 = "hola como estas";
    const char* w1 = "hola como estas";
    const char* w2 = "hola como estas";

    auto startTime1 = chrono::high_resolution_clock::now(); 
    compare_words_str(word1,word2);
    auto endTime1 = chrono::high_resolution_clock::now(); 
    auto elapsedTime1 = chrono::duration_cast<std::chrono::nanoseconds>(endTime1 - startTime1); 
    cout<<"A comparar strings le tomó: "<<elapsedTime1.count()<<" nanosegundos"<<endl; 

    auto startTime2 = chrono::high_resolution_clock::now(); 
    compare_words_char(w1,w2);
    auto endTime2 = chrono::high_resolution_clock::now(); 
    auto elapsedTime2 = chrono::duration_cast<std::chrono::nanoseconds>(endTime2 - startTime2); 
    cout<<"A comparar char* le tomó: "<<elapsedTime2.count()<<" nanosegundos"<<endl;
}