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

int n,m,a[12][12],b[12][12];

void amel(int x,int y)
{
	b[x][y]=a[x-1][y]^b[x-1][y];
	if(y>0) b[x][y]^=b[x-1][y-1];
	if(y<9) b[x][y]^=b[x-1][y+1];
	if(x>1) b[x][y]^=b[x-2][y];
}

void Solve()
{
	for(int i=10;i--;)
		for(int j=10;j--;)
		{
			char c;
			cin>>c;
			a[i][j]=c=='O';
		}
	n=101;
	for(int r=1024;r--;)
	{
		for(int i=10;i--;) b[0][i]=r>>i&1;
		for(int i=1;i<=10;i++)
			for(int j=10;j--;) amel(i,j);
		bool fl=false;
		for(int i=10;i--;) fl|=b[10][i];
		if(fl) continue;
		int t=0;
		for(int i=10;i--;)
			for(int j=10;j--;) t+=b[i][j];
		n=min(n,t);
	}
	cout<<(n>100 ? -1 : n);
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

