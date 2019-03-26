#include <iostream>

using namespace std;

int N;
int grade, total;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		int a, p;
		char subject[101], c[4];
		scanf("%s %d %s",subject,&a,c);
		grade += a;
		
		if(c[0] == 'A'){
			if(c[1] == '+') p = 43;
			else if(c[1] == '0') p = 40;
			else if(c[1] == '-') p = 37;
		} else if(c[0] == 'B'){
			if(c[1] == '+') p = 33;
			else if(c[1] == '0') p = 30;
			else if(c[1] == '-') p = 27;
		} else if(c[0] == 'C'){
			if(c[1] == '+') p = 23;
			else if(c[1] == '0') p = 20;
			else if(c[1] == '-') p = 17;
		} else if(c[0] == 'D'){
			if(c[1] == '+') p = 13;
			else if(c[1] == '0') p = 10;
			else if(c[1] == '-') p = 7;
		} else if(c[0] == 'F'){
			p = 0;
		}
		
		total += p*a;
	}
	
	int ans = (total*100)/grade;
	if(ans%10 >= 5) ans += 10;
	printf("%d.%d%d",ans/1000,(ans%1000)/100,(ans%100)/10);
	
	return 0;
}