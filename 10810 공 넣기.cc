#include <iostream>

using namespace std;

int N, M, A[101];

int main(){
	scanf("%d %d",&N,&M);
	while(M--){
		int i, j, k;
		scanf("%d %d %d",&i,&j,&k);
		
		for(int p=i; p<=j; p++)
			A[p] = k;
	}
	
	for(int i=1; i<=N; i++)
		printf("%d ",A[i]);
	
	return 0;
}