#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int N=5005,M=500005,mod=80112002;

struct node
{
    int next;
}p;

vector <node> v[N];
queue <int> q;

int n,m,dp[N];
int cnt,s[N],t;
int indegree[N],outdegree[N];

void Tsort()
{
    for(int i=1;i<=n;++i)
    {
        if(!indegree[i])
        {
            q.push(i);
            dp[i]=1;
        }    
        if(!outdegree[i])
        {
            ++cnt;
            s[cnt]=i;
        }
    }    
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        for(int i=0;i<v[t].size();++i)
        {
            int nextnum=v[t][i].next;
            if(indegree[nextnum])
            {
                --indegree[nextnum];
                dp[nextnum]=(dp[nextnum]+dp[t])%mod;
                if(!indegree[nextnum])
                    q.push(nextnum);
            }
        }    
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        p.next=y;
        v[x].push_back(p);
        ++outdegree[x];
        ++indegree[y];
    }
    Tsort();
    int tot=0;
    for(int i=1;i<=cnt;++i)
        tot=(tot+dp[s[i]]%mod)%mod;
    printf("%d\n",tot);
    return 0;
}