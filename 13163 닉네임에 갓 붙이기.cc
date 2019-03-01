#include <iostream>
#include <cstring>

using namespace std;

int N;

int main(){
	char c;
	scanf("%d",&N);
	for(int i=1; i<N; i++){
		while((c=getchar()) != 32) ;
		printf("god");
		while((c=getchar()) != 10){
			if(c != 32) putchar(c);
		}
		printf("\n");
	}
	
	while((c=getchar()) != 32) ;
	printf("god");
	while((c=getchar()) != EOF){
		if(c != 32) putchar(c);
	}
	return 0;
}