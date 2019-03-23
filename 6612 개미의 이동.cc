#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;

int main(){
	while(scanf("%d %d",&L,&N) != EOF){
		int ant[N];
		int left_max=-1, right_max=-1, left_fall=0;
		for(int i=0; i<N; i++){
			int a;
			char c;
			scanf("%d %c",&a,&c);
			if(c=='L'){
				left_fall++;
				if(left_max < a) left_max = a;
			}
			else if(right_max < L-a) right_max = L-a;
			ant[i] = a;
		}
		
		sort(ant, ant+N);
		
		if(left_max>right_max) printf("The last ant will fall down in %d seconds - started at %d.\n",left_max, ant[left_fall-1]);
		else if(left_max<right_max)printf("The last ant will fall down in %d seconds - started at %d.\n",right_max, ant[left_fall]);
		else printf("The last ant will fall down in %d seconds - started at %d and %d.\n",left_max,ant[left_fall-1], ant[left_fall]);
	}
	return 0;
}