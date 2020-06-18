#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=100005;

int n,m,a,b;
int virusx[N],virusy[N],rulerx,rulery,dp[N];

int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=1;i<=a;++i)
        scanf("%d%d",&virusx[i],&virusy[i]);
    memset(dp,127,sizeof(dp));
    for(int i=1;i<=b;++i)
    {
        scanf("%d%d",&rulerx,&rulery);
        for(int j=1;j<=a;++j)
            dp[i]=min(dp[i],abs(virusx[j]-rulerx)+abs(virusy[j]-rulery));
    }
    
    for(int i=1;i<=b;++i)
        printf("%d\n",dp[i]);
    return 0;
}