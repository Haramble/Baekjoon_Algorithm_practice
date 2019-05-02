#include <iostream>

int N, M, ans[8];

void dfs(int k){
	if(k==M){
		for(int i=0; i<M; i++)
			printf("%d ",ans[i]);
		printf("\n");
		return ;
	}
	
	if(k==0){
		for(int i=1; i<=N; i++){
			ans[k] = i;
			dfs(k+1);
		}
	}
	else{
		for(int i=ans[k-1]; i<=N; i++){
			ans[k] = i;
			dfs(k+1);
		}
	}
}

int main(){
	scanf("%d %d",&N,&M);
	dfs(0);
	return 0;
}