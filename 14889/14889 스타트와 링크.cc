#include <iostream>
#include <algorithm>

using namespace std;

int N, SL[20][20], MINIMUM=100000000;

int main(){
	scanf("%d",&N);
	int A[N];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d",&SL[i][j]);
		}
		A[i] = (i<N/2 ? 0 : 1);
	}
	
	do{
		int start[N/2], link[N/2], start_score=0, link_score=0;
		for(int i=0, s=0, l=0; i<N; i++){
			if(A[i] == 0) start[s++]=i;
			else link[l++]=i;
		}
		
		for(int i=0; i<N/2; i++){
			for(int j=i+1; j<N/2; j++){
				start_score += SL[start[i]][start[j]]+SL[start[j]][start[i]];
				link_score += SL[link[i]][link[j]]+SL[link[j]][link[i]];
			}
		}
		
		if(MINIMUM > abs(start_score-link_score)) MINIMUM = abs(start_score-link_score);
        
	}while(next_permutation(A, A+N));
	
	printf("%d\n",MINIMUM);
	return 0;
}