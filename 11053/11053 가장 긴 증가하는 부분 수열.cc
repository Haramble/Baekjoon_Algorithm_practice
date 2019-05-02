#include <iostream>

using namespace std;

int N, A[1000], B[1001], ans;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&A[i]);
	
	for(int i=0; i<N; i++){
		if(B[ans]<A[i])
			B[++ans] = A[i];
		else{
			int k=ans-1;
			while(B[k]>=A[i]) k--;
			B[k+1] = A[i];
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}