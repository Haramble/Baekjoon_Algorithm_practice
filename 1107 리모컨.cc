#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
bool button[10];

int digits(int a){
	if(a>0){
		int ret=0;
		for(int tmp=a; tmp>0; tmp/=10) ret++;
		return ret;
	}
	else if(a<0) return -1;
	else return 1;
}

bool TVcheck(int ch){
	if(ch<0) return false;
	
	int digit = digits(ch);
	while(digit>0){
		if(button[ch%10]) return false;
		ch /= 10;
		digit--;
	}
	
	return true;
}

int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++){
		int a;
		scanf("%d",&a);
		button[a] = true;
	}
	
	if(M==10)
		printf("%d\n",abs(N-100));
	else if(TVcheck(N))
		printf("%d\n",min(abs(N-100),digits(N)));
	else{
		int r=N+1, l=N-1;
		while(1){
			if(TVcheck(l)){
				printf("%d\n",min(abs(N-100),abs(N-l)+digits(l)));
				break;
			}
			else if(TVcheck(r)){
				printf("%d\n",min(abs(N-100),abs(r-N)+digits(r)));
				break;
			}
			r++; l--;
		}
	}
	return 0;
}