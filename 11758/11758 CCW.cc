#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> p1,p2,p3;
int a,b,c,d;

int main(){
	scanf("%d %d",&p1.first,&p1.second);
	scanf("%d %d",&p2.first,&p2.second);
	scanf("%d %d",&p3.first,&p3.second);
	a = p2.first-p1.first;
	b = p2.second-p1.second;
	c = p3.first-p2.first;
	d = p3.second-p2.second;
	
	if(a*d-b*c > 0) printf("1");
	else if(a*d-b*c < 0) printf("-1");
	else printf("0");
	return 0;
}