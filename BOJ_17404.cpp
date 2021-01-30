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

int n,m,a[1010][3],dp[1010][3][3];

void Solve()
{
	cin>>n;
	for(int i=n; i--; )
		for(int j=3; j--; ) cin>>a[i][j];
	for(int k=3; k--;)
	{
		for(int i=3; i--; ) dp[n-1][i][k]=54321;
		dp[n-1][k][k]=a[n-1][k];
		for(int i=n-1; i--; )
		{
			dp[i][0][k]=min(dp[i+1][1][k],dp[i+1][2][k])+a[i][0];
			dp[i][1][k]=min(dp[i+1][2][k],dp[i+1][0][k])+a[i][1];
			dp[i][2][k]=min(dp[i+1][0][k],dp[i+1][1][k])+a[i][2];
		}
	}
	int ans=INT_MAX;
	for(int i=3; i--; )
		for(int j=3; j--; )
			if(i!=j) ans=min(ans,dp[0][i][j]);
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
