#include <iostream>
#include <algorithm>

using namespace std;

int N, A[100000], ans[3];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=0; i<N; i++) cin >> A[i];
	sort(A,A+N);
	
	int s=0, e=N-1;
	ans[0] = 2000000000;
	while(s<e){
		int c = A[s]+A[e];
		if(c==0){
			cout << A[s] << " " << A[e];
			return 0;
		}
		
		if(abs(ans[0]) > abs(c)){
			ans[0] = c;
			ans[1] = A[s];
			ans[2] = A[e];
		}
		
		if(c>0) e--;
		else s++;
	}
	
	cout << ans[1] << " " << ans[2];
	return 0;
}