#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1'000'000'009

int n,m;
vpii a;
vi b;

struct segtree
{
    int a[100'000<<2],siz;
    void init(int p)
    {
        memset(a,1,sizeof(a));
        for(siz=1;siz<p;siz<<=1);
    }
    void upd(int pos,int p)
    {
        a[pos+=siz]=p;
        for(pos>>=1;pos;pos>>=1) a[pos]=min(a[pos*2],a[pos*2+1]);
    }
    int findmin(int lf,int rg)
    {
        if(lf>rg) return INT_MAX;
        lf+=siz; rg+=siz;
        int ret=INT_MAX;
        while(lf<rg)
        {
            if(lf&1) ret=min(ret,a[lf++]);
            else if(~rg&1) ret=min(ret,a[rg--]);
            else lf>>=1,rg>>=1;
        }
        return min(ret,a[lf]);
    }
}r;

void Solve()
{
    cin>>m>>n;
    a.resize(n);
    b.resize(n);
    r.init(n);
    for(auto &i:a) cin>>i.ff;
    for(auto &i:a) cin>>i.ss;
    b.front()=0;
    for(int i=1;i<n;i++)
        b[i]=a[i].ss==a[i-1].ss?b[i-1]:i;
    for(int i=0;i<n;i++)
    {
        int ret=r.findmin(b[i],i-1);
        if(b[i])
        {
            int p=b[b[i]-1],q=b[i]-1;
            int x=a[q].ff*2-a[i].ff,y=a[q+1].ff*2-a[i].ff;
            int lf=lower_bound(a.begin()+p,a.begin()+q+1,mp(x,0))-a.begin(),
                rg=upper_bound(a.begin()+p,a.begin()+q+1,mp(y,INT_MAX))-a.begin()-1;
            if(lf<=q&&rg>=p&&lf<=rg) ret=min(ret,r.findmin(lf,rg));
        }
        else ret=0;
        r.upd(i,ret+1);
    }
    cout<<r.findmin(b.back(),n-1);
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){Init(0);
//    int tc; cin>>tc; for(int i=1;i<=tc;i++)
//    cout<<"Case #"<<i<<'\n',
    Solve();
    return 0;
}
