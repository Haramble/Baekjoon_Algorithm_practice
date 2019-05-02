#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, parent[100001];
vector<int> tr[100001];
bool visit[100001];
queue<int> q;

int main(){
	scanf("%d",&N);
	for(int i=1; i<N; i++){
		int a, b;
		scanf("%d %d",&a,&b);
		tr[a].push_back(b);
		tr[b].push_back(a);
	}
	
	q.push(1);
	visit[1] = true;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		
		vector<int>::iterator it;
		for(it = tr[cur].begin(); it != tr[cur].end(); it++){
			if(!visit[*it]){
				visit[*it] = true;
				parent[*it] = cur;
				q.push(*it);
			}
		}
	}
	
	for(int i=2; i<=N; i++)
		printf("%d\n",parent[i]);
	
	return 0;
}