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

int n,m,par[1'000'010];
pii c[1'000'010];
vi a;

void dfs(int lf,int rg)
{
	if(lf>rg) return;
	int t;
	for(t=lf+1; t<=rg; t++)
		if(a[t]>a[lf]) break;
	dfs(lf+1,t-1);
	dfs(t,rg);
	cout<<a[lf]<<'\n';
}

void Solve()
{
	for(int i,j=-1; ; j=i)
	{
		cin>>i;
		if(i==j) break;
		a.pb(i);
	}
	dfs(0,a.size()-1);
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
