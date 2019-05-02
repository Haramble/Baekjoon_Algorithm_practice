#include <iostream>
#include <algorithm>

using namespace std;
/*
가고자 하는 채널에서 가장 가까운 채널로 숫자버튼을 눌러 간 후에 +혹은- 버튼을 눌러 목적지에 도달한다.
그때까지 리모컨을 누른 횟수를 구하는 문제이다.

여기서 중요한것은 가고자 하는 채널에서 가장 가까운 채널을 찾는 것이다.
그래서 가고자 하는 채널에서 하나씩 빼고 더하면서 누를 수 있는 채널을 찾았다.

그리고 마지막으로 채널로 가는 모든 경우의 수 중에 가장 작은 것을 출력하게 했다.
*/
int N, M;
bool button[10];

int digits(int a){ //자릿수를 구하는 함수. a값이 인풋으로 들어오면 a가 몇자리 수 인지 return해준다.
	if(a>0){
		int ret=0;
		for(int tmp=a; tmp>0; tmp/=10) ret++;
		return ret;
	}
	else if(a<0) return -1;
	else return 1;
}

bool TVcheck(int ch){ //채널로 숫자버튼을 이용해 갈 수 있는지 알려주는 함수. 채널이 인풋으로 들어오면 리모컨의 숫자버튼을 이용해 그 채널로 갈 수 있는지 알려준다.
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
	
	if(M==10) //만약 리모컨의 모든 숫자버튼이 고장났다면 +와 -버튼을 이용해서 목적지로 가야한다
		printf("%d\n",abs(N-100)); //절대값 함수 abs를 사용하여 출력한다
	else if(TVcheck(N)) //만약 목적지 채널로 한번에 갈 수 있다면 N의 자릿수만큼만 리모컨 버튼을 누르면 목적지로 갈 수 있다.
		printf("%d\n",min(abs(N-100),digits(N))); //+,-버튼을 이용해 목적지로 가는것과, N의 자릿수만큼 누르는 것 중 적은것이 정답이다
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
