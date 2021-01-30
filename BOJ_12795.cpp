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

struct line {
	ll a, b;
	ll get(ll x) {
		return a * x + b;
	}
};

struct node {
	int lf, rg;	// child
	ll s, e;	// range
	line v;
};

// find Max Y at given X position
struct lichao {
	vector<node> a;

	void init(ll s, ll e) {
		a.clear();
		a.push_back({-1, -1, s, e, {0, (ll)-4e18}});
	}

	// Max: upd(0, {a, b});		min: upd(0, {-a, -b});
	void upd(int pos, line p) {
		ll lf = a[pos].s, rg = a[pos].e;
		ll mid = lf + rg >> 1;

		line low = a[pos].v, high = p;
		if(low.get(lf) > high.get(lf)) swap(low, high);

		if(low.get(rg) <= high.get(rg)) {
			a[pos].v = high; return;
		}

		if(low.get(mid) < high.get(mid)) {
			a[pos].v = high;
			if(!~a[pos].rg) {
				a[pos].rg = a.size();
				a.push_back({-1, -1, mid + 1, rg, {0, (ll)-4e18}});
			}
			upd(a[pos].rg, low);
		}
		else {
			a[pos].v = low;
			if(!~a[pos].lf) {
				a[pos].lf = a.size();
				a.push_back({-1, -1, lf, mid, {0, (ll)-4e18}});
			}
			upd(a[pos].lf, high);
		}
	}

	// Max: query(0, x);		min: -query(0, x);
	ll query(int pos, ll p) {
		if(!~pos) return -5e18;
		ll lf = a[pos].s, rg = a[pos].e;
		ll mid = lf + rg >> 1;
		if(p <= mid) return max(a[pos].v.get(p), query(a[pos].lf, p));
		return max(a[pos].v.get(p), query(a[pos].rg, p));
	}
}a;

void Solve()
{
	cin>>n;
	a.init(-1e12, 1e12);
	for(int i; n--;)
	{
		cin>>i;
		if(i==1)
		{
			ll p,q;
			cin>>p>>q;
			a.upd(0,{p,q});
		}
		else
		{
			ll x; cin>>x;
			cout<<a.query(0,x)<<'\n';;
		}
	}
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
