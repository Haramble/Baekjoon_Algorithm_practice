#include <iostream>

using namespace std;

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		int d, n, s, p;
		scanf("%d %d %d %d",&d,&n,&s,&p);
		if(d+n*p > n*s)
			printf("do not parallelize\n");
		else if(d+n*p == n*s)
			printf("does not matter\n");
		else
			printf("parallelize\n");
	}
	return 0;
}