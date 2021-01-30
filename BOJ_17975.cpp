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

struct segtree
{
    int a[8'000],b[8'000],c[8'000],d[8'000],siz;
    void init(int p)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        for(siz=1;siz<p;siz<<=1);
    }
    void upd(int pos,int p)
    {
        d[pos+=siz]=p;
        a[pos]=b[pos]=c[pos]=max(p,0);
        for(pos>>=1;pos;pos>>=1)
            d[pos]=d[pos*2]+d[pos*2+1],
            b[pos]=max(b[pos*2],d[pos*2]+b[pos*2+1]),
            c[pos]=max(c[pos*2+1],d[pos*2+1]+c[pos*2]),
            a[pos]=max(c[pos*2]+b[pos*2+1],max(a[pos*2],a[pos*2+1]));
    }
}r;

struct node
{
    pii a;
    int c,p;
    bool operator<(const node &rhs)const
    {
        return a.ff<rhs.a.ff;
    }
};

vector<node> a;

bool cmp(const node &lhs,const node &rhs)
{
    return lhs.a.ss<rhs.a.ss;
}

vpii b,c;

void Solve()
{
    cin>>n;
    b.resize(n);
    for(auto &i:b) cin>>i.ff>>i.ss;
    cin>>n;
    c.resize(n);
    for(auto &i:c) cin>>i.ff>>i.ss;
    n+=b.size();
    r.init(n);
    int c1,c2; cin>>c1>>c2;
    for(auto &i:b) a.pb({i,c1,0});
    for(auto &i:c) a.pb({i,-c2,0});
    sort(a.begin(),a.end());
    for(int i=n;i--;) a[i].p=i;
    sort(a.begin(),a.end(),cmp);
    int ans=0;
    for(int i=n;i--;r.init(n))
        for(int j=i;j<n;j++)
        {
            r.upd(a[j].p,a[j].c);
            ans=max(ans,r.a[1]);
        }
    cout<<ans;
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
