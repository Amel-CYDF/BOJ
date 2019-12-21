#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 100010
#define MOD 15746

int n,m,par[N][18],vis[N],lev[N];
list<int> ed[N];

void dfs(int p,int up,int h)
{
    if(vis[p]) return;
    vis[p]=1; par[p][0]=up; lev[p]=h;
    for(int i:ed[p]) dfs(i,p,h+1);
}

void goup(int &p,int h)
{
    for(int i=0;h;h>>=1,i++)
         if(h&1) p=par[p][i];
}

int lca(int p,int q)
{
    lev[p]<lev[q]?goup(q,lev[q]-lev[p]):goup(p,lev[p]-lev[q]);
    if(p==q) return p;
    for(int i=17;i>=0;i--)
        if(par[p][i]!=par[q][i]) p=par[p][i],q=par[q][i];
    return par[p][0];
}

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1,s,t;i<n;i++) scanf("%d %d",&s,&t),ed[s].push_back(t),ed[t].push_back(s);
    dfs(1,1,0);
    for(int i=1;1<<i<n;i++)
        for(int j=1;j<=n;j++) par[j][i]=par[par[j][i-1]][i-1];
    scanf("%d",&m);
    for(int p,q;~scanf("%d %d",&p,&q);printf("%d\n",lca(p,q))) ;
    return 0;
}
