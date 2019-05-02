#include <iostream>
#include <algorithm>

using namespace std;

int N, M, MAP[1001][1001];
int dy[4] = {1,0,0,-1};
int dx[4] = {0,1,-1,0};
bool visit[1001][1001], isOk;

void dfs(int y, int x){
	if(isOk) return ;
	if(y==M-1){
		isOk = true;
		return ;
	}
	
	for(int i=0; i<4; i++){
		int nextY = y+dy[i];
		int nextX = x+dx[i];
		if(nextX<N && nextY<M && nextX>=0 && nextY>=0
		&& MAP[nextY][nextX]==0 && !visit[nextY][nextX]){
			visit[nextY][nextX] = true;
			dfs(nextY,nextX);
		}
	}
}

int main(){
	scanf("%d %d",&M,&N);
	
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			scanf("%1d",&MAP[i][j]);
	
	for(int i=0; i<N; i++){
		if(MAP[0][i]==0 && !visit[0][i]){
			visit[0][i] = true;
			dfs(0,i);
		}
		if(isOk){
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}