#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;

const ll M=1005;

ll t,n,h,r;
ll x[M],y[M],z[M];
ll way[M][M],used[M];
bool f;

ll area(ll n)
{
    return n*n;
}

void dfs(ll k)
{
    if(f)
        return ;
    if(z[k]>=h-r)
    {
        f=true;
        return ;
    }
    for(int i=1;i<=n;++i)
        if(!used[i]&&way[k][i])
        {
            used[i]=1;
            dfs(i);
        }
}

int main()
{
    scanf("%lld",&t);
    for(int ques=1;ques<=t;++ques)
    {
        memset(used,0,sizeof(used));
        memset(way,0,sizeof(way));
        f=false;
        scanf("%lld%lld%lld",&n,&h,&r);
        for(int i=1;i<=n;++i)
            scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
        for(int i=1;i<n;++i)
            for(int j=i+1;j<=n;++j)
            {
                double s=sqrt(1.0*area(x[i]-x[j])+area(y[i]-y[j])+area(z[i]-z[j]));
                if(s<=2.0*r)
                    way[i][j]=way[j][i]=1;
            }
        for(int i=1;i<=n;++i)
            if(z[i]<=r)
            {
                used[i]=1;
                dfs(i);
            }
        if(f)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}