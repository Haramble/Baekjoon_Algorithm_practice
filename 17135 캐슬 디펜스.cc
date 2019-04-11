#include <iostream>
#include <algorithm>

using namespace std;

int N, M, D, ans;
int MAP[15][15], arrow[15];

pair<int, int> findEnemy(int curY, int curX){
	pair<int,int> next = {-1,-1};
	for(int i=1; i<=D; i++){
		for(int j=1; j<2*i; j++){
			int nextY, nextX;
			if(j<=i) nextY = curY-j;
			else nextY = curY-2*i+j;
			nextX = curX-i+j;
			
			if(nextY<0 || nextX<0 || nextY>=N || nextX>=M || MAP[nextY][nextX]==0)
				continue;
			
			next.first = nextY;
			next.second = nextX;
			return next;
		}
	}
	
	return next;
}

int main(){
	scanf("%d %d %d",&N,&M,&D);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d",&MAP[i][j]);
	
	arrow[0] = arrow[1] = arrow[2] = 1;
	
	do{
		int backup[15][15];
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				backup[i][j] = MAP[i][j];
		
		int arrow_position[3];
		for(int i=0, j=0; i<M; i++)
			if(arrow[i]==1) arrow_position[j++] = i;
		
		int tmp=0;
		for(int i=N; i>0; i--){
			pair<int, int> attack[3];
			attack[0] = findEnemy(i,arrow_position[0]);
			attack[1] = findEnemy(i,arrow_position[1]);
			attack[2] = findEnemy(i,arrow_position[2]);
			
			if(attack[0].first!=-1){
				MAP[attack[0].first][attack[0].second]=0;
				tmp++;
			}
			if(attack[1].first!=-1 && MAP[attack[1].first][attack[1].second]==1){
				MAP[attack[1].first][attack[1].second]=0;
				tmp++;
			}
			if(attack[2].first!=-1 && MAP[attack[2].first][attack[2].second]==1){
				MAP[attack[2].first][attack[2].second]=0;
				tmp++;
			}
		}
		
		if(tmp>ans) ans = tmp;
		
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				MAP[i][j] = backup[i][j];
	}while(prev_permutation(arrow, arrow+M));
	
	printf("%d",ans);
	return 0;
}