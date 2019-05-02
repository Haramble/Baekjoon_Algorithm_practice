#include <iostream>
int r, c;
int main(){
	scanf("%d %d",&r,&c);
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}