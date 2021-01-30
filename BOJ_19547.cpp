#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007

int n,m;
vl up;
vector<vl> down;
vector<vector<pair<int,pii>>> ed;

void suminit(int p, int r, vl *q)
{
    auto t=q->begin(); *t=0; ++t;
    ll pre=0;
    for(int i=0;i<r;i++,++t) *t=(pre+down[p][i])%MOD, pre=*t;
}

void dfs(int p,int r,int lf,int rg,int par)
{
    bool fl=false;
    for(auto i:ed[p])
        if(i.ff!=par)
        {
            dfs(i.ff,r,i.ss.ff,i.ss.ss,p);
            if(fl)
            {
                vl mysum(r+1),childsum(r+1);
                suminit(p,r,&mysum); suminit(i.ff,r,&childsum);
                ll tmp=up[p]*up[i.ff]%MOD;
                for(int j=1;j<r;j++)
                {
                    tmp+=up[p]*down[i.ff][j]+up[i.ff]*down[p][j]; tmp%=MOD;
                    tmp+=down[p][j]*(childsum[r]-childsum[max(r-j,j)]+MOD); tmp%=MOD;
                    tmp+=down[i.ff][j]*(mysum[r]-mysum[max(r-j,j+1)]+MOD); tmp%=MOD;
                    down[p][j]=down[p][j]*childsum[min(j,r-1-j)+1]; down[p][j]%=MOD;
                    down[p][j]+=down[i.ff][j]*mysum[min(j-1,r-1-j)+1]; down[p][j]%=MOD;
                }
                up[p]=tmp;
            }
            else
            {
                down[p]=down[i.ff];
                up[p]=up[i.ff];
                fl=true;
            }
        }
    if(!p) return;
    if(ed[p].size()==1) down[p][0]=1;
    up[p]*=rg-lf+1; up[p]%=MOD;
    for(int i=max(0,r-rg);i<r;i++)
        up[p]+= down[p][i] * (i+rg-max(r,i+lf)+1), up[p]%=MOD;
    vl tmp(r+1);
    suminit(p,r,&tmp);
    for(int i=min(r,lf);i--;) down[p][i]=0;
    for(int i=lf;i<r;i++)
        down[p][i]=(tmp[i-lf+1] - tmp[max(i-rg,0)] + MOD)%MOD;
    down[p][0]=0;
}

void clr(int p)
{
    for(auto &i:up) i=0;
    for(auto &i:down)
    {
        i.resize(p);
        for(auto &j:i) j=0;
    }
}

void Solve()
{
    int lf,rg;
    cin>>n>>lf>>rg;
    up.resize(n);
    down.resize(n);
    ed.resize(n);
    lf=min(lf,(n-1)*400);
    rg=min(rg,(n-1)*400);
    for(int i=n-1,s,e,l,r;i--;)
    {
        cin>>s>>e>>l>>r;
        s--; e--;
        ed[s].pb(mp(e,mp(l,r)));
        ed[e].pb(mp(s,mp(l,r)));
    }
    clr(lf); dfs(0,lf,0,0,0);
    ll ans=up[0];
    clr(rg+1); dfs(0,rg+1,0,0,0);
    cout<<(ans-up[0]+MOD)%MOD;
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
}
int main(){ Init(0); //ios::sync_with_stdio(false); cin.tie(NULL);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
