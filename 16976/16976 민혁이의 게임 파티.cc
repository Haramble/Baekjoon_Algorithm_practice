#include <iostream>
#include <map>

using namespace std;

struct T{
	int parent, level;
	map<int,int> mp;
};
int N, M, Q, a, b, game[100001], ans[100001];
T tree[100001];

int findParent(int u){
	if(tree[u].parent == u) return u;
	return tree[u].parent = findParent(tree[u].parent);
}

void merge(int u, int v, int turn){
	u = findParent(u);
	v = findParent(v);
	
	if(u==v) return;
	
	if(tree[u].level>tree[v].level){
		int tmp = u;
		u = v;
		v = tmp;
	}
	tree[u].parent = v;
	if(tree[u].level == tree[v].level) tree[v].level++;
	
	map<int,int>::iterator Findv;
	while(!tree[u].mp.empty()){
		pair<int,int> tmp = *tree[u].mp.begin();
		tree[u].mp.erase(tree[u].mp.begin());
		
		Findv = tree[v].mp.find(tmp.first);
		if(Findv != tree[v].mp.end()){
			Findv->second += tmp.second;
			if(Findv->second == game[Findv->first]){
				ans[Findv->first] = turn;
				tree[v].mp.erase(Findv);
			}
		}
		else if(ans[tmp.first] != 0) tree[v].mp.insert(tmp);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> Q;
	for(int i=1; i<=N; i++){
		cin >> a;
		game[a]++;
		tree[i].parent = i;
		tree[i].level = 1;
		tree[i].mp.insert({a,1});
	}
	
	for(int i=1; i<=M; i++){
		if(game[i]==1) ans[i] = 0;
		else ans[i] = -1;
	}
	
	for(int i=1; i<=Q; i++){
		cin >> a >> b;
		merge(a,b,i);
	}
	
	for(int i=1; i<=M; i++) cout << ans[i] << "\n";
	return 0;
}