#include <iostream>
#include <algorithm>

using namespace std;

struct CHICKEN{int y, x, selec;};
struct HOUSE{int y, x, distance;};

CHICKEN chicken[13];
HOUSE house[100];
int N, M, MAP[50][50], chicken_size, house_size, ans=10000;

void dfs(int c, int chicken_index){
	if(c==M){
		for(int i=0; i<house_size; i++){
			for(int j=0; j<chicken_size; j++){
				if(chicken[j].selec==1){
					int tmp = abs(house[i].y-chicken[j].y)+abs(house[i].x-chicken[j].x);
					if(tmp<house[i].distance) house[i].distance = tmp;
				}
			}
		}
		
		int sum=0;
		for(int i=0; i<house_size; i++){
			sum += house[i].distance;
			house[i].distance = 1000;
		}
		if(sum < ans) ans=sum;
		return ;
	}
	
	chicken[chicken_index].selec = 1;
	if(chicken_index<chicken_size) dfs(c+1, chicken_index+1);
	chicken[chicken_index].selec = 0;
	if(chicken_index<chicken_size) dfs(c, chicken_index+1);
}

int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d",&MAP[i][j]);
			if(MAP[i][j] == 1){
				house[house_size].y = i;
				house[house_size].x = j;
				house[house_size].distance = 1000;
				house_size++;
			}
			if(MAP[i][j] == 2){
				chicken[chicken_size].y = i;
				chicken[chicken_size].x = j;
				chicken[chicken_size].selec = 0;
				chicken_size++;
			}
		}
	}
	
	dfs(0, 0);
	printf("%d",ans);
	
	return 0;
}