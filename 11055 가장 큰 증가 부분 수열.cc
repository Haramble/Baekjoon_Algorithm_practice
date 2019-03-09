#include <iostream>

using namespace std;

int N, dp[1000], A[1000], ans;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&A[i]);
		dp[i]=A[i];
		for(int j=0; j<i; j++)
			if(A[j]<A[i] && dp[i]<dp[j]+A[i])
				dp[i] = dp[j]+A[i];
		if(ans<dp[i]) ans=dp[i];
	}
	
	printf("%d\n",ans);
	
	return 0;
}