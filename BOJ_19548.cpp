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
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m,isone;
string u,a,pfx,sfx;
vector<vpll> b;
vl r;

void amel(int p, ll lf, ll rg)
{
    if(p>m)
    {
        ll t=(ll)pfx.size()*(p-m);
        for(;lf<=rg&&lf<t;lf++) cout<<pfx[lf%pfx.size()];
        amel(m, lf-t, rg-t);
        return;
    }
    rg=min(rg,r[p]-1);
    if(rg<lf) return;
    if(!p)
    {
        for(;lf<=rg;lf++) cout<<u[lf];
        return;
    }
    auto t=lower_bound(b[p].begin(),b[p].end(),mp(lf,0ll));
    ll now=lf;
    if(t!=b[p].begin())
    {
        --t;
        if(lf < t->ff+r[p-1])
        {
            amel(p-1, lf-t->ff, rg-t->ff);
            now=t->ss;
            lf=t->ff+r[p-1];
        }
        else now=t->ss+(lf-t->ff-r[p-1]);
    }
    for(;lf<=rg;now++)
    {
        if(a[now]!='$')
        {
            cout<<a[now];
            lf++;
        }
        else
        {
            amel(p-1, 0ll, rg-lf);
            lf+=r[p-1];
        }
    }
}

void one$(ll lf, ll rg)
{
    ll t=(ll)pfx.size()*n;
    for(;lf<=rg;lf++)
    {
        if(lf<t) cout<<pfx[lf%pfx.size()];
        else if(lf<t+u.size()) cout<<u[lf-t];
        else cout<<sfx[(lf-t-u.size())%sfx.size()];
    }
}

void Solve()
{
    ll lf,rg;
    cin>>lf>>rg;
    if(isone) one$(lf-1,rg-1);
    else amel(n,lf-1,rg-1);
    cout<<'\n';
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
    cin>>u>>a>>n;
    r.resize(n+1);
    b.resize(n+1);
    r[0]=u.size();
    ll cnt=0;
    for(auto i:a) cnt+=i=='$';
    for(auto i:a)
    {
        if(i=='$') break;
        pfx.pb(i);
    }
    if(cnt==1)
    {
        bool fl=false;
        for(auto i:a)
        {
            if(fl) sfx.pb(i);
            if(i=='$') fl=true;
        }
        isone=1;
        return;
    }
    ll h=1'000'000'000'000'000'010ll;
    m=n;
    for(int i=1;i<=n;i++)
    {
        if(h/cnt >= r[i-1]) r[i]=r[i-1]*cnt+a.size()-cnt;
        else
        {
            r[i]=h;
            m=i;
            break;
        }
    }
    for(int i=1;i<=m;i++)
    {
        ll now=0; cnt=0;
        for(auto j:a)
        {
            cnt++;
            if(j!='$') now++;
            else
            {
                b[i].pb(mp(now,cnt));
                now+=r[i-1];
            }
            if(now>h) break;
        }
    }
}
int main(){ ios::sync_with_stdio(false); cin.tie(NULL);
    Init(1);
    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
