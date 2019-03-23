#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> ant[100000];
int N, L, left_fall, left_max, right_max;

int main(){
	scanf("%d %d",&N,&L);
	for(int i=0; i<N; i++){
		int a;
		scanf("%d",&a);
		if(a<0){
			left_fall++;
			if(left_max < -a) left_max = -a;
		}
		else if(right_max < L-a) right_max = L-a;
		ant[i]= make_pair(abs(a),i+1);
	}
	
	sort(ant, ant+N);
	
	if(left_max>right_max) printf("%d %d",ant[left_fall-1].second,left_max);
	else printf("%d %d",ant[left_fall].second, right_max);
	
	return 0;
}