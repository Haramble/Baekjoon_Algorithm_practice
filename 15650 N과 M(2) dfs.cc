#include <iostream>
/*
간단한 dfs방법으로 nCm을 구한다.
*/
int N, M, arr[8];

void sol(int cur, int arr_count){
	if(arr_count == M){ //m개를 다 뽑았으면 1인것들만 출력
		for(int i=0; i<N; i++){
			if(arr[i] == 1){
				printf("%d ",i+1);
			}
		}
		printf("\n");
		return;
	}
	
	for(int i=cur; i<N; i++){ //dfs반복
		arr[i] = 1; //1로 했다가
		sol(i+1,arr_count+1); //dfs하고
		arr[i] = 0; //복구
	}
}

int main(){
	scanf("%d %d",&N,&M);
	
	sol(0,0);
	
	return 0;
}
