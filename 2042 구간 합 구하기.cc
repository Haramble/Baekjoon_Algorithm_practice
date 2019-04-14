#include <iostream>

using namespace std;

int N, M, K;

long long init(long long *tree,long long *arr,int index,int s, int e){
	if(s==e) tree[index] = arr[s];
	else tree[index] = init(tree,arr,index*2,s,(s+e)/2)
						+ init(tree,arr,index*2+1,(s+e)/2+1,e);
	return tree[index];
}

long long sum(long long *tree,int index,int s,int e,int L,int R){
	if(s>R || e<L) return 0;
	if(s>=L && e<=R) return tree[index];
	return sum(tree,index*2,s,(s+e)/2,L,R)+sum(tree,index*2+1,(s+e)/2+1,e,L,R);
}

void update(long long *tree,int index,int s,int e,int changed_index,long long diff){
	if(s>changed_index || e<changed_index) return;
	tree[index] += diff;
	if(s != e){
		update(tree,index*2,s,(s+e)/2,changed_index,diff);
		update(tree,index*2+1,(s+e)/2+1,e,changed_index,diff);
	}
}

int main(){
	scanf("%d %d %d",&N,&M,&K);
	int h=1, tree_size=1, Query=M+K;
	while(tree_size<N){
		h++;
		tree_size*=2;
	}
	tree_size*=2;
	
	long long arr[N];
	for(int i=0; i<N; i++) scanf("%lld",&arr[i]);
	
	long long tree[tree_size];
	init(tree,arr,1,0,N-1);
	
	while(Query--){
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a==1){
			update(tree,1,0,N-1,b-1,c-arr[b-1]);
			arr[b-1] = c;
		}
		else printf("%lld\n",sum(tree,1,0,N-1,b-1,c-1));
	}
	
	return 0;
}