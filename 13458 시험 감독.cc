#include <cstdio>
int N, B, C;
long long count; //count가 int 범위를 넘어갈 수 있으므로 long long으로 선언
int main(){
    scanf("%d",&N);
    int A[N];
    for(int i=0; i<N; i++)
        scanf("%d",&A[i]);
    scanf("%d %d",&B,&C);

    count = N; //모든 시험장에는 총시험관이 무조건 한명 있어야 함
    for(int i=0; i<N; i++){
        int a = A[i]-B; //총시험관이 관리 가능한 인원 빼준다
        if(a > 0) //나머지는 부시험관이 관리한다
            count += (a%C==0 ? a/C : a/C + 1); //부시험관의 최소수만큼 더함
    }

    printf("%lld",count);
    return 0;
}
