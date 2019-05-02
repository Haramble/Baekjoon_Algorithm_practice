#include <iostream>
#include <algorithm>

using namespace std;

int N, A[1000], B[1000], lis_L[1002], lis_R[1002], L, R, dp[2][1000], ans;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&A[i]);
		B[N-i-1] = A[i];
		if(lis_L[L] < A[i]){
			lis_L[++L] = A[i];
			dp[0][i] = L;
		}
		else{
			int *low;
			low = lower_bound(lis_L, lis_L+L, A[i]);
			lis_L[low-lis_L] = A[i];
			dp[0][i] = low-lis_L;
		}
	}
	
	for(int i=0; i<N; i++){
		scanf("%d",&B[i]);
		if(lis_R[R] < B[i]){
			lis_R[++R] = B[i];
			dp[1][i] = R;
		}
		else{
			int *low;
			low = lower_bound(lis_R, lis_R+R, B[i]);
			lis_R[low-lis_R] = B[i];
			dp[1][i] = low-lis_R;
		}
	}
	
	for(int i=0; i<N; i++)
		if(ans < dp[0][i]+dp[1][N-i-1]) ans=dp[0][i]+dp[1][N-i-1];
	
	printf("%d",ans-1);
	
	return 0;
}