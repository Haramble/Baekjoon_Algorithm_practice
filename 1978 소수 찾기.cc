#include <iostream>

using namespace std;

int N, a, ans;
bool flag;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		flag = false;
		scanf("%d",&a);
		if(a == 1) continue;
		
		for(int j=2; j*j<=a; j++){
			if(a%j == 0){
				flag = true;
				break;
			}
		}
		
		if(!flag) ans++;
	}
	
	printf("%d",ans);
	
	return 0;
}