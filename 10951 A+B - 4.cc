#include <iostream>

int main(){
	char c;
	while((c=getchar()) != EOF){
		int A,B;
		A = c-48;
		scanf("%d",&B);
		printf("%d\n",A+B);
		getchar();
	}
	return 0;
}