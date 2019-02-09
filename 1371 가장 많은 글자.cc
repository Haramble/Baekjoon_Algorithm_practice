#include <iostream>
/*
getchar를 이용하여 글자 하나씩
파일이끝날때까지 입력받고

알파벳 배열을 하나 선언해서
alpha[0] 은 a, alpha[1] 은 b 이런식으로 매칭하여
각각의 글자가 몇개 나왔는지 센다.

파일의 끝(EOF)까지 입력받은 후
가장 많이 나온 글자를 출력한다.
*/
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
