#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

const int N=100005;

int n,c,a[N],ans;
int l,r,mid;

inline int longestDistance()
{
    int ans=1,pos=a[1];
    for(int i=1;i<=n;++i)
        if(a[i]-pos>=mid)
        {
            ++ans;
            pos=a[i];
        }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    r=a[n]-a[1];
    while(l<=r)
    {
        mid=(l+r)/2;
        int tot=longestDistance();
        if(tot>=mid)
        {
            l=mid+1;
            ans=mid;
        }
        else
            r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}