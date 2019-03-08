#include <iostream>

using namespace std;

int h, s;
bool flag1, flag2;

int main(){
	char c;
	while((c=getchar()) != EOF){
		if(flag1==false && c==':'){
			flag1=true;
		}
		else if(flag1==true && flag2==false && c=='-'){
			flag2=true;
		}
		else if(flag1==true && flag2==true && c==')'){
			flag1 = flag2 = false;
			h++;
		}
		else if(flag1==true && flag2==true && c=='('){
			flag1 = flag2 = false;
			s++;
		}
		else{
			flag1 = flag2 = false;
		}
	}
	
	if(h>s) printf("happy");
	else if(h==s){
		if(h==0) printf("none");
		else printf("unsure");
	}
	else printf("sad");
	
	//printf("\n%d %d",h,s);
	return 0;
}