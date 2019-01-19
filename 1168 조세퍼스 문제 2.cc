#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int main(){
	scanf("%d %d",&N,&M);
	vector<int> v;
	v.push_back(N);
	for(int i=1; i<N; i++) v.push_back(i);

  int a = N;
  vector<int>::iterator it = v.begin();
	printf("<");
	for(int i=0; i<N-1; i++){
		it += M;
		if(it >= v.end()){
			while(1){
				it -= a;
				if(it < v.end()) break;
			}
		}
		printf("%d, ",*it);
		v.erase(it);
		it--; a--;
	}
	printf("%d>",v[0]);

	return 0;
}
