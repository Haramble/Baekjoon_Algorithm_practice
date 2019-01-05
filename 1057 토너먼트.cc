#include <cstdio>
int N, a,b, count;
int main(){
    scanf("%d %d %d",&N,&a,&b);
    while(a != b){ //a와 b가 같아지면 토너먼트에서 만남
        count++;
        a = a%2==0 ? a/2 : a/2+1; //a가 짝수면 반으로 줄이고 홀수면 반으로 줄이고+1
        b = b%2==0 ? b/2 : b/2+1; //b가 짝수면 반으로 줄이고 홀수면 반으로 줄이고+1
    }
    printf("%d",count);
    return 0;
}
