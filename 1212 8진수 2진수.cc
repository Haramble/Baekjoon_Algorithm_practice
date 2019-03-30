#include <iostream>

using namespace std;
/*
8진수를 2진수로 바꿀 때는 8진수 숫자 하나당 2진수 3자리로 보고 바꾸면 된다.
앞자리가 1로 시작해야 한다고 했으므로 제일 첫째자리만 조심해주면 된다.
*/
int num[333335], numIndex;

int main(){
	while(scanf("%1d",&num[numIndex]) != EOF) numIndex++;

	if(num[0]==0){
		printf("0");
		return 0;
	}

	//첫째자리 처리
	if(num[0]/4 == 1){
		printf("%d",num[0]/4);
		num[0]%=4;
		printf("%d",num[0]/2);
		num[0]%=2;
		printf("%d",num[0]);
	}
	else if(num[0]/2 == 1){
		printf("%d",num[0]/2);
		num[0]%=2;
		printf("%d",num[0]);
	}
	else printf("1");

	//8진수 1자리당 2진수 3자리로 처리
	for(int i=1; i<numIndex; i++){
		printf("%d",num[i]/4);
		num[i]%=4;
		printf("%d",num[i]/2);
		num[i]%=2;
		printf("%d",num[i]);
	}

	return 0;
}
