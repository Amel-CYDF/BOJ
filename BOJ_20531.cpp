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

int n,m,par[5010],r;
ll c[5010][5010], dp[5010];

int parfind(int p)
{
	if(par[p]==p) return p;
	return par[p]=parfind(par[p]);
}

bool uni(int p,int q)
{
	p=parfind(p); q=parfind(q);
	if(p==q) return false;
	par[p]=q; return true;
}

void Solve()
{
	for(int i=0; i<=5000; i++)
	{
		c[i][0]=1;
		for(int j=1; j<=i; j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	}
	dp[0]=1;
	for(int i=1; i<=5000; i++)
	{
		for(int j=i; j--;)
			dp[i]+=c[i-1][j]*dp[i-j-1],
			dp[i]%=MOD;
	}

	cin>>n>>m;
	r=n;
	for(int i=1;i<=n;i++) par[i]=i;
	for(int i,j; m--; )
	{
		cin>>i>>j;
		r-=uni(i,j);
		cout<<dp[r]<<'\n';
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
