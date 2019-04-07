#include <iostream>

using namespace std;

int N, M, CITY[200][200], trip_city[200];
bool visit[200], flag, flag2;

void dfs(int cur){
	visit[cur] = true;
	for(int i=0; i<N; i++){
		if(CITY[cur][i]==1 && !visit[i])
			dfs(i);
	}
}

int main(){
	scanf("%d",&N);
	scanf("%d",&M);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d",&CITY[i][j]);
	for(int i=0; i<M; i++){
		int a;
		scanf("%d",&a);
		trip_city[a-1]++;
	}
	
	for(int i=0; i<N; i++){
		if(trip_city[i]>0){
			if(!flag){
				dfs(i);
				flag = true;
			}
			else{
				if(!visit[i])
					flag2 = true;
			}
		}
	}
	
	if(flag2) printf("NO");
	else printf("YES");
	
	return 0;
}