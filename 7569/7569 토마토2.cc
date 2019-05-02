#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
/*
익은 토마토들을 queue에 넣어놓고 하루가 지날 때마다 토마토들의 상태를 변화시킨다.
즉 익은 토마토의 왼쪽,오른쪽,앞,뒤,위,아래에있는 덜익은 토마토를 익은걸로 바꾸고, queue에 넣는다.
이것을 계속 반복한다.

만약 덜 익은 토마토가 남아있는 상황에서 하루가 지났는데 덜 익은 토마토의 갯수가 감소하지 않았으면
더이상 토마토가 익을 수 없다는 의미이므로 -1을 출력한다.
혹은 덜 익은 토마토의 갯수가 0이 되면 몇일이 걸렸는지 출력한다.
*/
struct location{
	int x, y, h;
}; //토마토의 위치정보를 가지고 있는 구조체

int N, M, H, day, tom; //N,M,H : 박스의 가로와 세로와 쌓여져있는 박스 갯수 , day : 날짜 , tom : 덜익은 토마토 갯수
queue<location> ripe; //익은 토마토를 저장하는 큐
int dx[4] = {-1,1,0,0}; //왼쪽, 오른쪽, 앞, 뒤
int dy[4] = {0,0,-1,1}; //왼쪽, 오른쪽, 앞, 뒤
int dh[2] = {-1, 1}; //위, 아래

int main(){
	std::ios::sync_with_stdio(false);
	cin >> N >> M >> H;
	int BOX[H][M][N];
	for(int h=0; h<H; h++){
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				cin >> BOX[h][i][j];
				if(BOX[h][i][j] == 0) tom++; //덜익은 토마토이면 tom갯수 증가
				else if(BOX[h][i][j] == 1){ //익은 토마토이면 큐 ripe에 저장
					location t;
					t.x=j; t.y=i; t.h=h;
					ripe.push(t);
				}
			}
		}
	}

	while(tom>0){ //덜익은 토마토가 남아있으면 반복한다
		int nextTom = tom; //오늘 덜익은 토마토가 몇개나 익은토마토로 바뀌는지 보기위해 nextTom 선언 만약 변화가 없으면 반복문 중지하고 -1출력
		int k = ripe.size(); //현재 익은 토마토들만 가지고 하루동안 변화시켜야 하므로 ripe의 사이즈를 체크하고
		while(k--){ //체크한 사이즈 만큼 반복문을 돌게 한다
			location cur = ripe.front(); //queue에 첫번째 익은 토마토를 cur(현재) 변수에 저장
			ripe.pop(); //저장시켰으므로 queue에서 삭제
			for(int i=0; i<4; i++){ //익은 토마토의 왼쪽,오른쪽,앞,뒤 모두 체크
				int posY = cur.y+dy[i];
				int posX = cur.x+dx[i];
				if(posX>=0 && posY>=0 && posX<N && posY<M && BOX[cur.h][posY][posX]==0){ //덜익은 토마토가 있으면
					BOX[cur.h][posY][posX] = 1; //익은걸로 바꿔주고
					location t;
					t.y=posY; t.x=posX; t.h=cur.h;
					ripe.push(t); //queue에 넣는다
					nextTom--; //덜익은 토마토의 갯수는 감소
				}
			}
			for(int i=0; i<2; i++){ //익은 토마토의 위, 아래 체크
				int posH = cur.h+dh[i];
				if(posH>=0 && posH<H && BOX[posH][cur.y][cur.x]==0){ //덜익은 토마토가 있으면
					BOX[posH][cur.y][cur.x] = 1; //익은걸로 바꿔주고
					location t;
					t.y=cur.y; t.x=cur.x; t.h=posH;
					ripe.push(t); //queue에 넣는다
					nextTom--; //덜익은 토마토의 갯수는 감소
				}
			}
		}
		if(nextTom==tom) //만약 덜익은 토마토의 갯수가 변화 없으면 무한루프를 빠져나가기 위해 break
			break;
		else{ //변화가 있으면
			tom=nextTom; //tom 갯수를 nextTom으로 바꿔주고
			day++; //하루가 지났으므로 day를 증가시킨다
		}
	}

	cout << (tom>0 ? -1 : day); //만약 덜 익은 토마토의 갯수가 남아있으면 -1출력, 다 익은 토마토가 됐으면 day를 출력
	return 0;
}
