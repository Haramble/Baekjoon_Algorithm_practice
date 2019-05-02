#include <iostream>

using namespace std;

int T, N, arr[2][100000], dp[3][100000];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=0; i<2; i++)
			for(int j=0; j<N; j++)
				scanf("%d",&arr[i][j]);
		
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[2][0] = max(arr[0][0], arr[1][0]);
		
		if(N==1){
			printf("%d\n",dp[2][0]);
			continue;
		}
		
		dp[0][1] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];
		dp[2][1] = max(dp[0][1], dp[1][1]);
		
		for(int i=2; i<N; i++){
			dp[0][i] = max(dp[2][i-2], dp[1][i-1]) + arr[0][i];
			dp[1][i] = max(dp[2][i-2], dp[0][i-1]) + arr[1][i];
			dp[2][i] = max(dp[0][i], dp[1][i]);
		}
		
		printf("%d\n",dp[2][N-1]);
	}
	
	return 0;
}