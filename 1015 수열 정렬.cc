#include <iostream>
#include <algorithm>

using namespace std;

int N, A[50], B[50], P[50];
bool check[50];

int main(){
	scanf("%d",&N);
	
	for(int i=0; i<N; i++){
		scanf("%d",&A[i]);
		B[i] = A[i];
	}
	
	sort(&B[0], &B[N]);
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(B[i]==A[j] && check[j]==false){
				P[j] = i;
				check[j] = true;
				break;
			}
		}
	}
	
	for(int i=0; i<N; i++)
		printf("%d ",P[i]);
	return 0;
}