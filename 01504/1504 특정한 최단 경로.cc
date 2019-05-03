#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, E, a, b, c, s1, s2;
vector<pair<int,int> > MAP[801];
vector<pair<int,int> >::iterator it;
priority_queue<pair<int,int> > pq;
pair<int,int> ans[3];
bool flag;

void dijkstra(int start, int index){
	bool visit[N+1];
	int dist[N+1];
	for(int i=1; i<=N; i++){
		visit[i] = false;
		dist[i] = 1000000000;
	}
	
	while(!pq.empty()) pq.pop();
	
	dist[start] = 0;
	pq.push({0,start});
	while(!pq.empty()){
		int cur = pq.top().second;
		int curCost = -pq.top().first;
		pq.pop();
		
		if(visit[cur]) continue;
		visit[cur] = true;
		
		if(visit[s1] && visit[s2]){
			ans[index].first = dist[s1];
			ans[index].second = dist[s2];
			
			return;
		}
		
		for(it=MAP[cur].begin(); it<MAP[cur].end(); it++){
			int next = it->first;
			int nextCost = curCost + it->second;
			
			if(!visit[next] && nextCost<dist[next]){
				dist[next] = nextCost;
				pq.push({-nextCost,next});
			}
		}
	}
	
	flag = true;
	return;
}

int main(){
	scanf("%d %d",&N,&E);
	for(int i=0; i<E; i++){
		scanf("%d %d %d",&a,&b,&c);
		MAP[a].push_back({b,c});
		MAP[b].push_back({a,c});
	}
	scanf("%d %d",&s1,&s2);
	
	dijkstra(1,0);
	dijkstra(s1,1);
	dijkstra(N,2);
	
	if(flag) printf("-1");
	else printf("%d",min(ans[0].first+ans[1].second+ans[2].second,
						ans[0].second+ans[1].second+ans[2].first));
	
	return 0;
}