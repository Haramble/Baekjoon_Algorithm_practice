#include <iostream>
#include <deque>

using namespace std;

int N, L, A[5000000];
deque<pair<int,int> > dq;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> L;
	for(int i=0; i<N; i++) cin >> A[i];
	for(int i=0; i<N; i++){
		while(!dq.empty() && dq.front().second <= i-L) dq.pop_front();
		while(!dq.empty() && dq.back().first > A[i]) dq.pop_back();
		dq.push_back({A[i],i});
		cout<<dq.front().first<<" ";
	}
	return 0;
}