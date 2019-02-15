#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char A[10010], B[10010], C[10010];
int A_num[10010], B_num[10010], C_num[10010], up, a_size, b_size, c_size;

void add(char a, char b){
	if(a+b-48+up < 58){
		C[c_size++] = a+b-48+up;
		up = 0;
	}
	else{
		C[c_size++] = a+b-58+up;
		up = 1;
	}
}

void change_num(){
	c_size = max(a_size,b_size);
	if(A[0]=='-'){
		for(int i=0; i<a_size-1; i++)
			A_num[i] = '9' - A[a_size-i-1];
		for(int i=a_size-1; i<c_size; i++)
			A_num[i] = 9;
	}
	else {
		for(int i=0; i<a_size; i++)
			A_num[i] = A[a_size-i-1] - '0';
	}
	
	if(B[0]=='-'){
		for(int i=0; i<b_size-1; i++)
			B_num[i] = '9' - B[b_size-i-1];
		for(int i=b_size-1; i<c_size; i++)
			B_num[i] = 9;
	}
	else {
		for(int i=0; i<b_size; i++)
			B_num[i] = B[b_size-i-1] - '0';
	}
}


int main(){
	scanf("%s %s",&A,&B);
	
	a_size = strlen(A);
	b_size = strlen(B);
	
	if(A[0]=='-' && B[0]=='-'){ //둘다 음수
		printf("-");
		while(a_size>1 || b_size>1){
			if(a_size==1) add('0',B[--b_size]);
			else if(b_size==1) add(A[--a_size],'0');
			else add(A[--a_size],B[--b_size]);
		}
		
		if(up) printf("1");
		for(int i=c_size-1; i>=0; i--) printf("%c",C[i]);
	}
	else if(A[0]!='-' && B[0]!='-'){ //둘다 양수
		while(a_size>0 || b_size>0){
			if(a_size==0) add('0',B[--b_size]);
			else if(b_size==0) add(A[--a_size],'0');
			else add(A[--a_size],B[--b_size]);
		}
		
		if(up) printf("1");
		for(int i=c_size-1; i>=0; i--) printf("%c",C[i]);
	}
	else{ //하나만 음수
		change_num();
		bool flag = true;
		for(int i=0; i<c_size; i++){
			int tmp = A_num[i]+B_num[i]+up;
			if(tmp<10){
				C_num[i] = tmp;
				up=0;
				if(flag && C_num[i]==9){
					continue;
				}
				flag = false;
			}
			else{
				C_num[i] = tmp-10;
				up=1;
				if(flag && C_num[i]==9){
					continue;
				}
				flag = false;
			}
		}
		
		if(flag && up==0){
			printf("0");
			return 0;
		}
		if(up==1){
			for(int i=0; up!=0; i++){
				if(C_num[i] == 9){
					C_num[i] = 0;
				}
				else{
					C_num[i]++;
					up=0;
				}
			}
			c_size -= 1;
			while(C_num[c_size]==0){
				c_size--;
			}
			for(int i=c_size; i>=0; i--){
				printf("%d",C_num[i]);
			}
		}
		else{
			c_size -= 2;
			while(C_num[c_size]==9){
				c_size--;
			}
			printf("-");
			for(int i=c_size; i>=0; i--){
				printf("%d",9-C_num[i]);
			}
		}
	}
	
	return 0;
}