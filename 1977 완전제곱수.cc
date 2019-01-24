#include<iostream>

using namespace std;
/*
M,N의 범위가 1에서 10000이므로
완전제곱수를 찾기 위해 1에서 100만 고려하면 된다.
M과 N사이에 있는 완전제곱수를 찾고,
그 수들의 합과, 최소값을 출력한다.
*/
int M,N,SUM,MIN;

int main(){
	scanf("%d %d",&M,&N);

	for(int i=100; i>0; i--){
		int a = i*i;
		if(a>=M && a<=N){ //100부터 차례로 검사해서 M과 N범위에 있으면 SUM을 더해주고, 최소값 변경
			SUM+=a;
			MIN=a;
		}
	}

	SUM==0 ? printf("-1") : printf("%d\n%d",SUM,MIN); //SUM이 0이면 범위내에 완전제곱수가 없으므로 -1, 0이 아니면 SUM과 MIN출력
	return 0;
}
