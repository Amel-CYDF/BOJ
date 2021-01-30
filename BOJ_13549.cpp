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

int n,m,a[2'00'010];
queue<int> bfs;

void amel(int p,int q)
{
	if(!p) {bfs.push(0); a[0]=q; return;}
	for(; p<=2'00'000; p<<=1)
		if(!a[p]) bfs.push(p), a[p]=q;
}

void Solve()
{
	cin>>n>>m;
	amel(n,1);
	while(!bfs.empty())
	{
		auto t=bfs.front(); bfs.pop();
		for(int i: {t-1,t+1})
			if(i>=0 && !a[i]) amel(i,a[t]+1);
	}
	cout<<a[m]-1;
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
