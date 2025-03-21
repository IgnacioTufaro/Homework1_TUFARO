#ifndef COMPARE_H
#define COMPARE_H

#include <string>

bool compare_words_str(const std::string word1,const std::string word2, int idx=0);
bool compare_words_char(const char* word1, const char* word2, int idx=0);

constexpr bool b_compare_words_char(const char* word1, const char* word2, int idx=0){
    if(word1[idx]=='\0' && word2[idx]=='\0') return true;

    if(word1[idx] != word2[idx]) return false; 
    if (word1[idx] == '\0' || word2[idx] == '\0') return false;

    return b_compare_words_char(word1, word2, idx+1);
}
#endif
