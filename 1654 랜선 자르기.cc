#include <iostream>
#include <algorithm>

using namespace std;

int K, N;
long long A[10000], MAX;

void solve(long long s, long long e){
	if(s==e){
		printf("%lld",s);
		return ;
	}
	long long m = (s+e+1)/2;
	long long sum = 0;
	
	for(int i=0; i<K; i++){
		sum += A[i]/m;
	}
	
	if(sum < N){
		solve(s, m-1);
	}
	else {
		solve(m, e);
	}
}

int main(){
	scanf("%d %d",&K,&N);
	for(int i=0; i<K; i++){
		scanf("%lld",&A[i]);
		MAX = max(MAX, A[i]);
	}
	
	solve(0, MAX);
	
	return 0;
}