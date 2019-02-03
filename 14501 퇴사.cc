#include <cstdio>
/*
dp를 이용해서 풀었다.
benefit[N]은 N일에 퇴사하였을 때 얻을 수 있는 최대 이익 이라고 정의하고
benefit[1] 부터 채워나갔다.
그리고 마지막에 benefit[N+1]을 출력한다
*/
int N, benefit[22];
int main(){
	scanf("%d",&N);
	for(int i=1; i<=N; i++){ //1일부터 N일까지 일하므로 N일까지 반복한다.
		if(benefit[i]<benefit[i-1]) benefit[i] = benefit[i-1]; //만약 어제 퇴사할때의 이익이 오늘 퇴사할때의 이익보다 크다면 어제 퇴사한 이익으로 바꾼다.

		int T, P;
		scanf("%d %d",&T,&P); //오늘 상담을 하면 언제끝나는지(T), 얼마를 받는지(P) 입력을 받고
		if(benefit[i+T]<benefit[i]+P) benefit[i+T] = benefit[i]+P; //i+T일에 퇴사했을 때의 이익보다 오늘 받은 상담일을 했을 때의 이익이 크면 업데이트
	}

	if(benefit[N+1]<benefit[N]) benefit[N+1] = benefit[N];
	printf("%d",benefit[N+1]);
	return 0;
}
