#include <iostream>
#include <algorithm>

using namespace std;

int N, M, MAP[10][10], ans=11;
pair<int, int> BALL[2]; //BALL[0] : red, BALL[1] : blue

void ball_move(int dir){
	if(dir==0){
		int one, two;
		if(BALL[0].second>BALL[1].second){ one = 0; two = 1; } //먼저 움직일 공 선택
		else{ one = 1; two = 0; }

		MAP[BALL[one].first][BALL[one].second] = 2;
		for(int i=BALL[one].second; i<M; i++){
			if(MAP[BALL[one].first][i]==2) continue; //빈 공간

			if(MAP[BALL[one].first][i]==9) BALL[one].second = i; //탈출
			else{ //벽이나 다른 공 만남
				BALL[one].second = i-1;
				MAP[BALL[one].first][BALL[one].second] = one;
			}
			break;
		}

		MAP[BALL[two].first][BALL[two].second] = 2;
		for(int i=BALL[two].second; i<M; i++){
			if(MAP[BALL[two].first][i]==2) continue; //빈 공간

			if(MAP[BALL[two].first][i]==9) BALL[two].second = i; //탈출
			else{ //벽이나 다른 공 만남
				BALL[two].second = i-1;
				MAP[BALL[two].first][BALL[two].second] = two;
			}
			break;
		}
	}

	if(dir==1){
		int one, two;
		if(BALL[0].second<BALL[1].second){ one = 0; two = 1; } //먼저 움직일 공 선택
		else{ one = 1; two = 0; }

		MAP[BALL[one].first][BALL[one].second] = 2;
		for(int i=BALL[one].second; i>=0; i--){
			if(MAP[BALL[one].first][i]==2) continue; //빈 공간

			if(MAP[BALL[one].first][i]==9) BALL[one].second = i; //탈출
			else{ //벽이나 다른 공 만남
				BALL[one].second = i+1;
				MAP[BALL[one].first][BALL[one].second] = one;
			}
			break;
		}

		MAP[BALL[two].first][BALL[two].second] = 2;
		for(int i=BALL[two].second; i>=0; i--){
			if(MAP[BALL[two].first][i]==2) continue; //빈 공간

			if(MAP[BALL[two].first][i]==9) BALL[two].second = i; //탈출
			else{ //벽이나 다른 공 만남
				BALL[two].second = i+1;
				MAP[BALL[two].first][BALL[two].second] = two;
			}
			break;
		}
	}

	if(dir==2){
		int one, two;
		if(BALL[0].first>BALL[1].first){ one = 0; two = 1; } //먼저 움직일 공 선택
		else{ one = 1; two = 0; }

		MAP[BALL[one].first][BALL[one].second] = 2;
		for(int i=BALL[one].first; i<N; i++){
			if(MAP[i][BALL[one].second]==2) continue; //빈 공간

			if(MAP[i][BALL[one].second]==9) BALL[one].first = i; //탈출
			else{ //벽이나 다른 공 만남
				BALL[one].first = i-1;
				MAP[BALL[one].first][BALL[one].second] = one;
			}
			break;
		}

		MAP[BALL[two].first][BALL[two].second] = 2;
		for(int i=BALL[two].first; i<N; i++){
			if(MAP[i][BALL[two].second]==2) continue; //빈 공간

			if(MAP[i][BALL[two].second]==9) BALL[two].first = i; //탈출
			else{ //벽이나 다른 공 만남
				BALL[two].first = i-1;
				MAP[BALL[two].first][BALL[two].second] = two;
			}
			break;
		}
	}

	if(dir==3){
		int one, two;
		if(BALL[0].first<BALL[1].first){ one = 0; two = 1; } //먼저 움직일 공 선택
		else{ one = 1; two = 0; }

		MAP[BALL[one].first][BALL[one].second] = 2;
		for(int i=BALL[one].first; i>=0; i--){
			if(MAP[i][BALL[one].second]==2) continue; //빈 공간

			if(MAP[i][BALL[one].second]==9) BALL[one].first = i; //탈출
			else{ //벽이나 다른 공 만남
				BALL[one].first = i+1;
				MAP[BALL[one].first][BALL[one].second] = one;
			}
			break;
		}

		MAP[BALL[two].first][BALL[two].second] = 2;
		for(int i=BALL[two].first; i>=0; i--){
			if(MAP[i][BALL[two].second]==2) continue; //빈 공간

			if(MAP[i][BALL[two].second]==9) BALL[two].first = i; //탈출
			else{ //벽이나 다른 공 만남
				BALL[two].first = i+1;
				MAP[BALL[two].first][BALL[two].second] = two;
			}
			break;
		}
	}
}

void dfs(int T){
	if(T==11 || MAP[BALL[1].first][BALL[1].second]==9) return ;

	if(MAP[BALL[0].first][BALL[0].second]==9){
		if(ans>T) ans = T;
		return ;
	}

	int backup[10][10];
	pair<int, int> backup_BALL[2];
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			backup[i][j] = MAP[i][j];
	backup_BALL[0] = BALL[0]; backup_BALL[1] = BALL[1];

	for(int dir=0; dir<4; dir++){
		ball_move(dir);
		dfs(T+1);

		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				MAP[i][j] = backup[i][j];
		BALL[0] = backup_BALL[0]; BALL[1] = backup_BALL[1];
	}
}


int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<M; j++){
			char c = getchar();
			if(c == '.') MAP[i][j] = 2;
			if(c == '#') MAP[i][j] = 3;
			if(c == 'R'){
				MAP[i][j] = 0;
				BALL[0] = {i,j};
			}
			if(c == 'B'){
				MAP[i][j] = 1;
				BALL[1] = {i,j};
			}
			if(c == 'O') MAP[i][j] = 9;
		}
	}

	dfs(0);

	if(ans == 11) printf("-1");
	else printf("%d",ans);

	return 0;
}
