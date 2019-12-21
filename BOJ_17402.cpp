#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 210
#define MOD 1000000007

int n,m,k,no[N][N],vis[N],a[N];

bool dfs(int p)
{
    if(vis[p]) return 0;
    vis[p]=1;
    for(int i=1;i<=m;i++)
        if(no[p][i]&&(!a[i]||dfs(a[i])))
            {a[i]=p; return 1;}
    return 0;
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0,s,t;i<k;i++)
        scanf("%d %d",&s,&t),no[s][t]=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        ans+=dfs(i);
    }
    printf("%d",n+m-ans);
    return 0;
}