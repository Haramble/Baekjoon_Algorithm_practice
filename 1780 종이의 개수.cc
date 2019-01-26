#include <iostream>

using namespace std;
/*
알고리즘은 다음과 같다.
1. 처음부터 종이의 각 칸의 숫자들을 비교한다.
2. 하나라도 다른 숫자가 나오면 종이를 9개의 구역으로 나누고 각각의 구역에 대해 1번부터 다시 수행한다.
3. 구역 안의 숫자들이 모두 같으면 그 숫자에 해당하는 ans를 증가시킨다.
*/
int N, paper[2187][2187], ans[3]; //ans[0]은 -1구역의 갯수, ans[1]은 0구역의 갯수, ans[2]는 1구역의 갯수

void chk(int y, int x, int s){
	if(s == 1){ //구역의 크기가 1이라면 구역의 갯수를 바로 증가시킨다.
		ans[paper[y][x]+1]++;
	}
	else{
		for(int i=y; i<y+s; i++){
			for(int j=x; j<x+s; j++){
				if(paper[y][x] != paper[i][j]){ //구역안의 하나라도 다르 숫자가 나오면
					int b = s/3; //종이를 9개의 구역으로 나눈다
					chk(y,x,b); chk(y,x+b,b); chk(y,x+2*b,b);
					chk(y+b,x,b); chk(y+b,x+b,b); chk(y+b,x+2*b,b);
					chk(y+2*b,x,b); chk(y+2*b,x+b,b); chk(y+2*b,x+2*b,b);
					return;
				}
			}
		}
		ans[paper[y][x]+1]++; //구역안의 숫자들이 모두 같으면 해당하는 ans를 증가시킨다.
	}
	return;
}


int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d",&paper[i][j]);

	chk(0,0,N);

	printf("%d\n%d\n%d",ans[0],ans[1],ans[2]); //-1구역, 0구역, 1구역 차례로 출력
	return 0;
}
