#include <iostream>
#include <algorithm>

using namespace std;
/*
둘다 정렬 후 가장 교차적으로 곱한걸 더한게 가장 작은 수이다.
*/
int N, A[50], B[50], ans;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",&A[i]);
	for(int i=0; i<N; i++) scanf("%d",&B[i]);

	sort(A,A+N);
	sort(B,B+N);

	for(int i=0; i<N; i++) ans += A[i]*B[N-i-1];

	printf("%d",ans);

	return 0;
}
