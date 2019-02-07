#include <iostream>
#include <algorithm>

using namespace std;

int N, R[100];

int gcd(int a, int b){
	while(b>0){
		int c = b;
		b = a%b;
		a = c;
	}
	return a;
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&R[i]);
	
	for(int i=1; i<N; i++){
		int g = gcd(R[0],R[i]);
		printf("%d/%d\n",R[0]/g,R[i]/g);
	}
	
	return 0;
}