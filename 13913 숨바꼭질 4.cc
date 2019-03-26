#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int N, K, visit[100001];
stack<int> ans;
queue<pair<int, int>> q;

int main(){
	scanf("%d %d",&N,&K);
	for(int i=0; i<100001; i++) visit[i] = -1;
	
	q.push(make_pair(N,0));
	visit[N] = N;
	while(!q.empty()){
		int cur = q.front().first;
		int turn = q.front().second;
		q.pop();
		if(cur == K){
			printf("%d\n",turn);
			while(cur != N){
				ans.push(cur);
				cur = visit[cur];
			}
			printf("%d ",N);
			while(!ans.empty()){
				printf("%d ",ans.top());
				ans.pop();
			}
			break;
		}
		
		if(cur>K && visit[cur-1]==-1){
			visit[cur-1] = cur;
			q.push(make_pair(cur-1, turn+1));
			continue;
		}
		
		if(cur+1<100001 && visit[cur+1]==-1){
			visit[cur+1] = cur;
			q.push(make_pair(cur+1, turn+1));
		}
		if(cur-1>=0 && visit[cur-1]==-1){
			visit[cur-1] = cur;
			q.push(make_pair(cur-1, turn+1));
		}
		if(cur*2<100001 && visit[cur*2]==-1){
			visit[cur*2] = cur;
			q.push(make_pair(cur*2, turn+1));
		}
	}
	
	
	return 0;
}