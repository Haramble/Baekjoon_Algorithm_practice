#include <iostream>

using namespace std;

struct MATRIX{
	long long a,b,c,d;
};

long long N, M, gcd;

long long GCD(long long a, long long b){
	while(a != 0){
		long long tmp = a;
		b -= (b/a) * a;
		a = b;
		b = tmp;
	}
	
	return b;
}

MATRIX matrix(long long k){
	long long t=1;
	MATRIX c = {1,1,1,0};
	while((t<<1)<=k){
		MATRIX tmp = c;
		c.a = (tmp.a*tmp.a + tmp.b*tmp.c)%1000000007;
		c.b = (tmp.a*tmp.b + tmp.b*tmp.d)%1000000007;
		c.c = (tmp.c*tmp.a + tmp.d*tmp.c)%1000000007;
		c.d = (tmp.c*tmp.b + tmp.d*tmp.d)%1000000007;
		t=(t<<1);
	}
	
	if(t != k){
		MATRIX tmp = matrix(k-t), tmp1 = c;
		c.a = (tmp1.a*tmp.a + tmp1.b*tmp.c)%1000000007;
		c.b = (tmp1.a*tmp.b + tmp1.b*tmp.d)%1000000007;
		c.c = (tmp1.c*tmp.a + tmp1.d*tmp.c)%1000000007;
		c.d = (tmp1.c*tmp.b + tmp1.d*tmp.d)%1000000007;
	}
	return c;
}

int main(){
	scanf("%lld %lld",&N,&M);
	gcd = GCD(N,M);
	MATRIX ans = matrix(gcd);
	printf("%lld",ans.b);
	return 0;
}