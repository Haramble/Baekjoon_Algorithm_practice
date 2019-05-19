#include <iostream>

using namespace std;
/*
문자열이 s1 s2가 있을 때
s2를 s1으로 바꾸는 최소 횟수를 구하기.

DP[i][j]를 s2의 0~i-1번째 문자열을 s1의 0~j-1번째 문자열로 바꾸는 최소 횟수라고 정의.
(DP[i][0]과 DP[0][i]는 i로 초기화)

만약 s2[i]과 s1[j]가 같다면 DP[i][j] = DP[i-1][j-1]이고
다르다면 DP[i][j] = min(DP[i-1][j-1],DP[i-1][j],DP[i][j-1])+1 이다.

추가설명
DP[i][j-1] + 1 : s2의 0~i-1번째 문자열을 s1의 0~j-2번째 문자열로 바꾸고 마지막에 s1[j-1]추가
D[i-1][j] + 1 : s2의 0~i-1번째 문자열의 마지막 문자열을 빼고, 0~i-2번째 문자열을 s1의 0~j-1번째 문자열로 바꾸기
D[i-1][j-1] + 1 : s2의 0~i-2번째 문자열을 s1의 0~j-2문자열로 바꾸고 마지막에 s1[j-1] 추가
*/
string s1, s2;
int DP[1001][1001];

int main(){
	cin >> s1 >> s2;

	for(int i=1; i<=s1.size(); i++) DP[0][i] = i;
	for(int i=1; i<=s2.size(); i++) DP[i][0] = i;

	for(int i=1; i<=s2.size(); i++){
		for(int j=1; j<=s1.size(); j++){
			if(s2[i-1] == s1[j-1]) DP[i][j] = DP[i-1][j-1];
			else DP[i][j] = min(DP[i-1][j-1],min(DP[i-1][j],DP[i][j-1]))+1;
		}
	}

	cout << DP[s2.size()][s1.size()];
	return 0;
}
