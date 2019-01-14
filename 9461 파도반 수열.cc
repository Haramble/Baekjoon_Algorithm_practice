#include <cstdio>

using namespace std;
/*
문제를 잘 보면 P[i] = P[i-1] + P[i-5]인 것을 어렵지 않게 알 수 있다.
여기서 주의해야 할 사항은 100번까지 가는 도중에 int 범위를 넘어서는 문제가 있으므로
long long으로 선언 및 출력해 줘야 한다.
*/
int T;
long long P[101]; //출력범위가 int범위를 넘어가므로 long long으로 선언

int main(){
	P[1] = P[2] = P[3] = 1;
	P[4] = P[5] = 2;
	for(int i=6; i<101; i++){
		P[i] = P[i-1]+P[i-5]; //미리 P[100]까지 구해놓음
	}
	scanf("%d",&T);
	while(T--){
		int N;
		scanf("%d",&N);
		printf("%lld\n",P[N]); //출력
	}
	return 0;
}
