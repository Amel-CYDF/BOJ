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
#define MOD 1'000'000'007

int n,m;
vi a,w;
vl b,sb;
const ll INF=250'000'000'000'000;

struct segtree
{
	int a[250'005<<2],siz;
	void init()
	{
		for(siz=1; siz<n+5; siz<<=1) ;
		memset(a, 0, sizeof(a));
	}
	void upd(int pos)
	{
		for(pos|=siz; pos; pos>>=1) a[pos]++;
	}
	int query(int lf,int rg)
	{
		lf|=siz; rg|=siz;
		int ret=0;
		while(lf<rg)
		{
			if(lf&1) ret+=a[lf++];
			else if(~rg&1) ret+=a[rg--];
			else lf>>=1, rg>>=1;
		}
		return ret+a[lf];
	}
}c;

bool chk(ll &p)
{
	int cnt=0;
	c.init();
	for(int i=n+1;i--;)
	{
		int t=lower_bound(sb.begin(),sb.end(),b[i]+p)-sb.begin();
		cnt+=c.query(t,n+2);
		if(cnt>=m) return true;
		c.upd(w[i]);
	}
	return false;
}

ll getans()
{
	ll lf=LLONG_MAX,rg=LLONG_MIN,t=b.back();
	for(int i=n; i--; )
		rg=max(rg,t-b[i]), t=max(t,b[i]);
	t=b.back();
	for(int i=n; i--; )
		lf=min(lf, t-b[i]), t=min(t, b[i]);
	while(lf<rg)
	{
		ll mid=lf+rg>>1;
		if(chk(++mid)) lf=mid;
		else rg=mid-1;
	}
	return lf;
}

void Solve()
{
	cin>>n>>m;
	a.resize(n);
	for(auto &i:a) cin>>i;
	b.resize(n+1);
	b.front()=0;
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i-1];
	sb=b; sort(sb.begin(),sb.end());
	unique(sb.begin(),sb.end());
	w.resize(n+1);
	for(int i=n+1;i--;)
		w[i]=lower_bound(sb.begin(),sb.end(),b[i])-sb.begin();
	ll ans=getans();
	multiset<ll> t;
	vl dap;
	for(int i=n+1;i--;)
	{
		for(auto j=t.upper_bound(b[i]+ans); j!=t.end(); ++j)
			dap.pb(*j-b[i]);
		t.insert(b[i]);
	}
	sort(dap.begin(),dap.end());
	reverse(dap.begin(),dap.end());
	dap.resize(m,ans);
	for(auto &i:dap) cout<<i<<' ';
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(0);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
