#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int N, M, MAP[101][101];
deque<pair<int, int>> dq; //bfs를 하기 위한 queue
int visit[101][101];
pair<int, int> V;
int dx[4] = {1,-1,0,0}; //동,서,남,북
int dy[4] = {0,0,1,-1}; //동,서,남,북

void BFS(int y, int x){
	//printf("(%d %d) ",y,x);
	dq.pop_front();
	for(int i=0; i<4; i++){
		int posX = x+dx[i];
		int posY = y+dy[i];
		if(posX>=0 && posY>=0 && posX<M && posY<N && MAP[posY][posX]==1 && visit[posY][posX]==0){
			V.first = posY; V.second = posX;
			dq.push_back(V);
			visit[posY][posX] = visit[y][x]+1;
		}
	}
	if(!dq.empty())
		BFS(dq.front().first,dq.front().second);
}

int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++){
		getchar(); //버퍼 처리
		for(int j=0; j<M; j++){
			char c = getchar();
			MAP[i][j] = c-48;
			//printf("%d",MAP[i][j]);
		}
		//printf("\n");
	}

	V.first=0; V.second=0;
	dq.push_back(V); visit[0][0] = 1;
	BFS(0,0);
	printf("%d",visit[N-1][M-1]);
	return 0;
}
