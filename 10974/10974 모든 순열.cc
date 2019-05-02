#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[8];

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++) arr[i] = i+1;
	do{
		for(int i=0; i<N; i++) printf("%d ",arr[i]);
		printf("\n");
	}while(next_permutation(arr,arr+N));
	
	return 0;
}