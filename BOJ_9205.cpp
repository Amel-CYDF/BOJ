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

int n,m,vis[110];
vpii a;

bool chk(int p,int q)
{
	return 1'000 >= abs(a[p].ff-a[q].ff)+abs(a[p].ss-a[q].ss);
}

void dfs(int p)
{
	if(vis[p]) return;
	vis[p]=1;
	for(int i=n+2; i--;)
		if(chk(p,i)) dfs(i);
}

void Solve()
{
	cin>>n;
	a.resize(n+2);
	for(auto &i: a) cin>>i.ff>>i.ss;
	memset(vis,0,sizeof(vis));
	dfs(0);
	cout<<(vis[n+1]?"happy\n":"sad\n");
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
