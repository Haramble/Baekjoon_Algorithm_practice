#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N;
pair<int,int> point[200000];
map<int,int> mp;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d %d %d",&point[i].first,&point[i+N].second,&point[i+N].first);
		point[i].second = -point[i+N].second; //건물의 시작부분 구분하기위해 음수로 저장
	}
	
	sort(point, point+2*N); //정렬
	
	map<int,int>::iterator it, Find;
	for(int i=0; i<2*N; i++){
		it = mp.begin();
		
		if(point[i].second < 0){ //만약 건물의 시작지점일때
			Find = mp.find(point[i].second); //같은 높이를 찾음
			if(Find != mp.end()) Find->second++; //이미 있는 높이라면 갯수 추가
			else mp.insert({point[i].second, 1}); //없다면 높이 하나 추가
			
			if(it->first != mp.begin()->first) //추가 후의 최대높이가 달라졌다면
				printf("%d %d ",point[i].first,-mp.begin()->first); //출력
		}
		else{ //건물의 끝부분일때
			Find = mp.find(-point[i].second); //같은 높이를 찾음
			if(Find->second == 1){ //그 높이가 하나밖에 없다면 삭제해줘야함
				int tmp = it->first; //현재 제일 높은 건물높이를 저장해놓고
				mp.erase(Find); //찾은걸 일단 삭제
				if(mp.empty()) printf("%d %d ",point[i].first,0); //삭제하고 mp가 비엇으면 0 출력
				else if(tmp != mp.begin()->first) printf("%d %d ",point[i].first,-mp.begin()->first); //삭제하고 제일 높은 건물높이가 바뀌었으면 바뀐 건물높이 출력
			}
			else Find -> second--; //그 높이가 여러개라면 하나 삭제
		}
	}
	
	return 0;
}