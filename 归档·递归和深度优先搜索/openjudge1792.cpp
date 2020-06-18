#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int N=105;

int n,k;
int ha,la,hb,lb;
int used[N][N];
char maze[N][N];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int tx,ty;

void dfs(int x,int y)
{
    if(x==hb && y==lb)
    {
        return ;
    }
    for(int i=0;i<4;++i)
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(!used[tx][ty] && maze[tx][ty]!='#' && tx>=0 && tx<n && ty>=0 && ty<n)
        {
            used[tx][ty]=1;
            dfs(tx,ty);
        }
    }
}


int main()
{
    scanf("%d",&k);
    for(int q=1;q<=k;++q)
    {
        memset(used,0,sizeof(used));
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                cin>>maze[i][j];
        scanf("%d%d%d%d",&ha,&la,&hb,&lb);
        if(maze[ha][la]=='#')
        {
            printf("NO\n");
            continue;
        }
        used[ha][la]=1;
        dfs(ha,la);
        if(!used[hb][lb])
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}