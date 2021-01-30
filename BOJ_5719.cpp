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

int n,m,ed[510][510],a[510],s,e;

void amel()
{
	memset(a,-1,sizeof(a));
	priority_queue<pii> dij;
	dij.push(mp(0,s)); a[s]=0;
	while(!dij.empty())
	{
		auto t=dij.top(); dij.pop();
		if(a[t.ss]!=-t.ff) continue;
		for(int i=n;i--;)
			if(~ed[t.ss][i] && (!~a[i] | a[i]>ed[t.ss][i]-t.ff))
				a[i]=ed[t.ss][i]-t.ff, dij.push(mp(-a[i],i));
	}
}

void Solve()
{
	for(;;){
	cin>>n>>m>>s>>e;
	if(!n) return;
	memset(ed,-1,sizeof(ed));
	for(int i,j,k;m--;)
		cin>>i>>j>>k, ed[i][j]=k;
	amel();
	queue<int> bfs;
	bfs.push(e);
	while(!bfs.empty())
	{
		auto t=bfs.front(); bfs.pop();
		for(int i=n;i--;)
			if(~ed[i][t] && a[i]==a[t]-ed[i][t])
				ed[i][t]=-1, bfs.push(i);
	}
	amel();
	cout<<a[e]<<'\n';
	}
}

void Init(bool isLocal=0){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(1);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
