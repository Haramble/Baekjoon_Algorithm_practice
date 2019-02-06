#include <iostream>
#include <stack>

using namespace std;
/*
스페셜 저지 문제이므로 그냥 전부다 뒤집어 버리면 된다.

따라서 입력받으면서 스텍에 넣어놓고
그대로 하나씩 꺼내면서 출력하면 된다.
*/
int T;
stack<char> s[11];

int main(){
	scanf("%d",&T);
	while(T--){
		int H, W;
		scanf("%d %d",&H,&W);
		for(int i=0; i<H; i++){
			getchar();
			for(int j=0; j<W; j++){
				s[i].push(getchar()); //스택에 넣고
			}
		}

		for(int i=0; i<H; i++){
			for(int j=0; j<W; j++){
				printf("%c",s[i].top()); //출력
				s[i].pop();
			}
			printf("\n");
		}

	}

	return 0;
}
