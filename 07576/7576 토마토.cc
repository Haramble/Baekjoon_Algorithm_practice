#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, day, tom;
queue<pair<int, int>> ripe;
int dx[4] = {-1,1,0,0}; //왼쪽, 오른쪽, 앞, 뒤
int dy[4] = {0,0,-1,1}; //왼쪽, 오른쪽, 앞, 뒤

int main(){
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	int BOX[M][N];
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cin >> BOX[i][j];
			if(BOX[i][j] == 0) tom++;
			else if(BOX[i][j] == 1) ripe.push(make_pair(i,j));
		}
	}

	while(tom>0){
		int nextTom = tom;
		int k = ripe.size();
		while(k--){
			pair<int, int> cur = ripe.front();
			ripe.pop();
			for(int i=0; i<4; i++){
				int posY = cur.first+dy[i];
				int posX = cur.second+dx[i];
				if(posX>=0 && posY>=0 && posX<N && posY<M && BOX[posY][posX]==0){
					BOX[posY][posX] = 1;
					ripe.push(make_pair(posY,posX));
					nextTom--;
				}
			}
		}
		if(nextTom==tom)
			break;
		else{
			tom=nextTom;
			day++;
		}
	}
	
	cout << (tom>0 ? -1 : day);
	return 0;
}