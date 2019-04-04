#include <iostream>

using namespace std;

int T, n, curdfs, ans;
int map[100001], visit[100001];

void count_cycle(int cur){
	if(visit[cur]==-1) return;
	
	visit[cur] = -1;
	ans--;
	count_cycle(map[cur]);
}

void dfs(int cur){
	int next = map[cur];
	if(visit[next]==curdfs) count_cycle(next);
	
	if(visit[next]!=0) return ;
	
	visit[next] = curdfs;
	dfs(next);
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		curdfs = 1;
		ans = n;
		
		for(int i=1; i<=n; i++) scanf("%d",&map[i]);
		
		for(int i=1; i<=n; i++){
			if(visit[i]==0){
				visit[i] = curdfs;
				dfs(i);
				curdfs++;
			}
		}
		
		printf("%d\n",ans);
		
		for(int i=1; i<=n; i++) visit[i] = 0;
	}
	
	return 0;
}