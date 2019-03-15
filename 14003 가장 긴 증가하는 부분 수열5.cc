#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> lis;
vector<pair<int, int>> A;
stack<int> B;

int main(){
	scanf("%d",&N);
	lis.push_back(0);
	for(int i=0; i<N; i++){
		int a;
		scanf("%d",&a);
		if(lis.back()<a){
			lis.push_back(a);
			A.push_back(make_pair(lis.size()-1, a));
		}
		else{
			vector<int>::iterator low;
			low = lower_bound(lis.begin(), lis.end(), a);
			lis[low-lis.begin()] = a;
			A.push_back(make_pair(low-lis.begin(), a));
		}
	}
	
	int tmp = lis.size()-1;
	for(vector<pair<int,int>>::iterator it=A.end()-1; it>=A.begin(); it--){
		if((*it).first==tmp){
			tmp--;
			B.push((*it).second);
		}
	}
	
	printf("%d\n",B.size());
	while(!B.empty()){
		printf("%d ",B.top());
		B.pop();
	}
	
	return 0;
}