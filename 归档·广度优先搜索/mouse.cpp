#include<cstdio>
#include<iostream>
#include<string>
#include<queue>

using namespace std;

const int N=405;

struct node
{
    int x,y,step;
}p,t;

queue <node> q;
int m,n,used[N][N],ans[N][N],cnt=-1;
int startx,starty;
int tx,ty;
int dir[8][2]=
{
    1,2,1,-2,-1,2,-1,-2,
    2,1,2,-1,-2,1,-2,-1
};

void bfs(int x,int y)
{
    while(!q.empty())
    {
        t=q.front();
        //printf("** x: %d y: %d step: %d\n",t.x,t.y,t.step);
        q.pop();
        for(int i=0;i<8;++i)
        {
            tx=t.x+dir[i][0];
            ty=t.y+dir[i][1];
            //printf("> t.x : %d ; t.y : %d;\n",tx,ty);
            if(tx>=1 && tx<=n && ty>=1 && ty<=m)
                if(!used[tx][ty])
                {
                    //printf("IN tx: %d ty: %d\n",tx,ty);
                    used[tx][ty]=1;
                    p.x=tx;
                    p.y=ty;
                    p.step=t.step+1;
                    ans[p.x][p.y]=t.step+1;
                    q.push(p);
                }
        }
    }
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&startx,&starty);
    p.x=startx;
    p.y=starty;
    p.step=0;
    q.push(p);
    used[startx][starty]=1;
    bfs(p.x,p.y);
    return 0;
}