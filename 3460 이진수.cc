#include <iostream>

using namespace std;

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		int n, l;
		scanf("%d",&n);
		while(n!=0){
			int ans=0;
			l = n&-n;
			n -= l;
			l/=2;
			while(l!=0){
				l/=2;
				ans++;
			}
			printf("%d ",ans);
		}
		printf("\n");
	}
	return 0;
}