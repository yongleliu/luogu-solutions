#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
string s;
int n,a[N],g,r,ans=-1<<30;//g=-1,r=1
int main()
{
	cin>>s;
	n=s.length();
	for(int i=1;i<=n;++i)//��G��Rת��Ϊ-1��1������ת��Ϊ���Ϊ0��������ִ� 
		if(s[i-1]=='R')
			a[i]=1;
		else
			a[i]=-1;
	for(int i=1;i<=n;++i)
	{
		if(a[i]==-1)
			++g;
		else
			++r;
		if(g!=0&&r!=0)
			ans=max(ans,min(g,r)*2);
	}
	cout<<ans<<endl;
	return 0;
}
