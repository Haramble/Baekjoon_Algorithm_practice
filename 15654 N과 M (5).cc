#include <iostream>
#include <algorithm>

using namespace std;

int N, M, A[8], B[8];
bool visit[8];

void dfs(int m){
	if(m == M){
		for(int i=0; i<M; i++)
			printf("%d ",B[i]);
		printf("\n");
		return ;
	}
	
	for(int i=0; i<N; i++){
		if(!visit[i]){
			visit[i] = true;
			B[m] = A[i];
			dfs(m+1);
			visit[i] = false;
		}
	}
}

int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++) scanf("%d",&A[i]);
	sort(A, A+N);
	
	dfs(0);
	
	return 0;
}