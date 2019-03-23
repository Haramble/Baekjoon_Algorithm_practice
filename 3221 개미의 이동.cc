#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, T, N;
vector<int> ans;

int main(){
	scanf("%d %d %d",&L,&T,&N);
	for(int i=0; i<N; i++){
		int a;
		char c;
		scanf("%d %c",&a,&c);
		if(c=='L'){
			if(T<=a) a = a-T;
			else{
				int t = T-a;
				t = (t%(2*L));
				if(t <= L) a = t;
				else a = 2*L-t;
			}
		}
		else{
			if(T<=L-a) a = a+T;
			else{
				int t = T-L+a;
				t = (t%(2*L));
				if(t <= L) a = L-t;
				else a = t-L;
			}
		}
		
		ans.push_back(a);
	}
	
	sort(ans.begin(), ans.end());
	for(vector<int>::iterator it=ans.begin(); it<ans.end(); it++)
		printf("%d ",*it);
	
	return 0;
}