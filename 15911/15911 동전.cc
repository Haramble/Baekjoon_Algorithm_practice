#include <cstdio>
/*
동전이 N개 있을 때 N-1개의 동전의 앞면이 홀수개 나올 확률을 p라고 하고,
마지막 1개가 앞면이 나올 확률을 q라고 하면
ALIVE 확률 즉 N개의 동전의 앞면이 홀수개가 나올 확률은
(N-1개 동전중 앞면이 홀수개)*(마지막 동전이 뒷면) + (N-1개 동전중 앞면이 짝수개)*(마지막 동전이 앞면)이므로
p*(1-q) + (1-p)*q로 나타낼 수 있다.

위 식을 상황별로 나누면
1) p 혹은 q가 0.5 일때
		p*(1-q) + (1-p)*q = 0.5
2) p>0.5 && q>0.5일 때
		p*(1-q) + (1-p)*q < 0.5
3) p>0.5 && q<0.5일 때
		p*(1-q) + (1-p)*q > 0.5
4) p<0.5 && q>0.5 일 때
		p*(1-q) + (1-p)*q > 0.5
5) p<0.5 && q<0.5 일 때
		p*(1-q) + (1-p)*q < 0.5

위 상황을 동전이 두개일 때 부터 하나씩 생각해 보면
앞면이 나올 확률이 0.5인 동전이 하나라도 있으면 SAME이고,
앞면이 나올 확률이 0.5보다 큰 동전수가 짝수개 이면 DEAD이고,
앞면이 나올 확률이 0.5보다 큰 동전수가 홀수개 이면 ALIVE인 것을 알 수 있다.

따라서 입력을 받을 때 확률이 0.5이상인 동전 갯수를 알아놓고,
바뀌는 것에 따라서 상태를 결정하면 된다.
*/
int N, M, Front, Half; //동전갯수 : N, 바꾼횟수 : M, 0.5이상인동전갯수:Front, 0.5인동전갯수 : Half
int main(){
	scanf("%d %d",&N,&M);
	int coin[N+1];
	//동전별로 coin[i]가 0이면 i번째 동전이 0.5이하인 동전, 1이면 i번째 동전이 0.5이상인 동전, 2이면 i번째 동전이 0.5인 동전으로 나눈다
	for(int i=1; i<=N; i++){
		 double a;
		 scanf("%lf",&a);
		 if(a>0.5){ //확률이 0.5 이상이면 coin[i]에 1을 넣고, Front증가
		 	coin[i]=1; Front++;
		 }
		 else if(a == 0.5){ //확률이 0.5 이면 coin[i]에 2을 넣고, Half증가
		 	coin[i]=2; Half++;
		 }
		 else coin[i]=0; //확률이 0.5 이하이면 coin[i]에 0을 넣음
	}

//출력부분, Half가 하나라도 있으면 SAME, Front동전이 홀수개 있으면 ALIVE, FRONT동전이 짝수개 있으면 DEAD
	if(Half>0) printf("SAME\n");
	else if(Front%2 == 1) printf("ALIVE\n");
	else printf("DEAD\n");

	while(M--){ //M번 바꾸는 만큼 반복
		int n;
		double a;
		scanf("%d %lf",&n,&a);
		if(coin[n]==1){ //바꿀 동전이 원래 0.5 이상이었고
			if(a<0.5){ //바꿀 확률이 0.5 이하이면
				coin[n]=0; //coin을 0으로 바꾸고
				Front--; //Front 감소
			}
			else if(a==0.5){ //바꿀 확률이 0.5이면
				coin[n]=2; //coin을 2로 바꾸고
				Front--; Half++; //Front 감소, Half 증가
			}
		}

		else if(coin[n]==2){ //바꿀 동전이 원래 0.5 였고
			if(a<0.5){ //바꿀 확률이 0.5 이하이면
				coin[n]=0; //coin을 0으로 바꾸고
				Half--; //Half 감소
			}
			else if(a>0.5){ //바꿀 확률이 0.5 이상이면
				coin[n]=1; //coin을 1로 바꾸고
				Half--; Front++; //Half 감소, Front 증가
			}
		}

		else { //바꿀 동전이 원래 0.5 이하였고
			if(a>0.5){ //바꿀 확률이 0.5 이상이면
				coin[n]=1; //coin을 1로 바꾸고
				Front++; //Front 증가
			}
			else if(a==0.5){ //바꿀 확률이 0.5이면
				coin[n]=2; //coin을 2로 바꾸고
				Half++; //Half 증가
			}
		}

//출력부분, Half가 하나라도 있으면 SAME, Front동전이 홀수개 있으면 ALIVE, FRONT동전이 짝수개 있으면 DEAD
		if(Half>0) printf("SAME\n");
		else if(Front%2 == 1) printf("ALIVE\n");
		else printf("DEAD\n");
	}


	return 0;
}
