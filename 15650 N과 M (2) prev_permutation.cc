#include <iostream>
#include <algorithm>

using namespace std;

int N, M, arr[8];

int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++){
		arr[i] = 1;
	}
	
	do{
		for(int i=0; i<N; i++){
			if(arr[i] == 1){
				printf("%d ",i+1);
			}
		}
		printf("\n");
	}while(prev_permutation(arr, arr+N));
	
	return 0;
}