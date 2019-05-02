#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, s, e, chk, ans;
vector<pair<int,int> > p;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d %d",&s,&e);
		p.push_back({s,1});
		p.push_back({e,-1});
	}
	sort(p.begin(), p.end());
	s = -1000000001;
	
	for(vector<pair<int,int> >::iterator it=p.begin(); it<p.end(); it++){
		if(s==-1000000001) s = (*it).first;
		chk += (*it).second;
		if(chk == 0){
			ans += (*it).first - s;
			s = -1000000001;
		}
	}
	
	printf("%d",ans);
	
	return 0;
}