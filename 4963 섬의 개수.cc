#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int w, h;
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};
queue<pair<int,int> > q;

int main(){
	while(1){
		scanf("%d %d",&w,&h);
		if(w==0 && h==0) break;
		int MAP[h][w], ans=0;
		bool visit[h][w];
		
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				scanf("%d",&MAP[i][j]);
				visit[i][j] = false;
			}
		}
		
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(!visit[i][j] && MAP[i][j]==1){
					visit[i][j] = true;
					q.push({i,j});
					while(!q.empty()){
						int curY = q.front().first;
						int curX = q.front().second;
						q.pop();
						
						for(int i=0; i<8; i++){
							int nextY = curY+dy[i];
							int nextX = curX+dx[i];
							
							if(nextY>=0 && nextX>=0 && nextY<h && nextX<w
							&& MAP[nextY][nextX]==1 && !visit[nextY][nextX]){
								visit[nextY][nextX] = true;
								q.push({nextY,nextX});
							}
						}
					}
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}