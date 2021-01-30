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

int n,m,a[20][20],b[20][20][3];

void amel(int x,int y,int p,int q)
{
	switch(p)
	{
		case 0:
			if(y<n-1 && !a[x][y+1])
				b[x][y+1][0]+=b[x][y][q];
			break;
		case 1:
			if(x<n-1 && !a[x+1][y])
				b[x+1][y][1]+=b[x][y][q];
			break;
		case 2:
			if(x<n-1&&y<n-1 && !a[x][y+1]&&!a[x+1][y]&&!a[x+1][y+1])
				b[x+1][y+1][2]+=b[x][y][q];
			break;
	}
}

void Solve()
{
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) cin>>a[i][j];
	b[0][1][0]=1;
	for(int i=0; i<n; i++)
		for(int j=1; j<n; j++)
		{
			amel(i,j,0,0); amel(i,j,2,0);
			amel(i,j,1,1); amel(i,j,2,1);
			for(int k=3; k--; ) amel(i,j,k,2);
		}
	cout<<b[n-1][n-1][0]+b[n-1][n-1][1]+b[n-1][n-1][2];
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
