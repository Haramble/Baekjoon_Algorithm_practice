#include <iostream>
#include <cstring>

using namespace std;

char A[10001], B[10001], C[10002];
int up, a_size, b_size, c_size;

void add(char a, char b){
	if(a+b-48+up < 58){
		C[c_size++] = a+b-48+up;
		up = 0;
	}
	else{
		C[c_size++] = a+b-58+up;
		up = 1;
	}
}

int main(){
	scanf("%s %s",A,B);
	
	a_size = strlen(A);
	b_size = strlen(B);
	
	while(a_size>0 || b_size>0){
		if(a_size==0) add('0',B[--b_size]);
		else if(b_size==0) add(A[--a_size],'0');
		else add(A[--a_size],B[--b_size]);
	}
	
	if(up) printf("1");
	for(int i=c_size-1; i>=0; i--) printf("%c",C[i]);
	return 0;
}