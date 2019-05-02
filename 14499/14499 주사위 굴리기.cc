#include <iostream>

using namespace std;

int N, M, r, c, K;
int dice[6], MAP[20][20];
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

void diceMove(int commend){
	int tmp[4];
	if(commend==0){
		tmp[0] = dice[0];
		tmp[1] = dice[1];
		tmp[2] = dice[2];
		tmp[3] = dice[5];
		
		dice[0] = tmp[1];
		dice[1] = tmp[3];
		dice[2] = tmp[0];
		dice[5] = tmp[2];
	}
	else if(commend==1){
		tmp[0] = dice[0];
		tmp[1] = dice[1];
		tmp[2] = dice[2];
		tmp[3] = dice[5];
		
		dice[0] = tmp[2];
		dice[1] = tmp[0];
		dice[2] = tmp[3];
		dice[5] = tmp[1];
	}
	else if(commend==2){
		tmp[0] = dice[3];
		tmp[1] = dice[0];
		tmp[2] = dice[4];
		tmp[3] = dice[5];
		
		dice[3] = tmp[3];
		dice[0] = tmp[0];
		dice[4] = tmp[1];
		dice[5] = tmp[2];
	}
	else if(commend==3){
		tmp[0] = dice[3];
		tmp[1] = dice[0];
		tmp[2] = dice[4];
		tmp[3] = dice[5];
		
		dice[3] = tmp[1];
		dice[0] = tmp[2];
		dice[4] = tmp[3];
		dice[5] = tmp[0];
	}
}

int main(){
	scanf("%d %d %d %d %d",&N,&M,&r,&c,&K);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d",&MAP[i][j]);
	
	while(K--){
		int commend;
		scanf("%d",&commend);
		commend--;
		int nextR = r+dr[commend];
		int nextC = c+dc[commend];
		if(nextR<0 || nextC<0 || nextR>=N || nextC>=M) continue;
		
		r = nextR;
		c = nextC;
		diceMove(commend);
		if(MAP[r][c] == 0){
			MAP[r][c] = dice[0];
		}
		else{
			dice[0] = MAP[r][c];
			MAP[r][c] = 0;
		}
		
		printf("%d\n",dice[5]);
	}
	
	return 0;
}