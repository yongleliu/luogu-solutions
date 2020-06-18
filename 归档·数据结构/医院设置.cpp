#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;

const int N=105;

int n,l,r,mini=1<<30,tot;
int a[N],g[N][N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            g[i][j]=1000000;
    for(int i=1;i<=n;++i)
    {
        g[i][i]=0;
        scanf("%d%d%d",&a[i],&l,&r);
        if(l>0)
            g[i][l]=g[l][i]=1;
        if(r>0)
            g[i][r]=g[r][i]=1;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i!=j)
                for(int k=1;k<=n;++k)
                    if(i!=k && j!=k && g[j][i]+g[i][k]<g[j][k])
                        g[j][k]=g[j][i]+g[i][k];
    for(int i=1;i<=n;++i)
    {
        tot=0;
        for(int j=1;j<=n;++j)
            tot+=g[i][j]*a[j];
        if(tot<mini)
            mini=tot;
    }
    printf("%d\n",mini);
    return 0;
}