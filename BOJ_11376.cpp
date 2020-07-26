#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

int n,m,b[1010],ans,vis[2020];
list<int> ed[1010];

bool dfs(int p)
{
    if(vis[p]) return 0;
    vis[p]=1;
    for(auto i:ed[p>>1])
        if(!~b[i]||dfs(b[i])) {b[i]=p; return 1;}
    return 0;
}

int main(){
    freopen("input.txt","r",stdin);
//    int tc; cin>>tc;
    cin>>n>>m;
    for(int i=0,j;~scanf("%d",&j);i++)
        for(int k=j,u;k--;) scanf("%d",&u),ed[i].pb(u);
    n<<=1;
    memset(b,-1,sizeof(b));
    for(int i=n;i--;)
    {
        memset(vis,0,sizeof(vis));
        ans+=dfs(i);
    }
    cout<<ans;
    return 0;
}
