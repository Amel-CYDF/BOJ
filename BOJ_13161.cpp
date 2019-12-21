#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 510
#define MOD 1001
#define SOURCE 0
#define SINK 505

int n,a[N][N],now[N][N],ans,lev[N],work[N],where[N];
vector<int> ed;

int dfs(int p,int maxflow)
{
    if(p==SINK) return maxflow;
    for(int &ii=work[p];ii<ed.size();ii++)
        if(ed[ii]!=p)
        {
            int i=ed[ii];
            if(lev[i]==lev[p]+1&&now[p][i]<a[p][i])
            {
                int ret=min(maxflow,dfs(i,min(maxflow,a[p][i]-now[p][i])));
                if(ret>0)
                {
                    now[p][i]+=ret; now[i][p]-=ret;
                    return ret;
                }
            }
        }
    return 0;
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",where+i);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",a[i]+j);
    for(int i=1;i<=n;i++)
        if(where[i])
            for(int j=1,s,t;j<=n;j++)
                if(where[i]!=where[j])
                {
                    s=where[i]&1?SOURCE:SINK;
                    t=j;
                    if(where[j]) t=where[j]&1?SOURCE:SINK;
                    a[s][t]+=a[i][j];
                }
    for(int i=0;i<N;i++) a[i][SOURCE]=a[SOURCE][i],a[i][SINK]=a[SINK][i];
    for(int i=1;i<=n;i++) if(!where[i]) ed.push_back(i);
    ed.push_back(SOURCE); ed.push_back(SINK);
    while(1)
    {
        memset(lev,0,sizeof(lev));
        memset(work,0,sizeof(work));
        queue<int> flow;
        flow.push(SOURCE); lev[SOURCE]=1;
        while(!flow.empty())
        {
            int p=flow.front(); flow.pop();
            if(lev[SINK]) break;
            for(int i:ed)
                if(i!=p&&!lev[i]&&now[p][i]<a[p][i])
                    lev[i]=lev[p]+1,flow.push(i);
        }
        if(!lev[SINK]) break;
        for(int tmp;tmp=dfs(SOURCE,INT_MAX);ans+=tmp) ;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        if(!where[i]) where[i]=lev[i]?1:2;
    for(int i=1;i<=n;i++)
        if(where[i]&1) printf("%d ",i);
    puts("");
    for(int i=1;i<=n;i++)
        if(where[i]&2) printf("%d ",i);
    puts("");
    return 0;
}
