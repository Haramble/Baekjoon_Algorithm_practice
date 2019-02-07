#include <iostream>
#include <algorithm>

using namespace std;
/*
맨 앞에 있는 링을 한바퀴 돌린다는 것은 뒤에있는 링들도 맨 앞의 링의
지름만큼만 회전한다는 뜻이다.

따라서 뒤에 있는 링들은 (맨앞의 링의 지름) / (뒤의 링의 지름) 만큼 돌게 된다.
기약 분수로 나타내라고 했으니 맨앞의 링과 뒤의 각각의 링과의 최대공약수를 구해서
나눠준 값들을 출력하면 된다.

그리고 지름의 식은 (2파이R) 이므로 (2파이)는 서로 약분된다. 따라서 그냥 서로의 반지름의
비율을 구하면 된다.
*/
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
