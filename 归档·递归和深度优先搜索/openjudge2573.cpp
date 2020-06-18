#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

const int N=45;

int r,c,ans=127;
int dir[4][2]={-1,0,1,0,0,-1,0,1},dp[N][N];
int tx,ty;
char maze[N][N];

void dfs(int x,int y,int step,int power)
{
    for(int i=0;i<4;++i)
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(maze[tx][ty]=='.' && dp[tx][ty]>dp[x][y]+1 && tx>=1 && tx<=r && ty>=1 && ty<=c)
        {
            dp[tx][ty]=dp[x][y]+1;
            dfs(tx,ty,step+1);
        }
    }
}

int main()
{
    scanf("%d%d",&r,&c);
    for(int i=1;i<=r;++i)
        for(int j=1;j<=c;++j)
        {
            cin>>maze[i][j];
            dp[i][j]=1<<30;
        }
    dp[1][1]=1;
    dfs(1,1,1);
    printf("%d\n",dp[r][c]);
    return 0;
}