#include <iostream>

using namespace std;

struct NODE{
	int key, left, right;
};

NODE tr[27];
int N;

void pre_order(int k){
	if(k != -19){
		printf("%c",tr[k].key);
		pre_order(tr[k].left-65);
		pre_order(tr[k].right-65);
	}
}

void in_order(int k){
	if(k != -19){
		in_order(tr[k].left-65);
		printf("%c",tr[k].key);
		in_order(tr[k].right-65);
	}
}

void post_order(int k){
	if(k != -19){
		post_order(tr[k].left-65);
		post_order(tr[k].right-65);
		printf("%c",tr[k].key);
	}
}

int main(){
	scanf("%d",&N);
	
	for(int i=0; i<N; i++){
		char c[5];
		scanf("%s",c);
		int t = c[0]-'A';
		tr[t].key = c[0];
		scanf("%s",c);
		tr[t].left = c[0];
		scanf("%s",c);
		tr[t].right = c[0];
	}
	
	//for(int i=0; i<N; i++){
	//	printf("%d %d %d\n",tr[i].key,tr[i].left,tr[i].right);
	//}
	pre_order(0);
	printf("\n");
	in_order(0);
	printf("\n");
	post_order(0);
	
	return 0;
}