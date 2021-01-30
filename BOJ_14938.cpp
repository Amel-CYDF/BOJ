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

int n,m,r,a[110],b[110][110];

void Solve()
{
	cin>>n>>m>>r;
	memset(b,0x11,sizeof(b));
	for(int i=1;i<=n;i++) cin>>a[i], b[i][i]=0;
	for(int i,j,k; r--;)
	{
		cin>>i>>j>>k;
		b[i][j]=min(b[i][j],k);
		b[j][i]=min(b[j][i],k);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int tmp=0;
		for(int j=1;j<=n;j++)
			if(b[i][j]<=m) tmp+=a[j];
		ans=max(ans,tmp);
	}
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
