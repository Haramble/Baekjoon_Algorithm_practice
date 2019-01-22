#include <iostream>

using namespace std;

int A, B, ans;

int main(){
	scanf("%d %d",&A,&B);
	ans=A*B;
	while(B != 0){
		int r = A%B;
		A = B;
		B = r;
	}
    printf("%d\n%d\n",A,ans/A);
    return 0;
}