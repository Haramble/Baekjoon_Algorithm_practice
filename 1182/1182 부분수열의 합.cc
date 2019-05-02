#include <iostream>

using namespace std;

int N, S, A[20], ans;

void dfs(int arr_index, int sum){
	if(arr_index == N){
		if(sum == S) ans++;
		return ;
	}
	dfs(arr_index+1, sum+A[arr_index]);
	dfs(arr_index+1, sum);
}

int main(){
	scanf("%d %d",&N,&S);
	for(int i=0; i<N; i++){
		scanf("%d",&A[i]);
	}
	
	dfs(0, 0);
	if(S==0) ans--;
	printf("%d",ans);
	
	return 0;
}