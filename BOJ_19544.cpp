#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m,a[510][510],vis[510];
ll ans=1,fac[510]={1};

struct node
{
    vi a;
    int t;
    node(){a.clear(); t=0;}
};

vector<node> cyc;

bool cycchk(node *p)
{
    if(p->a.size()==1) return false;
    for(auto i:p->a)
        for(int j=n;j--;)
        {
            bool flag=false;
            for(auto k:p->a) if(j==k) {flag=true; break;}
            if(flag!=a[i][j]) return false;
        }
    return true;
}

bool chk(int p, int q)
{
    for(auto i:cyc[q].a) if(p==i) return false;
    for(auto i:cyc[q].a) if(!a[p][i]) return false;
    for(int i=n;i--;)
        if(i!=p&&a[p][i])
        {
            bool ret=true;
            for(auto j:cyc[q].a) if(i==j) {ret=false; break;}
            if(ret) return false;
        }
    return true;
}

void Solve()
{
    cin>>n;
    for(int i=n;i--;)
        for(int j=n;j--;) cin>>a[i][j];
    for(int i=1;i<=n;i++) fac[i]=(fac[i-1]*(ll)i)%MOD;
    for(int i=n;i--;)
        if(!vis[i])
        {
            node tmp;
            for(int j=n;j--;) if(a[i][j]) tmp.a.pb(j),tmp.t++;
            if(cycchk(&tmp))
            {
                cyc.pb(tmp);
                for(auto i:tmp.a) vis[i]=1;
                ans*=fac[tmp.t-1]; ans%=MOD;
            }
        }
    for(int i=n;i--;)
        if(!vis[i])
            for(int j=cyc.size();j--;)
                if(chk(i,j)) ans*=cyc[j].t,ans%=MOD;

    cout<<ans;
}

int main(){
   // freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
