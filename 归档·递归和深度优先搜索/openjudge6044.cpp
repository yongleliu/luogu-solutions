#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int N=205,M=12;

int m,n,t,ans,cnt;
int dir[4][2]={-1,0,1,0,0,-1,0,1},dp[N][N][M];
int tx,ty,startx,starty,endx,endy;
char maze[N][N];

void dfs(int x,int y,int power)
{
    for(int i=0;i<4;++i)
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(tx>=1 && tx<=m && ty>=1 && ty<=n)
        {
            if(maze[tx][ty]=='#')
            {
                if(power && dp[tx][ty][power-1] > dp[x][y][power]+1)
                {
                    dp[tx][ty][power-1]=dp[x][y][power]+1;
                    dfs(tx,ty,power-1);
                }
            }
            else
            {
                if(dp[tx][ty][power] > dp[x][y][power]+1)
                {
                    dp[tx][ty][power]=dp[x][y][power]+1;
                    dfs(tx,ty,power);
                }
            }
        }
    }
}

int main()
{
    memset(dp,127,sizeof(dp));
    scanf("%d%d%d",&m,&n,&t);
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
        {
            cin>>maze[i][j];
            if(maze[i][j]=='@')
            {
                dp[i][j][t]=0;
                startx=i;
                starty=j;
            }
            if(maze[i][j]=='+')
            {
                endx=i;
                endy=j;
            }
        }
    dfs(startx,starty,t);
    ans=1<<30;
    for(int i=0;i<=t;++i)
        if(dp[endx][endy][i]<ans)
        {
            ans=dp[endx][endy][i];
            ++cnt;
        }
    if(!cnt)
        printf("-1\n");
    else
        printf("%d\n",ans);
    return 0;
}