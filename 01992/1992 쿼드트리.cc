#include <iostream>

using namespace std;
/*
1780문제 종이의 개수랑 알고리즘이 비슷하다.
거의 똑같다.
*/
int N;
char display[64][64];

void chk(int y, int x, int s){
	for(int i=y; i<y+s; i++){
		for(int j=x; j<x+s; j++){
			if(display[y][x] != display[i][j]){
				int b = s/2;
				printf("(");
				chk(y,x,b); chk(y,x+b,b);
				chk(y+b,x,b); chk(y+b,x+b,b);
				printf(")");
				return;
			}
		}
	}
	printf("%c",display[y][x]);
}


int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){ //입력을 붙여서 주기 때문에 getchar로 하나씩 입력받는다.
		getchar();
		for(int j=0; j<N; j++){
			display[i][j] = getchar();
		}
	}

	chk(0,0,N);

	return 0;
}
