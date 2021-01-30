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
ll ans;
vpii a;
set<int> b;

struct fenwick {
	int a[1'500'010];
	int siz;
	void init(int p) {
		for(siz = 1; siz < p; siz <<= 1) ;
	}

	// add p to a[pos]
	void upd(int pos, int p) {
		for(; pos <= siz; pos += pos & -pos) a[pos] += p;
	}

	// get a[1] + a[2] + ... + a[pos]
	int sum(int pos) {
		ll ret = 0;
		for(; pos; pos ^= pos & -pos) ret += a[pos];
		return ret;
	}
}c;

void Solve()
{
	cin>>n;
	for(int i=1,j;i<=n;i++) cin>>j,a.pb(mp(j,i));
	sort(a.begin(),a.end());
	c.init(n);
	for(int i=n-1;i>=0;)
	{
		int t=i;
		for(; i>=0&&a[i].ff==a[t].ff; i--)
		{
			auto r=b.lower_bound(a[i].ss);
			ans+=(r!=b.end())+(r!=b.begin());
			int lf=0,rg= r==b.end() ? n : *r;
			if(r!=b.begin()) --r,lf=*r;
			ans+=c.sum(rg)-c.sum(lf),
			c.upd(a[i].ss, 1);
		}
		for(; t>i; t--) b.insert(a[t].ss), c.upd(a[t].ss, -1);
	}
	cout<<ans;
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
