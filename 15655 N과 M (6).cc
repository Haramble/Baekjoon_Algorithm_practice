#include <iostream>
#include <algorithm>

using namespace std;

int N, M, ans[8];
bool chk[9];

void dfs(int k, int p, int a[8]){
	if(k==M){
		for(int i=0; i<M; i++)
			printf("%d ",ans[i]);
		printf("\n");
		return ;
	}
	
	for(int i=p; i<N; i++){
		if(!chk[i]){
			chk[i] = true;
			ans[k] = a[i];
			dfs(k+1, i+1, a);
			chk[i] = false;
		}
	}
}

int main(){
	scanf("%d %d",&N,&M);
	int a[8];
	for(int i=0; i<N; i++)
		scanf("%d",&a[i]);
	sort(a,a+N);
	dfs(0, 0, a);
	return 0;
}