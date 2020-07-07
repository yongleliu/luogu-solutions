#pragma GCC optimize(3)
#include<cstdio>

using namespace std;

const int N=1000005,M=2005;

int n,m,a[N];
int l,r,mid;

inline int totalArtists()
{
    int ans=0,vis[M];
    for(int i=1;i<=m;++i)
        if(!vis[a[i]])
        {
            ++ans;
            vis[a[i]]=true;
        }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    r=m;
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    while(l<=r)
    {
        mid=(l+r)/2;
        int tot=totalArtists();
        if(tot<=mid)
            {}
    }
    return 0;
}