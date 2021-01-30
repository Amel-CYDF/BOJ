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

int n,m,a[10010];
vi b[30];

void Solve()
{
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		string t; cin>>t;
		for(auto &j: t)
			b[j-'a'].pb(i);
	}
	for(int i=26;i--;) b[i].resize(unique(b[i].begin(),b[i].end())-b[i].begin());
	for(int j; m--; )
	{
		char c;
		cin>>j>>c;
		for(auto &i: b[c-'a']) a[i]+= j==1? 1: -1;
		int cnt=0;
		for(int i=n; i--;) cnt+=!a[i];
		cout<<cnt<<'\n';
	}
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
