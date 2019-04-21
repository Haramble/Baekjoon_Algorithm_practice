#include <iostream>
using namespace std;
int A,B,C;
int main(){
	scanf("%d %d %d",&A,&B,&C);
	printf("%d",max(B-A-1,C-B-1));
	return 0;
}