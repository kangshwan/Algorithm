#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <vector>

using namespace std;

int main(){
    map<char, int> word_count;
    
    word_count['a']=0;word_count['b']=0;
    word_count['c']=0;word_count['d']=0;
    word_count['e']=0;word_count['f']=0;
    word_count['g']=0;word_count['h']=0;
    word_count['i']=0;word_count['j']=0;
    word_count['k']=0;word_count['l']=0;
    word_count['m']=0;word_count['n']=0;
    word_count['o']=0;word_count['p']=0;
    word_count['q']=0;word_count['r']=0;
    word_count['s']=0;word_count['t']=0;
    word_count['u']=0;word_count['v']=0;
    word_count['w']=0;word_count['x']=0;
    word_count['y']=0;word_count['z']=0;
    string word;
    cin >> word;
    
    for(unsigned long i = 0 ; i < word.length() ; i++){
        char w = tolower(word[i]);
        word_count[w]++;
    }
    int max = -1;
    char max_char;
    int max_word_count = 0;
    for(char i = 'a' ; i <= 'z' ; i++){
        if(word_count[i] == 0)
            continue;
        if(word_count[i] > max){
            max = word_count[i];
            max_char = i;
            max_word_count = 0;
        }else if(word_count[i] == max){
            max_word_count ++;
        }
    }
    if(max_word_count > 0)
        cout << '?';
    else
        cout << char(toupper(max_char));
    return 0;
}
