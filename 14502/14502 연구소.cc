#include <iostream>
#include <algorithm>

using namespace std;

int N, M, virus_size, ep_size, ans;
int MAP[8][8], ep[64];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
bool visit[8][8];
pair<int, int> virus[10];
pair<int, int> empty_place[64];

void dfs(int y, int x){
	MAP[y][x] = 2;
	for(int i=0; i<4; i++){
		int nextY = y+dy[i];
		int nextX = x+dx[i];
		if(nextY>=0 && nextX>=0 && nextY<N && nextX<M && MAP[nextY][nextX]==0
		&& !visit[nextY][nextX]){
			visit[nextY][nextX] = true;
			dfs(nextY,nextX);
		}
	}
}

int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d",&MAP[i][j]);
			if(MAP[i][j]==2) virus[virus_size++] = {i,j};
			else if(MAP[i][j]==0) empty_place[ep_size++] = {i,j};
		}
	}
	
	ep[0] = ep[1] = ep[2] = 1;
	do{
		int tmp = 0;
		int backup[8][8];
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				backup[i][j] = MAP[i][j];
		
		for(int i=0; i<ep_size; i++)
			if(ep[i]==1) MAP[empty_place[i].first][empty_place[i].second] = 1;
		
		for(int i=0; i<virus_size; i++){
			if(!visit[virus[i].first][virus[i].second]){
				visit[virus[i].first][virus[i].second] = true;
				dfs(virus[i].first, virus[i].second);
			}
		}
		
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				if(MAP[i][j]==0) tmp++;
		
		if(tmp>ans) ans = tmp;
		
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				MAP[i][j] = backup[i][j];
				visit[i][j] = false;
			}
		}
	}while(prev_permutation(ep,ep+ep_size));
	
	printf("%d",ans);
	
	return 0;
}