#include <iostream>
/*
생각을 잘 해 보면 n이 4 이후부터는
n-1숫자를 만든 경우의 수 에서 +1,
n-2숫자를 만든 경우의 수 에서 +2,
n-3숫자를 만든 경우의 수 에서 +3 을하는
경우의수 3가지가 나온다.

따라서 식이
dp[n] = dp[n-1] + dp[n-2] + dp[n-3] 이 된다.

n이 1,2,3일때는 직접 구해주고 나머지는 그냥 출력하면 된다.
*/
int T,n, dp[12];

int main(){
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i=4; i<12; i++)
		dp[i] = dp[i-1]+dp[i-2]+dp[i-3];

	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}

	return 0;
}
