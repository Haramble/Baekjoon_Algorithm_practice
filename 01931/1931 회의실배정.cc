#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
pair<int, int> meeting[100000];

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d %d",&meeting[i].second,&meeting[i].first);
	}
	
	sort(meeting, meeting+N);
	
	ans=N;
	int cur = meeting[0].first;
	for(int i=1; i<N; i++){
		if(meeting[i].second < cur) ans--;
		else cur = meeting[i].first;
	}
	
	printf("%d",ans);
	
	return 0;
}