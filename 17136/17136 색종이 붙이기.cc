#include <iostream>

using namespace std;

int MAP[10][10], paperCount[6]={0,5,5,5,5,5}, ans=50;

int cover(int y, int x, int c){
	for(int i=y; i<y+c; i++)
		for(int j=x; j<x+c; j++)
			if(i>9 || j>9 || MAP[i][j]==0) return cover(y,x,c-1);
	
	return c;
}

void sol(int y, int x){
	int i, j;
	for(i=y; i<10; i++){
		for(j=x; j<10; j++){
			if(MAP[i][j]==1){
				int c;
				c = cover(i,j,5);
				while(c){
					if(paperCount[c]==0) return;
					
					for(int p=i; p<i+c; p++)
						for(int q=j; q<j+c; q++)
							MAP[p][q] = 0;
					paperCount[c]--;
					
					sol(y,x);
					
					for(int p=i; p<i+c; p++)
						for(int q=j; q<j+c; q++)
							MAP[p][q] = 1;
					paperCount[c]++;
					
					c--;
				}
				return ;
			}
		}
	}
	
	if(i==10 && j==10){
		int tmp=0;
		for(int i=1; i<6; i++) tmp += 5-paperCount[i];
		if(tmp<ans) ans=tmp;
	}
	return ;
}

int main(){
	for(int i=0; i<10; i++)
		for(int j=0; j<10; j++)
			scanf("%d",&MAP[i][j]);
	
	sol(0,0);
	
	if(ans==50) printf("-1");
	else printf("%d",ans);
	return 0;
}