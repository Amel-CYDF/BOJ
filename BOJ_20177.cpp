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
#define MOD 998244353

int n,m;
vi a,ans;
vl z;

struct segtree
{
	int a[2'000'010<<2];
	int siz;
	void init(int p)
	{
		for(siz=1;siz<p;siz<<=1);
		memset(a, -1, sizeof(a));
	}
	void upd(int pos, int p)
	{
		for(pos |= siz; pos; pos>>=1) a[pos]=max(a[pos], p);
	}
	int amel(int p,int q)
	{
		if(a[q] < p) return -1;
		for(; !(q&siz); )
		{
			if(a[q<<1 | 1] >= p) q = q<<1 | 1;
			else q <<= 1;
		}
		return q^siz;
	}
	int query(int p, int rg)
	{
		if(rg<0) return -1;
		int lf = siz; rg |= siz;
		while(lf<rg)
		{
			if(~rg&1)
			{
				if(a[rg] >= p) return amel(p, rg);
				else rg--;
			}
			else lf>>=1,rg>>=1;
		}
		return amel(p, lf);
	}
}b;

struct query
{
	int lf,rg,idx;
	ll r;
	bool operator<(const query &rhs)const
	{
		return rg < rhs.rg;
	}
};
vector<query> c;

void Solve()
{
	cin>>n>>m;
	a.resize(n);
	ans.resize(m);
	c.resize(m);
	for(auto &i: a) cin>>i;
	for(auto &i: c) cin>>i.lf>>i.rg>>i.r;
	for(int i = m; i--; ) c[i].idx = i;
	sort(c.begin(),c.end());
	for(int i = n; i--;)
	{
		ll t = 0;
		for(int j = i+1; j--;)
			t += a[j], z.pb(t);
	}
	sort(z.begin(),z.end());
	unique(z.begin(),z.end());
	b.init(z.size());
	int t = 0;
	for(auto &i: c)
	{
		for(; t< i.rg; t++)
		{
			ll tmp=0;
			for(int j = t+1; j--; )
			{
				tmp += a[j];
				b.upd(lower_bound(z.begin(),z.end(),tmp)-z.begin(), j);
			}
		}
		ans[i.idx] = b.query(i.lf-1, upper_bound(z.begin(),z.end(),i.r)-z.begin()-1);
	}
	for(auto &i: ans)
		!~i ? cout<<"NONE\n" : cout<<z[i]<<'\n' ;
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"if( b == #"<<i<<'\n',
	Solve();
	return 0;
}
