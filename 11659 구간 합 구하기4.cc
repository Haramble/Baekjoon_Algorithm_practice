#include <iostream>

using namespace std;

int N, M, arr[100000], tree[300000];

int init(int index, int start, int end){
	if(start == end)
		tree[index] = arr[start];
	else
		tree[index] = init(index*2,start,(start+end)/2) + init(index*2+1,(start+end)/2+1,end);
	
	return tree[index];
}

int sum(int index, int start, int end, int left, int right){
	if(start>right || end<left) return 0;
	if(start>=left && end<=right) return tree[index];
	int m = (start+end)/2;
	return sum(index*2,start,m,left,right)+sum(index*2+1,m+1,end,left,right);
}

int main(){
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++)
		scanf("%d",&arr[i]);
	
	init(1,0,N-1);
	while(M--){
		int s, e;
		scanf("%d %d",&s,&e);
		printf("%d\n",sum(1,0,N-1,s-1,e-1));
	}
	
	return 0;
}