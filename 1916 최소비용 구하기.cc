#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, s, t, dist[1001];
vector<pair<int, int> > bus[1001];

void dijkstra(int start, int target){
	for(int i=1; i<=N; i++)
		dist[i] = 100000000;
	dist[start] = 0;
	
	priority_queue<pair<int, int> > pq;
	pq.push({0, start});
	while(!pq.empty()){
		int cur = pq.top().second;
		int curCost = -pq.top().first;
		pq.pop();
		
		if(dist[cur] < curCost) continue;
		
		for(vector<pair<int, int> >::iterator it=bus[cur].begin(); it<bus[cur].end(); it++){
			int next = (*it).first;
			int nextCost = curCost + (*it).second;
			if(dist[next] > nextCost){
				dist[next] = nextCost;
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
	printf("%d",dist[t]);
	
	return 0;
}