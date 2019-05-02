#include <iostream>
#include <algorithm>

using namespace std;

int N, A[500001];
long long ans;

int main(){
	scanf("%d",&N);
	for(int i=1; i<=N; i++)
		scanf("%d",&A[i]);
	
	sort(A+1,A+N+1);
	
	for(int i=1; i<=N; i++)
		ans += abs(i-A[i]);
	
	printf("%lld",ans);
	
	return 0;
}