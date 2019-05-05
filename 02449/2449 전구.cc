#include <iostream>

using namespace std;
/*
dp[i][j] 를 i~j까지 전구색을 같게만드는 최소 횟수라고 정의하면

dp[i][j] 는 i와 j사이의 k에 대해서
i~k까지 전구색을 같게하고, k+1~j까지 전구색 같게한 다음
두 그룹을 색을 같게하는 횟수 중에 최소값이다.

그리고 여기서 i~k와 k+1~j까지 그룹의 전구색을 같게할 때 제일 앞에있는 전구색으로 같게한다고 가정한다.

이것을 식으로 나타내면
if(i번째 전구와 k+1번째 전구 색이 같은경우) dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j])
else(i번째 전구와 k+1번째 전구 색이 다른경우) dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+1)
이 된다.
*/
int N, K, arr[200], arr_size;

int main(){
	scanf("%d %d",&N,&K);
	scanf("%d",&arr[arr_size++]);
	for(int i=1; i<N; i++){ //같은 전구색이 연속으로 들어오는것은 전구 한개로 봐도 되기때문에 압축
		scanf("%d",&arr[arr_size]);
		if(arr[arr_size] != arr[arr_size-1]) arr_size++;
	}

	int dp[arr_size][arr_size];

	for(int i=0; i<arr_size; i++) dp[i][i] = 0; //초기화
	for(int j=1; j<arr_size; j++){
		for(int i=j-1; i>=0; i--){ //(i,i+1) 부터 (0,i+1) 순서로 아래에서 위로 채워나감
			int tmp = 2000;
			for(int k=i; k<j; k++){ //위의 dp식 구현
				if(arr[i]!=arr[k+1]) tmp = min(tmp,dp[i][k]+dp[k+1][j]+1);
				else tmp = min(tmp,dp[i][k]+dp[k+1][j]);
			}
			dp[i][j] = tmp;
		}
	}
	
	/*for(int i=0; i<arr_size; i++){
		for(int j=0; j<arr_size; j++){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}*/
	
	printf("%d",dp[0][arr_size-1]);
	return 0;
}