#include <iostream>
#include <algorithm>

using namespace std;

int N, MAP[20][20], ans;

void copy(int A[20][20], int B[20][20]){
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			A[i][j] = B[i][j];
}

void transpose(){
	int tmp;
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			tmp = MAP[i][j];
			MAP[i][j] = MAP[j][i];
			MAP[j][i] = tmp;
		}
	}
}

void update(int dir){
	if(dir==0){ //좌
		for(int i=0; i<N; i++){
			int p=0, q=0;
			for(int j=0; j<N; j++){
				if(MAP[i][j] == 0) continue;
				if(p==0){
					p=MAP[i][j];
					MAP[i][j]=0;
				}
				else{
					if(MAP[i][j] == p){
						MAP[i][q] = p*2;
						p = 0;
					}
					else{
						MAP[i][q] = p;
						p = MAP[i][j];
					}
					q++;
					MAP[i][j]=0;
				}
			}
			if(p != 0) MAP[i][q] = p;
		}
	}
	else if(dir==1){//우
		for(int i=0; i<N; i++){
			int p=0, q=N-1;
			for(int j=N-1; j>=0; j--){
				if(MAP[i][j] == 0) continue;
				if(p==0){
					p=MAP[i][j];
					MAP[i][j]=0;
				}
				else{
					if(MAP[i][j] == p){
						MAP[i][q] = p*2;
						p = 0;
					}
					else{
						MAP[i][q] = p;
						p = MAP[i][j];
					}
					q--;
					MAP[i][j]=0;
				}
			}
			if(p != 0) MAP[i][q] = p;
		}
	}
	else if(dir==2){//상
		transpose();
		update(0);
		transpose();
	}
	else if(dir==3){//하
		transpose();
		update(1);
		transpose();
	}
}

void dfs(int move_count){
	if(move_count == 5){
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(MAP[i][j] > ans) ans = MAP[i][j];
		
		return ;
	}
	
	int backup[20][20];
	for(int dir=0; dir<4; dir++){
		copy(backup, MAP);
		
		update(dir);
		dfs(move_count+1);
		
		copy(MAP, backup);
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d",&MAP[i][j]);
	
	dfs(0);
	printf("%d",ans);
	
	return 0;
}