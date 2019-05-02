#include <iostream>

using namespace std;

int N, M, A[10000], l, r, sum, ans;

int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++)
		scanf("%d",&A[i]);
	
	while(r<=N){
		if(sum < M)
			sum += A[r++];
		else if(sum>M)
			while(sum>M) sum -= A[l++];
		else{
			ans++;
			sum = sum - A[l++];
		}
	}
	
	printf("%d",ans);
	
	return 0;
}