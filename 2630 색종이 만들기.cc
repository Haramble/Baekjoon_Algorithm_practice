#include <iostream>

using namespace std;
/*
1992번 쿼드트리 문제랑 거의 
*/
int N, MAP[128][128], ans0, ans1;

void chk(int y, int x, int n){
	for(int i=y; i<y+n; i++){
		for(int j=x; j<x+n; j++){
			if(MAP[y][x] != MAP[i][j]){
				n /= 2;
				chk(y,x,n);
				chk(y+n,x,n);
				chk(y,x+n,n);
				chk(y+n,x+n,n);
				return;
			}
		}
	}
	
	if(MAP[y][x] == 0) ans0++;
	else ans1++;
	return;
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d",&MAP[i][j]);
		}
	}
	
	chk(0,0,N);
	printf("%d\n%d",ans0,ans1);
	
	return 0;
}
