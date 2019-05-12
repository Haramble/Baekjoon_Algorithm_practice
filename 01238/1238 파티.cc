#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, X, a, b, c, dist[1000][1000], visit[1000], ans;
vector<pair<int,int> > MAP[1000];
vector<pair<int,int> >::iterator it;
priority_queue<pair<int,int> > pq;

void dijkstra(int s){
	while(!pq.empty()) pq.pop();
	
	dist[s][s] = 0;
	pq.push({0,s});
	while(!pq.empty()){
		int cur = pq.top().second;
		int curCost = -pq.top().first;
		pq.pop();
		
		if(visit[cur]==s) continue;
		visit[cur] = s;
		
		if(s!=X && visit[X]==s) return;
		
		for(it=MAP[cur].begin(); it<MAP[cur].end(); it++){
			int next = it->first;
			int nextCost = curCost + it->second;
			
			if(visit[next]!=s && nextCost<dist[s][next]){
				dist[s][next] = nextCost;
				pq.push({-nextCost,next});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> X;
	for(int i=0; i<M; i++){
		cin >> a >> b >> c;
		MAP[a-1].push_back({b-1,c});
	}
	
	for(int i=0; i<N; i++) visit[i] = -1;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			dist[i][j] = 100000000;
	
	X--;
	for(int i=0; i<N; i++) dijkstra(i);
	
	for(int i=0; i<N; i++){
		dist[X][i] += dist[i][X];
		if(ans<dist[X][i]) ans = dist[X][i];
	}
	
	printf("%d",ans);
	return 0;
}