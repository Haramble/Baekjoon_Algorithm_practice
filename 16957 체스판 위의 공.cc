#include <iostream>
#include <algorithm>

using namespace std;

int R, C, MAP[500][500], ans[500][500];
bool visit[500][500];
int dr[8] = {-1,-1,-1,0,0,1,1,1};
int dc[8] = {-1,0,1,-1,1,-1,0,1};
pair<int, int> dp[500][500];

pair<int, int> dpdfs(int r, int c, int ball_count){
	if(dp[r][c].first==r && dp[r][c].second==c){
		ans[r][c] += ball_count;
	}
	else{
		dp[r][c] = dpdfs(dp[r][c].first, dp[r][c].second, ball_count);
	}
	return dp[r][c];
}

void dfs(int r, int c, int ball_count){
	visit[r][c] = true;
	dp[r][c].first = r;
	dp[r][c].second = c;
	
	int MIN=MAP[r][c];
	for(int i=0; i<8; i++){
		int posR = r+dr[i];
		int posC = c+dc[i];
		if(posR>=0 && posC>=0 && posR<R && posC<C && MIN>MAP[posR][posC]){
			dp[r][c].first=posR;
			dp[r][c].second=posC;
			MIN=MAP[posR][posC];
		}
	}
	
	if(visit[dp[r][c].first][dp[r][c].second])
		dp[r][c] = dpdfs(dp[r][c].first, dp[r][c].second, ball_count);
	else
		dfs(dp[r][c].first, dp[r][c].second, ball_count+1);
}

int main(){
	std::ios::sync_with_stdio(false);
	cin >> R >> C;
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			cin >> MAP[i][j];
	
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			if(!visit[i][j]) dfs(i, j, 1);
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}
	
	return 0;
}