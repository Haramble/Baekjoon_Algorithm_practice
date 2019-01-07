#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int N,M,V;
vector<int> graph[1001]; //벡터 선언
deque<int> dq;
bool nodDFS[1001];
bool nodBFS[1001];

void DFS(int V){ //DFS 실행 (순환호출을 이용한 깊이우선탐색)
	printf("%d ",V); //방문한 노드 출력
	vector<int>::iterator it; //벡터에 쉽게 접근하기 위해 반복자 선언
	for(it = graph[V].begin(); it != graph[V].end(); it++){ //노드 V에 연결된 노드를 하나씩 접근
		if(!nodDFS[*it]){ //접근한 노드에 방문하지 않았다면
			nodDFS[*it] = true; //방문했다고 표시하고
			DFS(*it); //그 노드에서 DFS실행
		}
	}
}

void BFS(){ //BFS 실행
	while(!dq.empty()){ //queue가 비어있지 않다면 즉 탐색이 끝나지 않았다면 반복
		int V = dq.front(); //현재 위치의 노드를 저장
		printf("%d ",V); //현재 위치 출력
		dq.pop_front(); //현재 위치노드의 탐색이 끝났으므로 queue에서 제거
		vector<int>::iterator it; //벡터에 쉽게 접근하기 위해 반복자 선언
		for(it = graph[V].begin(); it != graph[V].end(); it++){ //현재 위치의 노드에 연결된 노드들 하나씩 접근
			if(!nodBFS[*it]){ //접근한 노드에 방문하지 않았다면
				dq.push_back(*it); //queue에 넣고
				nodBFS[*it] = true; //방문했다고 표시
			}
		}
	}
}

int main(){
    scanf("%d %d %d",&N,&M,&V);
    while(M--){ //입력받음
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=N; i++)
    	sort(graph[i].begin(), graph[i].end()); //문제조건에서 만약 방문 할 노드가 여러개 일 경우 노드번호가 작은 순서대로 방문하라고 했으므로 정렬을 시켜준다.

    nodDFS[V] = true;
    DFS(V); //DFS 실행
    printf("\n");

    dq.push_back(V);
    nodBFS[V] = true;
    BFS(); //BFS 실행

    return 0;
}
