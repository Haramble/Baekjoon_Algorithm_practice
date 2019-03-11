#include <iostream>

using namespace std;

int N, a[200][2];


int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d %d",&a[i][0],&a[i][1]);
	
	for(int i=0; i<N; i++){
		int rank=1;
		for(int j=0; j<N; j++){
			if(a[i][0]<a[j][0] && a[i][1]<a[j][1]) rank++;
		}
		printf("%d\n",rank);
	}
	
	return 0;
}