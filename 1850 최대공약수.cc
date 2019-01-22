#include <iostream>

using namespace std;

long long A, B;

int main(){
	scanf("%lld %lld",&A,&B);
	while(B != 0){
		long long r = A%B;
		A = B;
		B = r;
	}
	for(int i=0; i<A; i++)
    	printf("1");
    return 0;
}