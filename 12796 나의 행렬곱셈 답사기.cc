#include <iostream>

using namespace std;
/*
N을 3으로 고정시켜놓고 a b c d를 입력했을 때
행렬곱의 방법이 2가지만 남는다.
1. a*b*c + a*c*d = a*c*(b+d)
2. b*c*d + a*b*d = b*d*(a+c)

이 두가지중 하나는 최악의 곱셈 횟수, 다른 하나는 최적의 곱셈 횟수가 된다.
그러므로 둘의 차이가 K가 되게하면 된다.

따라서 a,b,d를 1로 고정하고 c를 K+1로 하면 된다.
*/
int K;

int main(){
	scanf("%d",&K);
	
	printf("3\n1 1 %d 1",K+1);
	return 0;
}
