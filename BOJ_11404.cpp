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

int n,m,a[110][110];

void Solve()
{
	cin>>n>>m;
	memset(a,0x11,sizeof(a));
	for(int i=n+1;i--;) a[i][i]=0;
	for(int i,j,k; m--; )
	{
		cin>>i>>j>>k;
		a[i][j]=min(a[i][j],k);
	}
	for(int k=1; k<=n; k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	for(int i=1;i<=n;i++,cout<<'\n')
		for(int j=1;j<=n;j++)
			cout<<(a[i][j]>1<<28 ? 0 : a[i][j])<<' ';
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
