#include <iostream>

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		getchar();
		char A, B;
		A = getchar();
		getchar();
		B = getchar();
		int C = A+B-96;
		printf("%d\n",C);
		
	}
	return 0;
}