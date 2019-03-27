#include <iostream>
#include <algorithm>

using namespace std;

int N, tree[500001];

int sum(int i){
	int ans = 0;
	while(i > 0){
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}

void update(int i, int num){
	while(i <= N){
		tree[i] += num;
		i += (i&-i);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	pair<int, int> tmp[N];
	for(int i=0; i<N; i++){
		cin >> tmp[i].first;
		tmp[i].second = i;
	}
	
	sort(tmp, tmp+N);
	for(int i=0; i<N; i++){
		tmp[i].first = tmp[i].second;
		tmp[i].second = N-i;
	}
	sort(tmp, tmp+N);
	
	for(int i=0; i<N; i++){
		update(tmp[i].second, 1);
		cout << sum(tmp[i].second) << '\n';
	}
	
	return 0;
}