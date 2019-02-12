#include <iostream>
#include <algorithm>

using namespace std;
/*
이분탐색을 이용하여 가능한 값중 가장 큰 값을 찾는다.
*/
int N, M, A[10001], ans, MAX;

void solve(int s, int e){
	if(s==e){ //같아지면 출력
		printf("%d",s);
		return ;
	}
	int m = (s+e+1)/2; //중간값을 찾는다. 여기서 (s+e+1)/2가 중요하다
	//왜냐하면 만약 s가 0이고 e가 1이라고 가정하면 그냥 (s+e)/2를 했을 때 0이되므로
	//1이 가능한 값인지 확인할 수 없다. 따라서 (s+e+1)/2를 해줘서 확인한다.
	int tmp = M; //총 예산을 담아 놓는다.

	for(int i=0; i<N; i++){
		if(m>A[i]) tmp -= A[i]; //상한보다 낮으면 총 예산에서 그냥 뺀다.
		else tmp -= m; //상한보다 높으면 총 예산에서 상한을 뺀다.
	}

	if(tmp < 0){ //총예산이 부족하면 상한이 너무 높은것이므로 상한을 줄인다.
		solve(s, m-1); //상한을 줄일 때 m은 이미 안되는 값이므로 m-1을 넣어준다.
	}
	else{ //총 예산이 남으면 상한을 올린다.
		solve(m, e); //상한을 올릴 때는 m이 되는 값일 수도 있으므로 그냥 m을 넣는다.
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&A[i]);
		if(MAX < A[i]) MAX = A[i]; //가장 큰 값을 찾음
	}
	scanf("%d",&M);

	solve(0, MAX); //0~MAX중에 답이 있으므로 이 범위 내에서 이분탐색을 한다
	return 0;
}
