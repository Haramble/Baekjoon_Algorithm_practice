#include <iostream>

using namespace std;

int N, M;
bool chk[9];

void selec(int k, int a[8]){
	if(k==M){
		for(int i=0; i<M; i++)
			printf("%d ",a[i]);
		printf("\n");
		return ;
	}
	
	for(int i=1; i<=N; i++){
		if(!chk[i]){
			chk[i] = true;
			a[k] = i;
			selec(k+1, a);
			chk[i] = false;
		}
	}
}

int main(){
	scanf("%d %d",&N,&M);
	
	int a[9];
	selec(0, a);
	
	return 0;
}