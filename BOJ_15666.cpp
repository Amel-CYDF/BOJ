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
vi a,b;
vvi ans;

void amel(int p,int q)
{
	if(!q)
	{
		ans.pb(a);
		return;
	}
	for(q--; p<n; p++)
	{
		a.pb(b[p]);
		amel(p,q);
		a.pop_back();
	}
}

void Solve()
{
	cin>>n>>m;
	b.resize(n);
	for(auto &i: b) cin>>i;
	sort(b.begin(),b.end());
	amel(0,m);
	sort(ans.begin(),ans.end());
	ans.resize(unique(ans.begin(),ans.end())-ans.begin());
	for(auto &i: ans)
	{
		for(auto &j: i) cout<<j<<' ';
		cout<<'\n';
	}
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
