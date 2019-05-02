#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

struct SNAKE{
	int headY,headX,tailY,tailX;
};
int N, K, L, LD_index, ans;
int MAP[101][101];
deque<pair<int,int> > headDQ, tailDQ;
pair<int, char> LD[100];
SNAKE s;

int main(){
	scanf("%d %d",&N,&K);
	for(int i=0; i<K; i++){
		int r, c;
		scanf("%d %d",&r,&c);
		MAP[r][c] = 3;
	}
	scanf("%d",&L);
	for(int i=0; i<L; i++) scanf("%d %c",&LD[i].first,&LD[i].second);
	
	headDQ.push_back({0,1});
	headDQ.push_back({1,0});
	headDQ.push_back({0,-1});
	headDQ.push_back({-1,0});
	
	MAP[1][1] = 1;
	s.headY=1; s.headX=1; s.tailY=1; s.tailX=1;
	while(1){
		if(LD_index<L && ans==LD[LD_index].first){
			if(LD[LD_index].second=='D'){
				headDQ.push_back(headDQ.front());
				headDQ.pop_front();
			}
			else{
				headDQ.push_front(headDQ.back());
				headDQ.pop_back();
			}
			LD_index++;
		}
		
		int nextY = s.headY + headDQ.front().first;
		int nextX = s.headX + headDQ.front().second;
		ans++;
		
		if(nextY<1 || nextX<1 || nextY>N || nextX>N || MAP[nextY][nextX]==1){
			break;
		}
		
		s.headY = nextY;
		s.headX = nextX;
		tailDQ.push_back(headDQ.front());
		
		if(MAP[nextY][nextX]==3){
			MAP[nextY][nextX] = 1;
		}
		else{
			MAP[nextY][nextX] = 1;
			MAP[s.tailY][s.tailX] = 0;
			s.tailY += tailDQ.front().first;
			s.tailX += tailDQ.front().second;
			tailDQ.pop_front();
		}
	}
	
	printf("%d",ans);
	return 0;
}