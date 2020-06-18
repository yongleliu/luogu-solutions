#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int N=25;

int w,h;
int tx,ty,dir[4][2]={1,0,-1,0,0,1,0,-1};
char maze[N][N],used[N][N];
int ha,la,ans;

void dfs(int x,int y)
{
    for(int i=0;i<4;++i)
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(!used[tx][ty] && maze[tx][ty]!='#' && tx>=0 && tx<h && ty>=0 && ty<w)
        {
            used[tx][ty]=1;
            ++ans;
            dfs(tx,ty);
        }
    }
}

int main()
{
    while(1)
    {
        scanf("%d%d",&w,&h);//width, height
        if(w==0&&h==0)
            break;
        ans=1;
        memset(used,0,sizeof(used));
        for(int i=0;i<h;++i)
            for(int j=0;j<w;++j)
            {
                cin>>maze[i][j];
                if(maze[i][j]=='@')
                {
                    ha=i;
                    la=j;
                }
            }
        used[ha][la]=1;
        dfs(ha,la);
        printf("%d\n",ans);
    }
    return 0;
}