#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct NODE{
	int destination, weight;
};

int V, edge, ans, distan[100001];
vector<NODE> tr[100001];
bool visit[100001];

void dfs(int cur){
	visit[cur] = true;
	vector<NODE>::iterator it;
	for(it=tr[cur].begin(); it!=tr[cur].end(); it++){
		if(!visit[(*it).destination]){
			distan[(*it).destination] = distan[cur]+(*it).weight;
			dfs((*it).destination);
		}
	}
}

int main(){
	scanf("%d",&V);
	for(int i=0; i<V; i++){
		int a, b, c;
		scanf("%d",&a);
		while(1){
			scanf("%d",&b);
			if(b == -1)
				break;
			else{
				scanf("%d",&c);
				NODE t;
				t.destination=b; t.weight=c;
				tr[a].push_back(t);
			}
		}
	}
	
	dfs(1);
	for(int i=1; i<=V; i++){
		if(ans < distan[i]){
			ans = distan[i];
			edge = i;
		}
		visit[i] = false;
		distan[i] = 0;
	}
	dfs(edge);
	for(int i=1; i<=V; i++)
		if(ans < distan[i])
			ans = distan[i];
	printf("%d",ans);
	
	return 0;
}