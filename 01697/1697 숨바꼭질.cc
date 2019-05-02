#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
bool visit[100001];
queue<pair<int, int>> q;

int main(){
	scanf("%d %d",&N,&K);
	
	q.push(make_pair(N,0));
	visit[N] = true;
	while(!q.empty()){
		int cur = q.front().first;
		int turn = q.front().second;
		q.pop();
		if(cur == K){
			printf("%d",turn);
			break;
		}
		
		if(cur>K && !visit[cur-1]){
			visit[cur-1] = true;
			q.push(make_pair(cur-1, turn+1));
			continue;
		}
		
		if(cur+1<100001 && !visit[cur+1]){
			visit[cur+1] = true;
			q.push(make_pair(cur+1, turn+1));
		}
		if(cur-1>=0 && !visit[cur-1]){
			visit[cur-1] = true;
			q.push(make_pair(cur-1, turn+1));
		}
		if(cur*2<100001 && !visit[cur*2]){
			visit[cur*2] = true;
			q.push(make_pair(cur*2, turn+1));
		}
	}
	
	
	return 0;
}