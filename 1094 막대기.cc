#include <cstdio>
/*
2진수를 만들어서 1의 갯수를 출력하는 것과 같은 문제이다.
*/
int X, count;
int main() {
	scanf("%d",&X);
	while(X){ //2진수 만드는 반복문
		if(X%2) //나머지가 1일 때마다 count증가
			count++;
		X /= 2;
	}

	printf("%d",count);
	return 0;
}
