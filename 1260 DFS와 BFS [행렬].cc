#include<cstdio>
#include<vector>
#include<deque>

using namespace std;

int N,M,V;
int graph[1001][1001]; //그래프를 행렬로 표현
deque<int> dq;
bool nodDFS[1001]; //방문했는지 확인하기 위한 배열
bool nodBFS[1001]; //방문했는지 확인하기 위한 배열

void DFS(int n){ //깊이우선탐색 실행 (순환호출을 이용한 DFS)
    printf("%d ",n); //도착한 노드를 출력
    nodDFS[n] = true; //방문했다고 표시
    for(int i=1 ; i<N+1; i++){ //지금 노드에서 연결된 노드들 방문
        if(graph[n][i]&&!nodDFS[i]) //만약 아직 방문하지 않은 노드라면
            DFS(i); //그 노드에서 DFS 실행
    }
}

void BFS(int n){ //넓이우선탐색 실행
    printf("%d ",n); //도착한 노드 출력
    dq.pop_front(); //이 노드에 대한 탐색을 끝냈으니 queue에서 제거
    for(int i=1; i<N+1 ; i++){ //지금 노드에서 연결된 노드들 방문
        if(graph[n][i]&&!nodBFS[i]){ //만약 아직 방문하지 않은 노드라면
            dq.push_back(i); //queue에 넣고
            nodBFS[i] = true; //방문했다고 표시
        }
    }
    if(!dq.empty()){ //queue가 비어있지 않으면, 즉 탐색이 끝나지 않았으면
        BFS(dq.front()); //queue의 제일 앞에 있는 노드부터 다시 BFS실행
    }
}

int main(){
    scanf("%d %d %d",&N,&M,&V);
    while(M--){ //입력받음
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    
    DFS(V); //DFS실행
    printf("\n");

    dq.push_back(V);
    nodBFS[V] = true;
    BFS(V); //BFS실행

    return 0;
}
