#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
N=2일 때를 생각해보면
만약 입력받은 x1과 x2를 M으로 나누었을 때의 나머지가 같다면
abs(x1-x2)는 M으로 나누었을때 나머지가 0일 것이고,
M의 약수들로 나누었을 때도 나머지가 0일 것이다.

따라서 N=2일 때는 (x1-x2)의 절대값의 1을 제외한 약수들을 출력하면 된다.

위의 결과를 가지고 N>2일 때를 생각해보면
입력받은 x1,x2,...,xn-1, xn에 대해서 각각의 차이들을 구한 후
그들의 공통된 약수들을 출력하면 된다.

즉 abs(x1-x2) , abs(x3-x4), ... , abs(xn-1 - xn)를 계산하고
이들의 최대공약수를 구한 후에
그 최대공약수의 1을 제외한 약수들을 출력하면 된다.
*/
int N, M, X[100];
vector<int> v;

int gcd(int a, int b){
	while(b>0){
		int c=b;
		b = a%b;
		a = c;
	}
	return a;
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&X[i]);

	if(N%2 == 0)
		M = abs(X[0]-X[1]);
	else{
		M = gcd(abs(X[0]-X[1]),abs(X[0]-X[N-1]));
		N--;
	}
	for(int i=2; i<N; i+=2)
		M = gcd(M,abs(X[i]-X[i+1]));

	for(int i=2; i*i<=M; i++){
		if(M%i == 0){
			if(i*i == M) v.push_back(i);
			else{
				v.push_back(i);
				v.push_back(M/i);
			}
		}
	}
	sort(v.begin(), v.end());
	for(vector<int>::iterator it=v.begin(); it != v.end(); it++)
		printf("%d ",*it);
	printf("%d\n",M);

    return 0;
}
