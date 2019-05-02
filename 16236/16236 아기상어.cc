#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct SHARK{
	int y, x, size, evolution;
};

SHARK baby;
int N, MAP[20][20], dp[20][20], ans;
int dy[4] = {-1,0,0,1};
int dx[4] = {0,-1,1,0};
bool visit[20][20], flag;
queue<pair<int,int>> q;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d",&MAP[i][j]);
			if(MAP[i][j]==9){
				baby.y = i; baby.x = j;
				baby.size = 2; baby.evolution = 0;
				MAP[i][j] = 0;
			}
		}
	}
	
	while(1){
		int move_count = 0;
		vector<pair<int,int>> po;
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				visit[i][j] = false;
				dp[i][j] = 0;
			}
		}
		q.push(make_pair(baby.y,baby.x));
		visit[baby.y][baby.x] = true;
		flag = false;
		
		while(!q.empty()){//dfs
			pair<int,int> cur = q.front(); q.pop();
			if(flag && dp[cur.first][cur.second] != move_count-1) continue;
			
			for(int i=0; i<4; i++){
				int posY = cur.first+dy[i];
				int posX = cur.second+dx[i];
				if(posY>=0 && posX>=0 && posY<N && posX<N && !visit[posY][posX]){
					visit[posY][posX] = true;
					if(MAP[posY][posX]==0 || MAP[posY][posX]==baby.size){
						q.push(make_pair(posY,posX));
						dp[posY][posX] = dp[cur.first][cur.second]+1;
					}
					else if(MAP[posY][posX]<baby.size){
						dp[posY][posX] = dp[cur.first][cur.second]+1;
						po.push_back(make_pair(posY,posX));
						move_count = dp[posY][posX];
						flag = true;
					}
				}
			}
		}
		
		if(!flag) break;
		
		sort(po.begin(),po.end());
		baby.y = po[0].first; baby.x = po[0].second;
		MAP[baby.y][baby.x] = 0;
		baby.evolution++;
		if(baby.evolution == baby.size){
			baby.size++;
			baby.evolution = 0;
		}
		
		ans += move_count;
	}
	
	printf("%d",ans);
	return 0;
}