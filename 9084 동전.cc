#include <iostream>

using namespace std;

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		int N, M;
		scanf("%d",&N);
		
		int coin[N];
		for(int i=0; i<N; i++) scanf("%d",&coin[i]);
		
		scanf("%d",&M);
		int dp[M+1];
		for(int i=0; i<=M; i++) dp[i] = 0; //dp 0으로 초기화
		
		for(int i=0; i<N; i++){
			dp[coin[i]]++;
			for(int j=coin[i]+1; j<=M; j++){
				dp[j] += dp[j-coin[i]];
			}
		}
		
        printf("%d\n",dp[M]);
		/*for(int i=0; i<=M; i++){
			printf("dp[%d] : %d\n",i,dp[i]);
		}*/
	}
	
	
	return 0;
}