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

int n,m,a[25];

void Solve()
{
	cin>>n;
	for(string b; n--; )
	{
		cin>>b;
		if(b == "add") cin>>m, a[m]=1;
		else if(b == "remove") cin>>m, a[m]=0;
		else if(b == "check") cin>>m, cout<<a[m]<<'\n';
		else if(b== "toggle") cin>>m, a[m]^=1;
		else if(b== "empty") memset(a, 0, sizeof(a));
		else
		{
			for(int i = 1; i<21; i++) a[i]=1;
		}
	}
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"if( b == #"<<i<<'\n',
	Solve();
	return 0;
}
