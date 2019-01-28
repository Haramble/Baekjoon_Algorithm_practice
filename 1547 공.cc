#include <iostream>

using namespace std;
/*
공이 들어있는 컵을 바꿔줄때 공의 위치를 바꿔주면 된다.
*/
int M;
bool cup[4];

int main(){
	scanf("%d",&M);
	cup[1] = true; //공의 위치가 처음에 1번에 있으므로 1번에 넣어놨다고 표시

	while(M--){ //바꿔야하는 컵이 공이 들어있는 컵이면 공위치를 바꾼다
		int i, j;
		scanf("%d %d",&i,&j);
		if(cup[i]){ //i번 컵에 공이 들어있으면 공위치를 j번컵으로 바꿈
			cup[i] = false;
			cup[j] = true;
		} else if(cup[j]){ //j번 컵에 공이 들어있으면 공위치를 i번컵으로 바꿈
			cup[j] = false;
			cup[i] = true;
		}
	}

	for(int i=1; i<4; i++)
		if(cup[i]) printf("%d\n",i); //공이 들어있는 컵의 번호를 출력


	return 0;
}
