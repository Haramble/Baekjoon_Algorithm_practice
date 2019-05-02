#include <cstdio>
#include <algorithm>
/*
이 문제를 잘 생각해보면 모든 노드들은 들어오는 방향과 나가는방향이 딱 하나밖에 없다.
그렇기 때문에 어떤 한 노드에서 생길 수 있는 사이클은 하나 뿐이다.
따라서 한 노드에서 bfs나 dfs를 하여 연결된 노드들을 다 찾으면 그 노드들은 하나의 사이클을
이루고 있다고 볼 수 있다.
*/
using namespace std;

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		int N, cycle=0;
		scanf("%d",&N);
		pair<int,bool> arr[N+1]; //pair의 first는 연결된 노드를 나타내고, second는 방문했는지 안했는지를 나타낸다
		for(int i=1; i<N+1; i++){
			scanf("%d",&arr[i].first); //입력받음
			arr[i].second = false; //false로 초기화
		}

		for(int i=1; i<N+1; i++){
			if(!arr[i].second){ //만약 i번째 노드를 방문하지 않았다면
				arr[i].second = true; //방문했다고 표시하고
				int next = arr[i].first; //다음노드를 저장한다
				while(!arr[next].second){ //dfs를 이용하여 dfs가 끝날때까지 반복
					arr[next].second = true;
					next = arr[next].first;
				}
				cycle++; //dfs가 끝나면 싸이클이 하나 나왔다고 본다
			}
		}
		printf("%d\n",cycle); //사이클 갯수 출력
	}
	return 0;
}
