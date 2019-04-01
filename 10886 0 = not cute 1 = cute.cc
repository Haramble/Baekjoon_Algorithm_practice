#include <iostream>

using namespace std;

int N, a, sum;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&a);
		sum += a;
	}
	
	if(sum > N/2) printf("Junhee is cute!");
	else printf("Junhee is not cute!");
	
	return 0;
}