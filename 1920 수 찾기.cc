#include <iostream>
#include <algorithm>

using namespace std;

int N, A[100000], M;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&A[i]);
	}
	sort(A, A+N);
	scanf("%d",&M);
	while(M--){
		int t, s=0, e=N-1;
		scanf("%d",&t);
		
		while(s < e){
			int m = (s+e+1)/2;
			if(t < A[m]){
				e = m-1;
			}
			else{
				s = m;
			}
		}
		
		if(A[s] == t) printf("1\n");
		else printf("0\n");
	}
	
	return 0;
}