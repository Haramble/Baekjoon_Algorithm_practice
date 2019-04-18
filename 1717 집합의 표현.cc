#include <iostream>

using namespace std;

int N, M, a, b, c;
int parent[1000001], level[1000001];

int find(int u){
	if(u==parent[u]) return u;
	
	return parent[u] = find(parent[u]);
}

void merge(int u, int v){
	u = find(u);
	v = find(v);
	if(u==v) return;
	
	if(level[u]>level[v]){
		int tmp = u;
		u = v;
		v = tmp;
	}
	
	parent[u] = v;
	
	if(level[u] == level[v]) level[v]++;
}

int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<=N; i++){
		parent[i] = i;
		level[i] = 1;
	}
	
	while(M--){
		scanf("%d %d %d",&c,&a,&b);
		if(c==0) merge(a,b);
		else{
			if(find(a)==find(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
	
	return 0;
}