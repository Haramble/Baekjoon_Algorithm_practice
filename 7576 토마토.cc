#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
/*
익은 토마토들을 queue에 넣어놓고 하루가 지날 때마다 토마토들의 상태를 변화시킨다.
즉 익은 토마토의 옆에있는 덜익은 토마토를 익은걸로 바꾸고, queue에 넣는다.
이것을 계속 반복한다.

만약 덜 익은 토마토가 남아있는 상황에서 덜 익은 토마토의 갯수가 감소하지 않았으면
더이상 토마토가 익을 수 없다는 의미이므로 -1을 출력한다.
혹은 덜 익은 토마토의 갯수가 0이 되면 몇일이 걸렸는지 출력한다.
*/
int N, M, day, tom; //N,M : 박스의 가로,세로 , day : 토마토가 전부 익는데 걸리는 시간 , tom : 덜 익은 토마토의 갯수
queue<pair<int, int>> ripe; //익은 토마토를 넣어놓는 queue
int dx[4] = {-1,1,0,0}; //왼쪽, 오른쪽, 앞, 뒤
int dy[4] = {0,0,-1,1}; //왼쪽, 오른쪽, 앞, 뒤

int main(){
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	int BOX[M][N];
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cin >> BOX[i][j];
			if(BOX[i][j] == 0) tom++; //만약 덜익은 토마토이면 tom갯수 증가
			else if(BOX[i][j] == 1) ripe.push(make_pair(i,j)); //만약 익은 토마토이면 큐 ripe에 넣는다
		}
	}

	while(tom>0){ //덜익은 토마토 갯수가 남아있으면 계속 반복한다
		int nextTom = tom; //덜익은 토마토 갯수가 변화하는지 보기 위해서 nextTom변수 선언
		int k = ripe.size(); //현재 익은 토마토들만 가지고 하루동안 변화해야 하므로 ripe의 사이즈를 체크하고
		while(k--){ //체크한 사이즈 만큼만 반복문을 돌게 한다
			pair<int, int> cur = ripe.front(); //queue의 첫번째 익은 토마토를 cur(현재) 변수에 저장
			ripe.pop(); //queue의 첫번째 토마토 삭제
			for(int i=0; i<4; i++){ //익은토마토의 왼쪽, 오른쪽, 앞, 뒤 모두 체크
				int posY = cur.first+dy[i];
				int posX = cur.second+dx[i];
				if(posX>=0 && posY>=0 && posX<N && posY<M && BOX[posY][posX]==0){덜 익은 토마토가 있으면 익은걸로 바꿔주고 queue에 넣는다
					BOX[posY][posX] = 1;
					ripe.push(make_pair(posY,posX));
					nextTom--; //덜익은 토마토 갯수 감소
				}
			}
		}
		if(nextTom==tom) //만약 덜익은 토마토의 갯수가 변화가 없으면 무한루프를 빠져나가기 위해 break
			break;
		else{ //변화가 있으면
			tom=nextTom; //tom갯수를 nextTom으로 바꿔주고
			day++; //하루가 지났으므로 day를 증가시킨다
		}
	}
	
	cout << (tom>0 ? -1 : day); //만약 덜 익은 토마토의 갯수가 남아있으면 -1출력, 다 익은 토마토가 됐으면 day를 출력
	return 0;
}
