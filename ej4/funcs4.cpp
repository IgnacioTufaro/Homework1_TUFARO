#include "header4.h"
using namespace std;

bool compare_words_str(const string word1,const string word2, int idx){
    /*Compara cada caracter indice por indice de las palabras utilizando la recursividad.
    Si en algun momento alguno es distinto, entonces es falso, 
    si ambos llegan al final sin cortarse es porque son iguales(true)
    Si tienen distinto largo es falso (caso base)*/
    if(word1.length() != word2.length()) return false;
    if(idx == word1.length()) return true;
    if(word1[idx] != word2[idx]) return false;

    //Llamado recursivo
    return compare_words_str(word1, word2, idx+1);
}

bool compare_words_char(const char* word1, const char* word2, int idx){
    /*Misma logica que la anterior, compara cada caracter usando la recursividad, si en algun 
    momento alguno es distinto o alguno llega al final antes que otro es false
    Si ambos llegan al final sin cortarse es porque son iguales (true)*/
    if(word1[idx]=='\0' && word2[idx]=='\0') return true;

    if(word1[idx] != word2[idx]) return false; 
    if (word1[idx] == '\0' || word2[idx] == '\0') return false;
    
    //Llamado recursivo
    return compare_words_char(word1, word2, idx+1);
}

