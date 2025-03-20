
#include <iostream>
#include <chrono> 
using namespace std;

constexpr bool b_compare_words_char(const char* word1, const char* word2, int idx=0){
    if(word1[idx]=='\0' && word2[idx]=='\0') return true;

    if(word1[idx] != word2[idx]) return false;
    
    return b_compare_words_char(word1, word2, idx+1);
}


int main(){
    constexpr const char* w1 = "hola como estas";
    constexpr const char* w2 = "hola como estas";

    auto startTime2 = chrono::high_resolution_clock::now(); 
    b_compare_words_char(w1,w2);
    auto endTime2 = chrono::high_resolution_clock::now(); 
    auto elapsedTime2 = chrono::duration_cast<std::chrono::nanoseconds>(endTime2 - startTime2); 
    cout<<"A comparar char* le tomó: "<<elapsedTime2.count()<<" nanosegundos"<<endl;
}