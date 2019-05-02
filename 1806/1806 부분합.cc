#include <iostream>

using namespace std;

int N, S, sum, A[100000], r, l;

int main(){
	scanf("%d %d",&N,&S);
	for(int i=0; i<N; i++)
		scanf("%d",&A[i]);
	
	for(r=0; r<N; r++){
		sum += A[r];
		if(sum>=S)
			break;
	}
	
	if(sum<S){
		printf("0");
		return 0;
	}
	
	while(r<N){
		if(sum>=S){
			while(sum>=S){
				sum -= A[l];
				l++;
			}
			sum += A[--l];
		}
		sum = sum-A[l++]+A[++r];
	}
	
	printf("%d",r-l+1);
	
	return 0;
}