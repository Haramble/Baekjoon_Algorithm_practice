#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int N, tmp;
long long ans, level[300002];
set<int> S;
set<int>::iterator R, L;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	S.insert(0); S.insert(300001);
	cin >> N;
	
	cin >> tmp;
	S.insert(tmp);
	cout << "0\n";
	for(int i=1; i<N; i++){
		cin >> tmp;
		
		S.insert(tmp);
		R = L = S.find(tmp);
		R++; L--;
		
		level[tmp] = max(level[*R],level[*L])+1;
		ans += level[tmp];
		cout << ans << '\n';
	}
	
	return 0;
}