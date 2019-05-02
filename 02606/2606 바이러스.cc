#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int N, E, ret; //컴퓨터의 갯수, 엣지의 갯수, 감염된 컴퓨터의 갯수 선언
bool visit[101]; //방문했는지 안했는지 표시하는 배열
vector<int> computer[101];
deque<int> dq; //bfs를 위한 dq

void bfs(){
	dq.push_back(1); visit[1]=true; //시작을 1번컴퓨터에서 시작하므로 dq에 1을 넣고, 1번을 방문했다고 표시
	while(!dq.empty()){ //여기서부터 bfs(넓이우선탐색) 알고리즘. dq가 비어있으면 bfs 종료
      		int V = dq.front();
      		dq.pop_front();
      		vector<int>::iterator it; //연결되어있는 컴퓨터를 파악하기 위한 반복자(iterator)  선언
      		for(it = computer[V].begin(); it != computer[V].end(); it++){ //iterator를 이용하여 연결되어있는 컴퓨터 전부 방문
        		if(!visit[*it]){ //아직 방문하지 않은 컴퓨터이면
          		visit[*it]=true; ret++; //방문했다고 표시하고 ret증가
          		dq.push_back(*it); //dq에도 넣어줌
			}
		}
	}
}

int main(){
	scanf("%d %d",&N,&E);
	while(E--){
		int a, b;
		scanf("%d %d",&a,&b);
		computer[a].push_back(b); //양쪽으로 다 연결되어있는 그래프이므로 컴퓨터벡터에 둘다 넣어준다.
		computer[b].push_back(a);
	}

	bfs();
	printf("%d",ret);

	return 0;
}
