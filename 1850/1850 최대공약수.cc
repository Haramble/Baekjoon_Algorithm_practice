#include <iostream>

using namespace std;
/*
1의 갯수가 주어졌을 때
주어진 갯수의 최대공약수만큼의 1을 가지고 있는 수가 최대공약수이다.

예를들어 a=111111111 과 b=111111 의 최대공약수를 구하면
a는 1이 9개, b는 1이 6개이므로 9와 6의 최대공약수는 3이니까
a와 b의 최대공약수는 111이 된다.

이를 바탕으로 입력받은 1의 갯수의 최대공약수를 유클리드 호제법으로 구한 후
그 수만큼 1을 출력해주면 된다.
*/
long long A, B;

int main(){
	scanf("%lld %lld",&A,&B);
	while(B != 0){ //유클리드 호제법
		long long r = A%B;
		A = B;
		B = r;
	}
	for(int i=0; i<A; i++) printf("1"); //최대공약수만큼 1 출력
    return 0;
}
