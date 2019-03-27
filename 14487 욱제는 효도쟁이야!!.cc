#include <iostream>
int N, ans, max;
int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		int a;
		scanf("%d",&a);
		ans += a;
		if(max<a) max=a;
	}
	printf("%d",ans-max);
}