#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct point{
	int z, y, x;
};
int board[5][5][5], cube[5][5][5], ans=125;
queue<point> q;
point dPoint[6] = {{-1,0,0}, {1,0,0}, {0,-1,0}, {0,1,0},{0,0,-1},{0,0,1} }; //위,아래,상,하,좌,우

void copy(int A[5][5], int B[5][5]){
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			A[i][j] = B[i][j];
}

void rotate(int A[5][5]){
	int tmp[5][5];
	copy(tmp, A);
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			A[i][j] = tmp[4-j][i];
}

void make_cube(){
	int per[5] = {0,1,2,3,4};
	do{
		for(int i=0; i<5; i++)
			copy(cube[i],board[per[i]]);
		
		if(cube[0][0][0]==0 || cube[4][4][4]==0) continue;
		
		q.push({0,0,0});
		cube[0][0][0] = 0;
		while(!q.empty()){
			point cur = q.front();
			q.pop();
			for(int i=0; i<6; i++){
				point pos;
				pos.z = cur.z+dPoint[i].z;
				pos.y = cur.y+dPoint[i].y;
				pos.x = cur.x+dPoint[i].x;
				if(pos.z>=0 && pos.y>=0 && pos.x>=0
				&& pos.z<5 && pos.y<5 && pos.x<5
				&& cube[pos.z][pos.y][pos.x]==1){
					cube[pos.z][pos.y][pos.x] = cube[cur.z][cur.y][cur.x]+1;
					q.push(pos);
				}
			}
		}
		
		if(cube[4][4][4]!=1 && ans>cube[4][4][4])
			ans = cube[4][4][4];
	}while(next_permutation(per, per+5));
}

void brute(int brute_count){
	if(ans == 12)
		return ;
	if(brute_count == 5){
		make_cube();
		return ;
	}
	
	for(int i=0; i<4; i++){
		brute(brute_count+1);
		rotate(board[brute_count]);
	}
}

int main(){
	for(int k=0; k<5; k++)
		for(int i=0; i<5; i++)
			for(int j=0; j<5; j++)
				scanf("%d",&board[k][i][j]);
	
	brute(0);
	
	if(ans == 125) printf("-1");
	else printf("%d",ans);
	
	return 0;
}