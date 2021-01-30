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

int n,m,a[20]={1};
ll dp[10][10][100'010],ten[20]={1};

void Solve()
{
	cin>>n>>m;
	for(int i=1;i<n<<1;i++) a[i]=a[i-1]*10%m,ten[i]=ten[i-1]*10;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<10;i++) dp[0][0][i%m]=i;
	dp[0][1][11%m]=11;
	for(int i=1;i<n;i++)
		for(int r=i+1;r--;)
			for(int j=m;j--;)
				if(~dp[i-1][r][j])
				{
					for(int k=12;k--;)
						if(k!=10)
						{
							int t=(j+k*a[i+r])%m,rr=r+(k>10);
							dp[i][rr][t]=max(dp[i][rr][t], dp[i-1][r][j]+ten[i+r]*k);
						}
				}
	int r=n;
	for(; r>=0; r--) if(~dp[n-1][r][0]) break;
	cout<<dp[n-1][r][0]<<'\n';
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(0);
	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
