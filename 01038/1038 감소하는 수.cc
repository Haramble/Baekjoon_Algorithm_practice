#include<iostream>

using namespace std;

int N, dp[11][10], s, t, l, A[10];

void update(int p, int q){
	A[p]--;
	if(A[p] == q){
		update(p-1, q+1);
		A[p] = A[p-1]-1;
	}
}

void make_dp(){
	int tmp = 9;
	for(int i=0; i<10; i++)
			dp[1][i] = 1;
	for(int i=2; i<11; i++){
		for(int j=i-1; j<10; j++){
			dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
			tmp += dp[i][j];
			if(tmp >= N){
				s = j; //맨앞자리 숫자
				t = i; //자릿수가 몇인지
				l = tmp - N; //몇번째 숫자인지
				return;
			}
		}
	}
}

int main(){
	scanf("%d",&N);
	if(N < 10)
		printf("%d",N);
	else if(N>1022)
		printf("-1");
	else{
		make_dp();
		//printf("%d %d %d",s,t,l);
		
		printf("%d",s--);
		t--;
		for(int i=0; i<t; i++)
			A[i] = s--;
		
		for(int i=0; i<l; i++)
			update(t-1, -1);
		
		for(int i=0; i<t; i++) printf("%d",A[i]);
	}
	return 0;
}