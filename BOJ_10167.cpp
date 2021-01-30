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
    ll a[12'000],b[12'000],c[12'000],d[12'000];
    int siz;
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
        d[pos+=siz]+=p;
        a[pos]=b[pos]=c[pos]=max(d[pos],0ll);
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

void Solve()
{
    cin>>n;
    a.resize(n);
    for(auto &i:a) cin>>i.a.ff>>i.a.ss>>i.c;
    r.init(n);
    sort(a.begin(),a.end());
    for(int i=0,j=-1;i<n;i++)
    {
        if(i&&a[i].a.ff==a[i-1].a.ff) a[i].p=j;
        else a[i].p=++j;
    }
    sort(a.begin(),a.end(),cmp);
    ll ans=0;
    for(int i=0;i<n;r.init(n))
    {
        for(int j=i;j<n;)
        {
            r.upd(a[j].p,a[j].c);
            for(j++; j<n&&a[j].a.ss==a[j-1].a.ss; j++) r.upd(a[j].p,a[j].c);
            ans=max(ans,r.a[1]);
        }
        for(i++; i<n&&a[i].a.ss==a[i-1].a.ss; i++) ;
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
