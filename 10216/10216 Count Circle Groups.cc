#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
/*
진영끼리 닿거나 겹치는 부분이 있다면 직접 통신이 가능하므로 그래프적으로 이어졌다고 본다.
즉 진영i와 진영j의 거리 d가 ri+rj 보다 작다면 그래프가 연결되었다고 볼 수 있다.

이렇게 그래프로 다 연결시켜 놓은 후에 각각에 노드에서 bfs나 dfs를 이용하여 탐색을 한다.
하나의 노드에서 탐색을 했을때 탐색된 노드들은 그룹 하나로 본다.

모든 노드의 탐색이 끝나면 그룹 갯수를 출력한다.
*/
struct location{
	int x, y, r;
}; //점들의 위치와 반지름을 저장할 구조체

int T;
queue<int> q;

bool dist(location A, location B){
	int d = (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y); //d는 거리의 제곱, 점과 점 사이의 거리 공식
	return (d > (A.r+B.r)*(A.r+B.r) ? false : true);
} //진영 A와 B의 직접 통신이 가능하다면 true 리턴, 불가능하면 false 리턴

int main(){
	scanf("%d",&T);

	while(T--){
		int N, group = 0;
		scanf("%d",&N);

		location MAP[N]; //점들 저장할 배열
		bool visit[N]; //방문했는지 확인할 배열
		for(int i=0; i<N; i++){
			scanf("%d %d %d",&MAP[i].x,&MAP[i].y,&MAP[i].r);
			visit[i] = false; //visit배열 초기화
		}

		vector<int> link[N];
		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){
				if(dist(MAP[i], MAP[j])){ //저장한 점들에 대해서 직접 통신 가능한 노드들을 찾음
					link[i].push_back(j);
					link[j].push_back(i);
				}
			}
		}

		for(int i=0; i<N; i++){ //모든 노드에 대해서 bfs를 진행할 것이다
			if(!visit[i]){ //아직 방문한 적이 없는 노드라면
				q.push(i); visit[i] = true; //queue에 넣고, 방문했다고 표시
				while(!q.empty()){ //bfs 시작
					int cur = q.front();
					q.pop();
					vector<int>::iterator it; //연결된 노드들을 확인하기 위한 반복자
					for(it = link[cur].begin(); it != link[cur].end(); it++){ //연결된 노드들 모두 방문
						if(!visit[*it]){ //아직 방문하지 않았다면
							visit[*it] = true; //queue에 넣고 방문했다고 표시
							q.push(*it);
						}
					}
				}
				group++; //bfs가 끝나면 그룹 증가
			}
		}

		printf("%d\n",group);
	}

	return 0;
}
