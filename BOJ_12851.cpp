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

int n,m,a[2'00'010],vis[2'00'010];
ll c[2'00'010];
queue<int> b;

bool chk(int p,int q)
{
	if(p<0 || p>2'00'000) return false;
	if(a[p]<=a[q]) return false;
	if(a[p]==a[q]+1) c[p]+=c[q];
	else a[p]=a[q]+1, c[p]=c[q];
	return true;
}

void Solve()
{
	cin>>n>>m;
	memset(a,0x70,sizeof(a));
	b.push(n); a[n]=0; c[n]=1;
	while(!b.empty())
	{
		auto t=b.front(); b.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(int i: {t-1, t+1, t<<1})
			if(chk(i,t)) b.push(i);
	}
	cout<<a[m]<<'\n'<<c[m];
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
