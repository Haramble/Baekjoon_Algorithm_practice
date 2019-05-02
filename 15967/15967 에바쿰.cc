#include <iostream>

using namespace std;

struct TREE{
	long long value, lazy;
};
int N, Q1, Q2, a, n, m, s, e;
long long l;
int arr[1000000];
TREE tree[1<<22];

long long init(int index, int start, int end){
	if(start == end) tree[index].value = arr[start];
	else tree[index].value = init(index*2,start,(start+end)/2)+init(index*2+1,(start+end)/2+1,end);
	return tree[index].value;
}

long long sum(int index, int start, int end, int left, int right){
	if(tree[index].lazy != 0){
		tree[index].value += (end-start+1)*tree[index].lazy;
		if(start != end){
			tree[index*2].lazy += tree[index].lazy;
			tree[index*2+1].lazy += tree[index].lazy;
		}
		tree[index].lazy = 0;
	}
	
	if(start>right || end<left) return 0;
	if(start>=left && end<=right) return tree[index].value;
	return sum(index*2,start,(start+end)/2,left,right)+sum(index*2+1,(start+end)/2+1,end,left,right);
}

void update(int index, int start, int end, int left, int right, long long diff){
	if(tree[index].lazy != 0){
		tree[index].value += (end-start+1)*tree[index].lazy;
		if(start != end){
			tree[index*2].lazy += tree[index].lazy;
			tree[index*2+1].lazy += tree[index].lazy;
		}
		tree[index].lazy = 0;
	}
	
	if(start>right || end<left) return;
	if(left<=start && end<=right){
		tree[index].value += diff*(end-start+1);
		if(start != end){
			tree[index*2].lazy += diff;
			tree[index*2+1].lazy += diff;
		}
		return;
	}
	
	update(index*2,start,(start+end)/2,left,right,diff);
	update(index*2+1,(start+end)/2+1,end,left,right,diff);
	tree[index].value = tree[index*2].value + tree[index*2+1].value;
}

int main(){
	scanf("%d %d %d",&N,&Q1,&Q2);
	for(int i=0; i<N; i++) scanf("%d",&arr[i]);
	
	init(1,0,N-1);
	
	int Q = Q1+Q2;
	while(Q--){
		scanf("%d",&a);
		if(a==1){
			scanf("%d %d",&n,&m);
			printf("%lld\n",sum(1,0,N-1,n-1,m-1));
		}
		else{
			scanf("%d %d %lld",&s,&e,&l);
			update(1,0,N-1,s-1,e-1,l);
		}
	}
	return 0;
}