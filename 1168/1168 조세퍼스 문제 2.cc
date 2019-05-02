#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
이 문제는 시간제한이 1초이므로 큐를 이용한 풀이는 시간제한에 걸린다.
그래서 벡터를 이용해서 원하는 인덱스에 접근하여 출력하고
출력한 값을 벡터에서 지우는 방식으로 구현했다.
*/
int N, M;

int main(){
	scanf("%d %d",&N,&M);
	vector<int> v;
	v.push_back(N);
	for(int i=1; i<N; i++) v.push_back(i);

  	int a = N; //줄어드는 벡터의 길이를 저장하는 변수
  	vector<int>::iterator it = v.begin(); //벡터에 접근하기 위한 반복자
	printf("<");
	for(int i=0; i<N-1; i++){
		it += M; //M번째 값을 가리키게 한다
		if(it >= v.end()){ //만약 가리키는 값이 벡터의 끝부분을 벗어나면
			while(1){
				it -= a; //벡터 안의 값을 가리키게 현재 벡터의 길이만큼 계속 빼준다
				if(it < v.end()) break;
			}
		}
		printf("%d, ",*it); //지금 가리키고 있는 값을 출력하고
		v.erase(it); //지워준다
		it--; a--; //지웠으므로 반복자는 뒤에 값을 가리키고 있다 그래서 하나 줄여주고, a값도 줄여준다.
	}
	printf("%d>",v[0]); //마지막남은 값 출력하고 '>'도 출력한다

	return 0;
}
