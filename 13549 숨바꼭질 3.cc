#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
bool visit[100001];
queue<pair<int, int>> q;

int main(){
	scanf("%d %d",&N,&K);
	
	if(N == 0){
		visit[0] = true;
		q.push(make_pair(0,0));
	}
	else{
		for(int i=N; i<100001; i *= 2){
			q.push(make_pair(i,0));
			visit[i] = true;
		}
	}
	
	while(!q.empty()){
		int cur = q.front().first;
		int turn = q.front().second;
		q.pop();
		if(cur == K){
			printf("%d",turn);
			break;
		}
		
		if(cur==0){
			if(!visit[1]){
				for(int i=1; i<100001; i *= 2){
					if(!visit[i]){
						visit[i] = true;
						q.push(make_pair(i, turn+1));
					}
					else break;
				}
			}
			continue;
		}
		
		if(cur>K && !visit[cur-1]){
			for(int i=cur-1; i<100001; i *= 2){
				if(!visit[i]){
					visit[i] = true;
					q.push(make_pair(i, turn+1));
				}
				else break;
			}
			continue;
		}
		
		if(cur+1<100001 && !visit[cur+1]){
			for(int i=cur+1; i<100001; i *= 2){
				if(!visit[i]){
					visit[i] = true;
					q.push(make_pair(i, turn+1));
				}
				else break;
			}
		}
		if(cur-1>=0 && !visit[cur-1]){
			for(int i=cur-1; i<100001; i *= 2){
				if(!visit[i]){
					visit[i] = true;
					q.push(make_pair(i, turn+1));
				}
				else break;
			}
		}
	}
	
	
	return 0;
}