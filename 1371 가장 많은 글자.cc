#include <iostream>

int alpha[26], alp_max;
char c;

int main(){
    while((c=getchar()) != EOF){
    	if(c!=' ' && c!='\n') alpha[c-'a']++;
    }
    
    for(int i=0; i<26; i++){
        if(alp_max < alpha[i]) alp_max = alpha[i];
    }
    
    for(int i=0; i<26; i++){
        if(alp_max == alpha[i]) printf("%c",(i+'a'));
    }
    
    
    return 0;
}