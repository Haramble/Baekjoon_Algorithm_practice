#include <iostream>

using namespace std;
/*
최악의 경우를 생각해 봤을 때
사무실이 8*8 크기이고(64),
카메라가 8개가 있고(카메라 하나당 4방향 탐색. 4의 8승 = 65536)
모든 경우마다 감시하지 못하는 공간을 카운트 한다고 하면
64 * 65536 = 4194304 약 400만 이다.
400만번의 연산은 충분히 1초안에 완료 가능하므로
모든 경우를 조사하는 방식으로 문제를 푼다.
*/
struct CCTV{ //cctv들을 저장할 구조체
	int num, y, x;
};

CCTV cctv[8];
int N, M, office[8][8], cctv_count, ans=1000;
int upd_count[6] = {0, 4, 2, 4, 4, 1}; //cctv 번호별로 탐색해야 하는 횟수

void matrix_copy(int A[8][8], int B[8][8]){ //행렬을 복사해주는 함수
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			A[i][j] = B[i][j];
}

void update(int dir, CCTV current){ //행렬 감시영역을 방향별로 업데이트 해주는 함수
	dir = dir%4;
	if(dir==0){ //east
		for(int i=current.x+1; i<M; i++){
			if(office[current.y][i]==6) break; //벽을 만나면 중지
			if(office[current.y][i]==0)
				office[current.y][i] = -1;
		}
	} else if(dir==1){ //south
		for(int i=current.y+1; i<N; i++){
			if(office[i][current.x]==6) break; //벽을 만나면 중지
			if(office[i][current.x]==0)
				office[i][current.x] = -1;
		}
	} else if(dir==2){ //west
		for(int i=current.x-1; i>=0; i--){
			if(office[current.y][i]==6) break; //벽을 만나면 중지
			if(office[current.y][i]==0)
				office[current.y][i] = -1;
		}
	} else if(dir==3){ //north
		for(int i=current.y-1; i>=0; i--){
			if(office[i][current.x]==6) break; //벽을 만나면 중지
			if(office[i][current.x]==0)
				office[i][current.x] = -1;
		}
	}
}

void chk(int cctv_index){ //감시영역을 체크하는 함수
	if(cctv_index == cctv_count){ //모든 cctv에 대해서 감시영역 업데이트가 끝났으면
		int tmp=0;
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(office[i][j]==0){ //감시하지 못하는 영역의 갯수를 모두 세고
					tmp++;
				}
			}
		}
		if(tmp < ans) ans=tmp; //최소값을 찾는다
		return;
	}


	int backup[8][8]; //잠시 백업해놓을 행렬
	for(int dir = 0; dir<upd_count[cctv[cctv_index].num]; dir++){
		//backup
		matrix_copy(backup, office);
		//update cctv의 번호에 따라서 감시영역 업데이트
		if(cctv[cctv_index].num == 1){
			update(dir, cctv[cctv_index]);
		} else if(cctv[cctv_index].num == 2){
			update(dir, cctv[cctv_index]);
			update(dir+2, cctv[cctv_index]);
		} else if(cctv[cctv_index].num == 3){
			update(dir, cctv[cctv_index]);
			update(dir+1, cctv[cctv_index]);
		} else if(cctv[cctv_index].num == 4){
			update(dir, cctv[cctv_index]);
			update(dir+1, cctv[cctv_index]);
			update(dir+2, cctv[cctv_index]);
		} else if(cctv[cctv_index].num == 5){
			update(dir, cctv[cctv_index]);
			update(dir+1, cctv[cctv_index]);
			update(dir+2, cctv[cctv_index]);
			update(dir+3, cctv[cctv_index]);
		}
		chk(cctv_index+1); //다음 cctv에 대해서 감시영역 체크 진행
		//recovery
		matrix_copy(office, backup);
	}
}

int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d",&office[i][j]);
			if(office[i][j] != 0 && office[i][j] != 6){
				cctv[cctv_count].num = office[i][j];
				cctv[cctv_count].y = i;
				cctv[cctv_count].x = j;
				cctv_count++;
			}
		}
	}

	chk(0);
	printf("%d",ans);

	return 0;
}
