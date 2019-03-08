#include <iostream>

using namespace std;

int N, A[201], v;

int main(){
	scanf("%d",&N);
	
	for(int i=0; i<N; i++){
		int a;
		scanf("%d",&a);
		if(a>=-100 && a<=100)
			A[a+100]++;
	}
	scanf("%d",&v);
	
	printf("%d",A[v+100]);
	
	return 0;
}