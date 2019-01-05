#include <iostream>
#include <algorithm>

using namespace std;

  /*
  충돌을 충돌이라고 생각하지 말고, 항상 그대로 뚫고 지나간다고 생각해 보세요.

  그러면 어떤 시점에서 어떤 방향으로 시작하는 개미가 언제 떨어질지는 알 수 있겠죠?
  그리고 이번엔 다시 충돌 개념을 생각해서, 왼쪽 방향으로 시작하는 개미가 N마리, 오른쪽 방향으로 시작하는 개미가 M마리이면,
  처음의 N+M마리 중 왼쪽에 있던 N마리가 왼쪽으로 떨어지고, 오른쪽에 있던 M마리가 오른쪽으로 떨어진다는 것도 이해 되시나요?

  그러면 충돌이 없는 상태에서 "왼쪽 방향으로" 시작한 개미들이 떨어지는 시간을,
  충돌이 있는 상태에서 "왼쪽에서" 시작한 개미들에 차례대로 대응만 시켜주면 됩니다.
  */

int T;
int main() {
  	std::ios::sync_with_stdio(false); //입출력을 빠르게 해주는 함수
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	
	while(T--){
		int N, L, K;
		cin >> N >> L >> K;

		pair<int, int> ant[N];  //개미의 위치와 ID를 입력받기 위해 pair로 선언
		int left[N], leftLength=0; //왼쪽으로 떨어지는 개미의 떨어지는 시간을 저장하는 배열과 배열의 길이 선언.
		int right[N], rightLength=0; //오른쪽으로 떨어지는 개미의 떨어지는 시간을 저장하는 배열과 배열의 길이 선언.
		for(int i=0; i<N; i++){
			cin >> ant[i].first >> ant[i].second;
			
			if(ant[i].second > 0){
        		right[rightLength] = L-ant[i].first; //오른쪽으로 떨어지는 개미의 떨어지는데 걸리는 시간
        		rightLength++;
      			} 
			else{
        			left[leftLength] = ant[i].first; //왼쪽으로 떨어지는 개미의 떨어지는데 걸리는 시간
        			leftLength++;
      			}
		}

		for(int i=0; i<leftLength; i++)	ant[i].first = left[i]; //왼쪽부터 leftLength마리만큼 왼쪽으로 떨어짐
		for(int i=0; i<rightLength; i++) ant[leftLength+i].first = right[i]; //나머지 rightLength마리만큼 오른쪽으로 떨어짐
		sort(ant,ant+N); //개미들을 떨어지는 시간으로 정렬하고, 만약 떨어지는시간이 같다면 ID가 작은 개미를 앞으로 정렬
		cout << ant[K-1].second << "\n"; //K번째로 떨어지는 개미 출력
	}
	return 0;
}
