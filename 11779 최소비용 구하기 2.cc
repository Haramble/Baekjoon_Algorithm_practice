#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int N, M, s, t;
pair<int, int> dist[1001];
vector<pair<int, int> > bus[1001];
stack<int> ans;

void dijkstra(int start, int target){
	for(int i=1; i<=N; i++)
		dist[i].first = 1000000000;
	dist[start].first = 0;
	dist[start].second = start;
	
	priority_queue<pair<int, int> > pq;
	pq.push({0, start});
	while(!pq.empty()){
		int cur = pq.top().second;
		int curCost = -pq.top().first;
		pq.pop();
		
		if(dist[cur].first < curCost) continue;
		
		for(vector<pair<int, int> >::iterator it=bus[cur].begin(); it<bus[cur].end(); it++){
			int next = (*it).first;
			int nextCost = curCost + (*it).second;
			if(dist[next].first > nextCost){
				dist[next].first = nextCost;
				dist[next].second = cur;
				pq.push({-nextCost, next});
			}
		}
	}
}

int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++){
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		bus[a].push_back({b,c});
	}
	scanf("%d %d",&s,&t);
	
	dijkstra(s, t);
	printf("%d\n",dist[t].first);
	
	if(s == t){
		printf("2\n%d %d",s,s);
	}
	else{
		for(int i=t; dist[i].second != i; i = dist[i].second) ans.push(i);
		ans.push(s);
		printf("%d\n",ans.size());
		while(!ans.empty()){
			printf("%d ",ans.top());
			ans.pop();
		}
	}
	
	return 0;
}