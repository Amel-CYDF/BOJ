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

int n,m,c[1010][1010];
string a,b;

void Solve()
{
	cin>>a>>b;
	for(int i=1; i<=a.size(); i++)
	{
		for(int j=1; j<=b.size(); j++)
		{
			c[i][j]=max(c[i-1][j], c[i][j-1]);
			if(a[i-1]==b[j-1]) c[i][j]=max(c[i][j], c[i-1][j-1]+1);
		}
	}
	cout<<c[a.size()][b.size()];
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
