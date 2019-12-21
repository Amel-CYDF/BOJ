#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1001
#define SOURCE 0
#define BUMP 2019
#define SINK 2020

int n,m,k,a[1<<11][1<<11],now[1<<11][1<<11],ans,lev[1<<11],work[1<<11];
vector<int> ed[1<<11];

int dfs(int p,int maxflow)
{
    if(p==SINK) return maxflow;
    for(int &ii=work[p];ii<ed[p].size();ii++)
    {
        int i=ed[p][ii];
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
 //   freopen("input.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1,s;i<=n;i++)
    {
        scanf("%d",&s);
        for(int j=0,t;j<s;j++)
            scanf("%d",&t),t+=1<<10,
            a[i][t]=1, ed[i].push_back(t),ed[t].push_back(i);
    }
    for(int i=1;i<=n;i++) a[SOURCE][i]=1,a[BUMP][i]=1,ed[BUMP].push_back(i),ed[SOURCE].push_back(i);
    for(int i=(1<<10)+1;i<=(1<<10)+m;i++) a[i][SINK]=1,ed[i].push_back(SINK);
    ed[SOURCE].push_back(BUMP); a[SOURCE][BUMP]=k;
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
            for(int i:ed[p])
                if(!lev[i]&&now[p][i]<a[p][i])
                    lev[i]=lev[p]+1,flow.push(i);
        }
        if(!lev[SINK]) break;
        for(int tmp;tmp=dfs(SOURCE,INT_MAX);ans+=tmp) ;
    }
    printf("%d",ans);
    return 0;
}
