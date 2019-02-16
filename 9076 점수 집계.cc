#include <iostream>
#include <algorithm>

using namespace std;

int T;

int main(){
	scanf("%d",&T);
	while(T--){
		int score[5];
		for(int i=0; i<5; i++){
			scanf("%d",&score[i]);
		}
		sort(score, score+5);
		if(score[3]-score[1] >= 4) printf("KIN\n");
		else printf("%d\n",score[1]+score[2]+score[3]);
	}
	return 0;
}