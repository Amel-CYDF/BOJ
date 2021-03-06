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

int n,m,c[55][55];

void Solve()
{
	cin>>n;
	for(int i=0;i<55;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%10'007;
	}
	for(int i=1;i<=13 && i<<2<=n;i++)
	{
		m+= (i&1 ? 1 : -1) * c[13][i] * c[52-i*4][n-i*4];
		m%=10'007;
	}
	cout<<(m+10'007)%10'007;
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
