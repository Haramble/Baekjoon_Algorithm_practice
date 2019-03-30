#include <iostream>
#include <algorithm>

using namespace std;

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		int L, N, ans1=0, ans2=0;
		scanf("%d %d",&L,&N);
		for(int i=0; i<N; i++){
			int a, falling1, falling2;
			scanf("%d",&a);
			falling1 = min(a, L-a);
			falling2 = max(a, L-a);
			if(falling1>ans1) ans1=falling1;
			if(falling2>ans2) ans2=falling2;
		}
		printf("%d %d\n",ans1, ans2);
	}
	
	return 0;
}