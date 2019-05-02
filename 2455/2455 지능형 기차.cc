#include <cstdio>
int PEOPLE, IN, OUT, MAX;
int main(){
	for(int i=0; i<4; i++){ //역이 4개이므로 4번 반복
		scanf("%d %d",&OUT,&IN); //나가는사람 들어오는사람 입력받고
		PEOPLE += IN-OUT; //people에 나가고 들어간만큼 더해준다
		if(MAX < PEOPLE) MAX = PEOPLE; //만약 최대사람보다 지금 사람이 많으면 max update
	}
	printf("%d",MAX); //max 출력
	return 0;
}
