#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1010
#define M 0
#define MOD 15746

int n,m,par[N],ans;

int pfind(int p)
{
    if(par[p]==p) return p;
    return par[p]=pfind(par[p]);
}

void uni(int p,int q)
{
    p=pfind(p); q=pfind(q);
    if(p==q) return;
    par[q]=p;
}

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++) par[i]=i;
    while(~scanf("%d %d",&n,&m)) uni(n,m);
    for(int i=1;par[i];i++) if(par[i]==i) ans++;
    cout<<ans;
    return 0;
}
