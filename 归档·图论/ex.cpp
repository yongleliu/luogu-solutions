#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=20;

int n,g[N][N],vis[N],low[N];
int pos,mint,k=1;
int ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",&g[i][j]);
    memset(low,127,sizeof(low));
    for(int i=1;i<n;++i)
    {
        pos=k;
        vis[pos]=1;
        mint=1<<30;
        for(int j=1;j<=n;++j)//当前位置j
            if(!vis[j])
            {
                if(low[j]>g[pos][j])
                    low[j]=g[pos][j];
                if(mint>low[j])
                {
                    mint=low[j];
                    k=j;
                }
            }
        ans+=mint;
    }
    printf("%d\n",ans);
    return 0;
}