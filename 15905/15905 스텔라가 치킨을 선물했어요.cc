#include <cstdio>
#include <algorithm>

using namespace std;

int N, ret;
int main(){
	scanf("%d",&N);
	pair<int, int> student[N]; //푼 문제수와 패널티점수를 입력받기위해 pair로 선언
	for(int i=0; i<N; i++){
		int a, b;
		scanf("%d %d",&a,&b);
		student[i].first = a*(-1); //푼문제가 많을수록 좋고, 패널티가 적을수록 좋으므로 푼문제를 음수로 바꿔서 입력
		student[i].second = b;
	}
	sort(student, student+N); //pair를 정렬하면 먼저 first로 정렬되고, first가 같은값들은 second값으로 정렬된다

	for(int i=5; student[4].first == student[i].first; i++) //5등과 푼 문제수가 같은 사람들을 찾는다
		ret++;
	printf("%d",ret); //출력

	return 0;
}
