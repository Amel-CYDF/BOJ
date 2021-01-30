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

int n,m,arr[1'000'010];
vpii a,b;
ll ans;

ll cal(int p, int q)
{
	return (ll)(b[q].ff - a[p].ff) * (b[q].ss + a[p].ss);
}

void amel(int lf, int rg, int optlf, int optrg)
{
	if(lf>rg) return;
	ll ret = 0;
	int mid = lf+rg >> 1, opt=optlf;
	for(int i = optlf; i <=optrg && a[i].ff < b[mid].ff; i++)
		if(ret < cal(i, mid))
			ret=cal(i,mid), opt = i;
	ans=max(ans,ret);
	amel(lf, mid-1, optlf, opt);
	amel(mid+1, rg, opt, optrg);
}

void Solve()
{
	cin>>n;
	for(int i = 0; i < n; i++) cin>>arr[i];
	for(int i = 0; i < n; i++)
		if(a.empty() || a.back().ss < arr[i])
			a.pb(mp(i,arr[i]));
	for(int i = n; i--; )
		if(b.empty() || b.back().ss < arr[i])
			b.pb(mp(i, arr[i]));
	reverse(b.begin(), b.end());
	amel(0, b.size()-1, 0, a.size()-1);
	cout<<ans;
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
