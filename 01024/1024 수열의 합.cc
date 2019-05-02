#include <cstdio>
/*
등차수열의 합 공식 : S = {n(2a + (n-1)d)} / 2

위 식에서 연속된 숫자 이므로 공차 d = 1로 함
수열의 갯수 n = L로 함
수열의 합 S = N으로 하고 시작점 a 찾기.

예외처리
시작점 a가 음의정수이면 -1출력
L이 100을 넘어가면 -1출력
*/

int N, L, a;
int main(){
    scanf("%d %d",&N,&L);
    while(1){
        if((2*N - (L-1)*L) % (2*L)){ //나누어 떨어지지 않으면 L을 증가시킴
            L++;
            if(L>100){ //예외처리
                printf("-1");
                break;
            }
        }
        else{
            a = (2*N - (L-1)*L) / (2*L); //등차수열의 합 공식 변형하여 a값 구함
            if(a < 0) //예외처리
                printf("-1");
            else
                for(int i=0; i<L; i++)
                    printf("%d ",a+i);
            break;
        }
    }
    return 0;
}
