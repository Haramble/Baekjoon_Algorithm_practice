#include <iostream>

using namespace std;

int N;
char S[2188][2188];

void star(int y, int x, int n){
	if(n==1){
		S[y][x] = '*';
		return ;
	}
	
	star(y, x,         n/3);
	star(y, x+n/3,     n/3);
	star(y, x+(n/3)*2, n/3);
	
	star(y+n/3, x,         n/3);
	star(y+n/3, x+(n/3)*2, n/3);
	
	star(y+(n/3)*2, x,         n/3);
	star(y+(n/3)*2, x+n/3,     n/3);
	star(y+(n/3)*2, x+(n/3)*2, n/3);
	
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			S[i][j] = ' ';
	
	star(0,0,N);
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			printf("%c",S[i][j]);
		printf("\n");
	}
	
	return 0;
}