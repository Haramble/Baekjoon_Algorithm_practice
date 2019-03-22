#include <iostream>
#include <algorithm>

using namespace std;

int N, M, MAP[501][501], dp[501][501];
int dx[4] = {1,-1,0,0}; //오른쪽, 왼쪽, 위쪽, 아래쪽
int dy[4] = {0,0,-1,1}; //오른쪽, 왼쪽, 위쪽, 아래쪽
bool visit[501][501];

void dfs(int y, int x){
	if(y==M-1 && x==N-1)
		dp[y][x] = 1;
	else{
		for(int i=0; i<4; i++){
			int posY = y+dy[i];
			int posX = x+dx[i];
			if(posY>=0 && posX>=0 && posY<M && posX<N && MAP[y][x]>MAP[posY][posX]){
				if(!visit[posY][posX]){
					visit[posY][posX] = true;
					dfs(posY,posX);
				}
				dp[y][x] += dp[posY][posX];
			}
		}
	}
}

int main(){
	scanf("%d %d",&M,&N);
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			scanf("%d",&MAP[i][j]);
	
	visit[0][0] = true;
	dfs(0,0);
	
	printf("%d",dp[0][0]);
	return 0;
}