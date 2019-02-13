#include <iostream>

int N, M, arr[8];

void sol(int cur, int arr_count){
	if(arr_count == M){
		for(int i=0; i<N; i++){
			if(arr[i] == 1){
				printf("%d ",i+1);
			}
		}
		printf("\n");
		return;
	}
	
	for(int i=cur; i<N; i++){
		arr[i] = 1;
		sol(i+1,arr_count+1);
		arr[i] = 0;
	}
}

int main(){
	scanf("%d %d",&N,&M);
	
	sol(0,0);
	
	return 0;
}