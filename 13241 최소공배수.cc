#include <iostream>

using namespace std;

long long A, B, ans;

int main(){
	scanf("%lld %lld",&A,&B);
	ans=A*B;
	while(B != 0){
		long long r = A%B;
		A = B;
		B = r;
	}
	printf("%lld\n",ans/A);
    return 0;
}