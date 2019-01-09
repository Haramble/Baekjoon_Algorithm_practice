#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N, number, house_count[400], house[25][25];
queue<pair<int, int>> q;
int dy[4] = {0,0,1,-1}; //동,서,남,북
int dx[4] = {1,-1,0,0}; //동,서,남,북

void bfs(){
	while(!q.empty()){
		pair<int, int> cur = q.front(); //queue의 첫번째 값을 현재값인 current에 넣는다
		q.pop(); house_count[number-1]++; //current에 넣은 queue값 삭제하고, 주택의 갯수를 세기위한 배열을 증가시킴
		for(int i=0; i<4; i++){
			pair<int, int> next; //다음으로 갈 수 있는곳을 탐색
			next.first = cur.first+dy[i];
			next.second = cur.second+dx[i];
			if(next.first>=0 && next.second>=0 && next.first<N && next.second<N
			&& house[next.first][next.second]==1){ //만약 동,서,남,북 중에 아직 방문하지 않은 집이 있다면
				house[next.first][next.second] = 2; //방문햇다고 표시하고
				q.push(next); //queue에 넣는다.
			}
		}
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){ //입력받음
		getchar();
		for(int j=0; j<N; j++){
			char ch = getchar(); //띄어쓰기 없이 입력이 들어오므로 getchar로 받은 후에
			house[i][j] = ch-48; //아스키코드로 변환해서 house 배열에 저장한다
		}
	}

	for(int i=0; i<N; i++){ //주택단지 탐색 시작
		for(int j=0; j<N; j++){
			if(house[i][j] == 1){ //만약 집이 있고, 방문하지 않았으면 (house배열의 값이 0이면 집이 없는구역, 1이면 집이 있지만 방문하지 않은곳, 2이면 집이 있고 방문한곳 이라는 의미)
				number++; //주택단지의 번호 증가
				pair<int, int> start; //queue에 넣기 위한 pair 선언, 여기서 부터 탐색 시작하므로 start라고 이름을 붙였음
				start.first = i; start.second = j;
				q.push(start); house[i][j] = 2; //queue에 넣고 house배열에 방문했다고 표시한 후에
				bfs(); //bfs 시작
			}
		}
	}

	sort(house_count,house_count+number); //주택단지별로 주택의 갯수를 오름차순으로 출력하라고 했으므로 정렬
	printf("%d\n",number);
	for(int i=0; i<number; i++)
		printf("%d\n",house_count[i]);
	return 0;
}
