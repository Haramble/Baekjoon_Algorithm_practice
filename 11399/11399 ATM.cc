#include <iostream>
#include <algorithm>

using namespace std;

int N, P[1000], sum;

int main(){
	scanf("%d", &N);
	
	for(int i=0; i<N; i++) scanf("%d", &P[i]);
	sort(P,P+N);
	for(int i=0; i<N; i++) sum += P[i]*(N-i);
	
	printf("%d",sum);
	return 0;
}
