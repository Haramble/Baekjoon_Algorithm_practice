#include <iostream>
int N, ans;
int main(){
	scanf("%d",&N);
	for(int i=1; i<=N; i++){
		int a;
		scanf("%d",&a);
		if(i != a) ans++;
	}
	printf("%d",ans);
}