#include <iostream>
#include <algorithm>

using namespace std;

int N, M, ans;
int MAP[500][500];
bool flag;
pair<int,int> dir[19][3] = {{{1,1},{0,1},{1,0}}, //사각형
	{{0,3},{0,2},{0,1}}, {{3,0},{2,0},{1,0}}, //작대기
	{{0,2},{1,1},{0,1}}, {{2,0},{1,1},{1,0}}, //ㅜ,ㅏ
	{{2,0},{1,-1},{1,0}}, {{0,2},{-1,1},{0,1}}, //ㅓ,ㅗ
	{{2,1},{1,1},{1,0}}, {{-1,2},{-1,1},{0,1}}, //ㄹ
	{{2,-1},{1,-1},{1,0}}, {{1,2},{1,1},{0,1}},
	{{-2,1},{-2,0},{-1,0}}, {{-2,-1},{-2,0},{-1,0}}, //ㄴ
	{{2,-1},{2,0},{1,0}}, {{2,1},{2,0},{1,0}},
	{{-1,2},{0,2},{0,1}}, {{1,2},{0,2},{0,1}},
	{{-1,-2},{0,-2},{0,-1}}, {{1,-2},{0,-2},{0,-1}},
};

int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d",&MAP[i][j]);
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			for(int p=0; p<19; p++){
				flag = false;
				int sum=MAP[i][j];
				for(int q=0; q<3; q++){
					int nextY = i+dir[p][q].first;
					int nextX = j+dir[p][q].second;
					
					if(nextY<0 || nextX<0 || nextY>=N || nextX>=M){
						flag = true;
						break;
					}
					
					sum+=MAP[nextY][nextX];
				}
				
				if(!flag && sum>ans) ans = sum;
			}
		}
	}
	
	printf("%d",ans);
	
	return 0;
}