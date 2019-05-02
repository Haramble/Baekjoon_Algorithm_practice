#include <iostream>
#include <algorithm>

using namespace std;

int N, M, a, b, arr[100000];
pair<int,int> tree[1<<20];

pair<int,int> init(int index, int s, int e){
	if(s==e){
		tree[index].first = arr[s];
		tree[index].second = arr[s];
	}
	else{
		pair<int,int> tmp1, tmp2;
		tmp1 = init(index*2,s,(s+e)/2);
		tmp2 = init(index*2+1,(s+e)/2+1,e);
		tree[index].first = min(tmp1.first,tmp2.first);
		tree[index].second = max(tmp1.second,tmp2.second);
	}
	return tree[index];
}

pair<int,int> find(int index, int s, int e, int left, int right){
	if(s>right || e<left){
		pair<int,int> tmp = {1000000001,-1000000001};
		return tmp;
	}
	
	if(left<=s && e<=right) return tree[index];
	
	pair<int,int> tmp1, tmp2;
	tmp1 = find(index*2,s,(s+e)/2,left,right);
	tmp2 = find(index*2+1,(s+e)/2+1,e,left,right);
	tmp1.first = min(tmp1.first,tmp2.first);
	tmp1.second = max(tmp1.second, tmp2.second);
	return tmp1;
}

int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++) scanf("%d",&arr[i]);
	
	init(1,0,N-1);
	
	while(M--){
		scanf("%d %d",&a,&b);
		pair<int,int> ans = find(1,0,N-1,a-1,b-1);
		printf("%d %d\n",ans.first,ans.second);
	}
	return 0;
}