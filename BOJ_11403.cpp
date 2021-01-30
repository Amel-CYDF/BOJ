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

int n,m,a[110][110],b[110][110];

void Solve()
{
	cin>>n;
	for(int i=n; i--; )
		for(int j=n; j--; )
		{
			cin>>a[i][j];
			if(!a[i][j]) a[i][j]=1234;
		}
	for(int i=n; i--; )
		for(int j=n; j--; )
			for(int k=n; k--; )
				a[j][k]=min(a[j][k], a[j][i]+a[i][k]);
	for(int i=n; i--; cout<<'\n')
		for(int j=n; j--; ) cout<<(a[i][j]<200)<<' ';
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
