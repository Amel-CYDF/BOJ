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
#define MOD 1'000'000'003

int n,m,a[2010],b[2010][2010];

void Solve()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=n; i--;) b[i][i]=1;
	for(int i=n-1; i--;) b[i][i+1]=a[i]==a[i+1];
	for(int i=2; i<n; i++)
		for(int j=n-i; j--;)
			b[j][j+i]=b[j+1][j+i-1]&a[j]==a[j+i];
	cin>>m;
	for(int i,j;m--;)
		cin>>i>>j,cout<<b[i-1][j-1]<<'\n';
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

