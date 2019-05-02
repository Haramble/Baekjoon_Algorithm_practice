#include <iostream>

using namespace std;
/*
일반적인 dp 문제를 푸는 방식과 비슷하게 푼다.
각 칸에서 갈 수 있는 수를 적어논 배열 MAP을 선언하고
dp계산을 위한 dp배열을 하나 더 선언한다.

dp배열의 0,0에서 시작하므로 0,0의 좌표를 1로 초기화 하고
각각의 좌표에서 갈 수 있는 곳을 업데이트 시킨다.

즉 dp[i][j]에서 갈 수 있는곳은 dp[i+MAP[i][j]][j] 와 dp[i][j+MAP[i][j]]이 있으므로
dp[i+MAP[i][j]][j] = dp[i+MAP[i][j]][j] + dp[i][j]
dp[i][j+MAP[i][j]] = dp[i][j+MAP[i][j]] + dp[i][j]
로 표현 할 수 있다.

이렇게 dp배열을 처음부터 끝가지 업데이트 시킨 후 마지막 dp[N-1][N-1]을 출력한다.

주의사항은 계산하는 도중에 int범위를 넘어가므로 long long으로 선언해 줘야 한다.
*/
int N, MAP[100][100];
long long dp[100][100];

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d",&MAP[i][j]);
		}
	}

	dp[0][0] = 1;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(MAP[i][j]){
				if((i+MAP[i][j])<N)
					dp[i+MAP[i][j]][j] += dp[i][j];
				if((j+MAP[i][j])<N)
					dp[i][j+MAP[i][j]] += dp[i][j];
			}
		}
	}

	printf("%lld",dp[N-1][N-1]);

	return 0;
}
