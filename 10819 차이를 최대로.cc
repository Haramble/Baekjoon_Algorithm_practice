#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[8], A[8], ans;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&arr[i]);
		A[i] = i;
	}
	
	do{
		int tmp = 0;
		for(int i=1; i<N; i++)
			tmp += abs(arr[A[i]]-arr[A[i-1]]);
		if(ans < tmp) ans = tmp;
	}while(next_permutation(A, A+N));
	
	printf("%d",ans);
	
	return 0;
}