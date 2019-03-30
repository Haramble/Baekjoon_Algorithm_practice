#include <iostream>

using namespace std;

string ROT13 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string rot13 = "abcdefghijklmnopqrstuvwxyz";
char C;

int main(){ //A : 65, Z : 90, a : 97, z : 122
	while(scanf("%c",&C) != EOF){
		if(C>=65 && C<=90){
			C -= 65;
			if(C < 13) printf("%c",ROT13[C+13]);
			else printf("%c",ROT13[C-13]);
		}
		else if(C>=97 && C<=122){
			C -= 97;
			if(C < 13) printf("%c",rot13[C+13]);
			else printf("%c",rot13[C-13]);
		}
		else printf("%c",C);
	}

	return 0;
}
