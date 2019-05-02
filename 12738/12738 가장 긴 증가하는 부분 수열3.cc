#include <iostream>

using namespace std;

int N, A[1000000], ans;

int main(){
	std::ios::sync_with_stdio(false);
	cin >> N;
	A[0] = -1000000001;
	for(int i=0; i<N; i++){
		int a;
		cin >> a;
		if(a>A[ans])
			A[++ans] = a;
		else{
			int r=ans-1, l=0;
			while(r>l){
				int m = (r+l+1)/2;
				if(a<=A[m]) r=m-1;
				else l=m;
			}
			A[l+1] = a;
		}
	}
	
	cout << ans;
	
	return 0;
}