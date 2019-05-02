#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int main(){
	scanf("%d",&N);
	pair<int, int> arr[N]; //x좌표, y좌표를 입력받기 위해서 pair로 선언
	for(int i=0; i<N; i++)
		scanf("%d %d",&arr[i].first,&arr[i].second); //x좌표는 first, y좌표는 second
	sort(arr, arr+N); //pair를 sort하면 먼저 first기준으로 정렬된 후, first가 같은값들은 second기준으로 정렬된다
	for(int i=0; i<N; i++)
		printf("%d %d\n",arr[i].first,arr[i].second); //그대로 출력
	return 0;
}
