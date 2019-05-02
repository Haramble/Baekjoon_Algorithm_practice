#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M, virus[10000]; //컴퓨터 갯수 : N, 신뢰관계의 갯수 : M, 컴퓨터 별로 감염시킬 수 있는 컴퓨터 갯수 : virus
queue<int> q; //bfs를 하기 위한 queue

int main(){
	scanf("%d %d",&N,&M);
	vector<int> rel[N]; //관계를 저장하는 벡터, 그래프로 표현 가능
	for(int i=0; i<M; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		rel[b-1].push_back(a-1); //A가 B를 신뢰한다는 것은 B를 감염시키면 A를 감염시킬 수 있다는 의미이므로 관계B에 A를 저장
	}

	int max=0; //가장 많은 컴퓨터를 감염시킬 수 있는 컴퓨터를 찾기 위한 max
	for(int i=0; i<N; i++){
		bool visit[N]; //bfs를 위한 방문했는지 확인할 visit배열
		memset(visit, false, sizeof(visit)); //false로 초기화
		q.push(i); visit[i] = true; //0번부터 N-1번까지 bfs를 다 적용한다, queue에 시작할 computer번호를 넣고 방문했다고 표시
		while(!q.empty()){ //bfs 시작, 더이상 방문할 컴퓨터가 없을때 까지 반복
			int cur = q.front(); //현재 들어와있는 컴퓨터 cur로 선언
			virus[i]++; q.pop(); //감염시킬 수 있는 컴퓨터 갯수 증가, queue의 첫번째 원소 삭제
			vector<int>::iterator it; //연결되어있는 모든 컴퓨터에 접근하기 위한 반복자
			for(it = rel[cur].begin(); it != rel[cur].end(); it++){
				if(!visit[*it]){ //만약 연결되어있는 컴퓨터가 아직 방문하지 않은 컴퓨터이면
					visit[*it] = true; //방문했다고 표시
					q.push(*it); //queue에 넣는다
				}
			}
		}
		if(virus[i] > max) max = virus[i]; //감염시킬 수 있는 컴퓨터 갯수가 여태까지 나온것 중 최대이면 max를 업데이트
	}

	for(int i=0; i<N; i++){
		if(max == virus[i]) printf("%d ",i+1); //max와 같은값을 가지는 컴퓨터 번호를 출력
	}

	return 0;
}
