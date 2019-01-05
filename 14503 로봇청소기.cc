#include <cstdio>

struct ROBOT{
    int x, y, d;
}; //로봇청소기의 x좌표, y좌표, 방향을 가진 구조체

int Room[50][50]; //방
int N,M,count; //N,M은 방의 크기, count는 청소하는 구역의 수
int xdir[4] = {0,1,0,-1}; //동서남북 순으로 이동할 때의 x값
int ydir[4] = {-1,0,1,0}; //동서남북 순으로 이동할 때의 y값
bool Shutdown; //로봇청소기 작동 정지변수

int main(){
    ROBOT rob;
    scanf("%d %d %d %d %d",&N,&M,&rob.y,&rob.x,&rob.d);

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d",&Room[i][j]);

    while(!Shutdown){
        if(Room[rob.y][rob.x] == 0){ //현재위치가 청소안되어있으면 청소한다
            Room[rob.y][rob.x] = 3;
            count++;
        }

        int Dcount = 0; //방향을 몇번움직이는지 카운트
        for(; Dcount<4; Dcount++){
            ROBOT next; //다음 로봇청소기가 있을곳으로 next선언
            next.d = (rob.d+3-Dcount)%4; //로봇청소기의 방향은 0,3,2,1순서로 변해야 함
            next.x = rob.x+xdir[next.d];
            next.y = rob.y+ydir[next.d];
            if(Room[next.y][next.x] == 0){ //만약 청소되어있지 않은 부분이 있다면 그곳으로 이동
                rob.x = next.x;
                rob.y = next.y;
                rob.d = next.d;
                break;
            }
        }

        if(Dcount == 4){ //4방향 다 탐색했는데도 청소할 곳이 없다면 후진
            rob.x = rob.x+xdir[(rob.d+2)%4];
            rob.y = rob.y+ydir[(rob.d+2)%4];
            if(Room[rob.y][rob.x] == 1) //후진할 곳이 없으면 Shutdown
                Shutdown = true;
        }
    }

    printf("%d",count);
    return 0;
}
