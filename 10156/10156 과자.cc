#include <iostream>

int main(){
	int K, N, M;
	scanf("%d %d %d",&K,&N,&M);
	if(K*N-M < 0) printf("0");
	else printf("%d",K*N-M);
	return 0;
}