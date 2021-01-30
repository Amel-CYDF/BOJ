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

int n,m,a[1'00'010],b[1'00'010],c[1'00'010];
vvi ed;
vi w,rr[1'00'010];
bitset<1'00'010> r;
ll ans;

void fuck(int p, int q, vpii &r, vi &tt)
{
	if(p>=r.size())
	{
		tt.pb(q); return;
	}
	for(int i=r[p].ss+1,j=1; i--; j*=r[p].ff)
		fuck(p+1, q*j, r,tt);
}

void amel(int p, vi &q)
{
	vpii t;
	for(int i=0; w[i]*w[i]<=p && p!=1; i++)
	{
		if(p%w[i]) continue;
		t.pb(mp(w[i],0));
		for(; p%w[i]==0; p/=w[i]) t.back().ss++;
	}
	if(p!=1) t.pb(mp(p,1));
	fuck(0,1,t,q);
}

void dfs(int p)
{
	ans+=c[a[p]];
	for(auto &i: rr[a[p]]) ans+= (i==a[p] ? 0 : b[i]), c[i]++;

	b[a[p]]++;
	for(auto &i: ed[p]) dfs(i);
	b[a[p]]--;

	for(auto &i: rr[a[p]]) c[i]--;
}

void Solve()
{
	w.pb(2);
	for(int i=3; i<=1'00'000; i+=2)
		if(!r.test(i))
		{
			w.pb(i);
			for(int j=i*3; j<=1'00'000; j+=i<<1) r.set(j);
		}
	for(int i=1; i<=1'00'000; i++) amel(i,rr[i]);
	cin>>n;
	ed.resize(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1,j;i<n;i++) cin>>j, ed[j-1].pb(i);
	dfs(0);
	cout<<ans;
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
