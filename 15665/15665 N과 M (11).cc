#include <iostream>
#include <algorithm>

using namespace std;

int N, M, arr[8], A[8], n, ans[8];

void printArr(int pcount){
	if(pcount == M){
		for(int i=0; i<M; i++)
			printf("%d ",ans[i]);
		printf("\n");
		return ;
	}
	for(int i=0; i<n; i++){
		ans[pcount] = A[i];
		printArr(pcount+1);
	}
}

int main(){
	scanf("%d %d",&N,&M);
	
	for(int i=0; i<N; i++) scanf("%d",&arr[i]);
	sort(arr, arr+N);
	for(int i=0; i<N; i++)
		if(arr[i] != arr[i+1])
			A[n++] = arr[i];
	
	printArr(0);
	
	return 0;
}