#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int T;
int dy[8] = {-2,-2,-1,-1,1,1,2,2};
int dx[8] = {-1,1,-2,2,-2,2,-1,1};

int main(){
	scanf("%d",&T);
	while(T--){
		queue<pair<pair<int, int>, int>> q;
		int I;
		scanf("%d",&I);
		
		bool visit[I][I];
		for(int i=0; i<I; i++)
			for(int j=0; j<I; j++)
				visit[i][j] = false;
		
		pair<int, int> start, goal;
		scanf("%d %d",&start.first, &start.second);
		scanf("%d %d",&goal.first, &goal.second);
		
		q.push(make_pair(start, 0));
		visit[start.first][start.second] = true;
		while(!q.empty()){
			pair<int, int> cur = q.front().first;
			int turn = q.front().second;
			q.pop();
			
			if(cur.first==goal.first && cur.second==goal.second){
				printf("%d\n",turn);
				break;
			}
			
			for(int i=0; i<8; i++){
				pair<int, int> next;
				next.first = cur.first+dy[i];
				next.second = cur.second+dx[i];
				if(next.first<I && next.second<I && next.first>=0 && next.second>=0
				&& !visit[next.first][next.second]){
					visit[next.first][next.second] = true;
					q.push(make_pair(next, turn+1));
				}
			}
		}
	}
	return 0;
}