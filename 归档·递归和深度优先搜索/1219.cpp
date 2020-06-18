#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=15;
int n,tot,a[N];
bool f[N];
void p(int k)
{
    if(k>n)
    {
        for(int i=1;i<=n;++i)//i(a,b)
            for(int j=i+1;j<=n;++j)//j(c,d)
                if(abs(a[i]-a[j])==abs(i-j))
                    return;
        ++tot;
        if(tot<=3)
        {
            for(int i=1;i<=n;++i)
                cout<<a[i]<<' ';
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=n;++i)
        if(!f[i])
        {//k-1层全部比较
            f[i]=1;
            a[k]=i;
            p(k+1);
            f[i]=0;
        }
}
int main()
{
    cin>>n;
    p(1);
    cout<<tot<<endl;
    return 0;
}
