#include <iostream>

using namespace std;
/*
최대 공약수는 유클리드 호제법으로 구할 수 있고,

최소 공배수를 구하는 방법은
먼저 A와 B의 최대 공약수 g를 먼저 구한다.
그러면 A=g*a, B=g*b (a,b는 서로소)로 나타낼 수 있다.
따라서 최소공배수는 다음과 같이 나타낼 수 있다.
최소공배수 = (A*B)/g = g*a*b
*/
int A, B, ans;

int main(){
	scanf("%d %d",&A,&B);
	ans=A*B;
	while(B != 0){ //최대공약수 구하기(유클리드 호제법)
		int r = A%B;
		A = B;
		B = r;
	}
    printf("%d\n%d\n",A,ans/A);
    return 0;
}
