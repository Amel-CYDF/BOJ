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

int n,m,dp[510][510];
vi a;

void Solve()
{
	cin>>n;
	a.resize(n+1);
	for(int i=0; i<n; i++) cin>>a[i]>>a[i+1];
	memset(dp,0x44,sizeof(dp));
	for(int i=n+1; i--;) dp[i][i+1]=dp[i][i]=0;
	for(int i=2; i<=n; i++)
		for(int j=0; j<=n-i; j++)
			for(int k=j+1; k<j+i; k++)
				dp[j][i+j]=min(dp[j][i+j], dp[j][k]+dp[k][i+j]+a[j]*a[k]*a[i+j]);
	cout<<dp[0][n];
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
