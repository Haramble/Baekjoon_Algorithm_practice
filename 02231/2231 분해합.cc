#include <iostream>

using namespace std;

int N, n, t, ans;

int main(){
	scanf("%d",&N);
	n = N;
	while(n>0){
		t++;
		n /= 10;
	}
	
	ans = N-9*t;
	while(ans < N){
		int a=ans, b=ans;
		
		for(int i=0; i<t; i++){
			a += b%10;
			b /= 10;
		}
		
		if(a == N){
			printf("%d",ans);
			break;
		}
		
		ans++;
	}
	
	if(ans == N) printf("0\n");
	return 0;
}