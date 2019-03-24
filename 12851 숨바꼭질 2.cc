#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K, ans=1, visit[100001];
queue<pair<int, int>> q;

int main(){
	scanf("%d %d",&N,&K);
	for(int i=0; i<100001; i++) visit[i] = 1000000;
	
	q.push(make_pair(N,0));
	visit[N] = 0;
	while(!q.empty()){
		int cur = q.front().first;
		int turn = q.front().second;
		q.pop();
		if(cur == K){
			printf("%d\n",turn);
			while(!q.empty() && q.front().second==turn){
				if(q.front().first==K) ans++;
				q.pop();
			}
			printf("%d",ans);
			break;
		}
		
		if(cur>K && visit[cur-1]>=turn){
			visit[cur-1] = turn;
			q.push(make_pair(cur-1, turn+1));
			continue;
		}
		
		if(cur+1<100001 && visit[cur+1]>=turn){
			visit[cur+1] = turn;
			q.push(make_pair(cur+1, turn+1));
		}
		if(cur-1>=0 && visit[cur-1]>=turn){
			visit[cur-1] = turn;
			q.push(make_pair(cur-1, turn+1));
		}
		if(cur*2<100001 && visit[cur*2]>=turn){
			visit[cur*2] = turn;
			q.push(make_pair(cur*2, turn+1));
		}
	}
	
	
	return 0;
}