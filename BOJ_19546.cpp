#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007

int n,m,f;
int a[2010][2010],flow[2010][2010];
const int SOURCE=2001,SINK=2002;

void makeflow()
{
	while(1)
	{
		vi par(2010,-1);
		queue<int> bfs;
		bfs.push(SOURCE); par[SOURCE]=SOURCE;
		while(!bfs.empty())
		{
			int t=bfs.front(); bfs.pop();
			if(t==SINK) break;
			for(int i=2003;i--;)
				if(!~par[i] && a[t][i]>flow[t][i])
					bfs.push(i), par[i]=t;
		}
		if(!~par[SINK]) break;
		int maxflow=INT_MAX;
		for(int i=SINK; i!=SOURCE; i=par[i])
			maxflow=min(maxflow,a[par[i]][i]-flow[par[i]][i]);
		for(int i=SINK; i!=SOURCE; i=par[i])
			flow[par[i]][i]+=maxflow, flow[i][par[i]]-=maxflow;
	}
}

vi b(2010,0);
void dfs(int p)
{
	if(b[p]) return;
	b[p]=1;
	for(int i=2003;i--;)
		if(a[p][i]>flow[p][i]) dfs(i);
}

void Solve()
{
	cin>>n>>m>>f;
	int s,e;
	cin>>s>>e; s--; e--;
	int w=s<<1;
	a[SOURCE][w]=INT_MAX;
	for(int i=1+(e<<1),k=f;k--;i+=n<<1)
		a[i][SINK]=INT_MAX;
	for(int i=0,j;i<n;i++)
	{
		cin>>j;
		int r=i<<1;
		for(int k=f;k--;r+=n<<1)
		{
			a[r][r+1]=j;
			if(k) a[r][r+1+(n<<1)]=INT_MAX;
		}
	}
	for(;m--;)
	{
		cin>>s>>e;
		s--; e--; s<<=1; e<<=1; s++;
		for(int k=f;k--;s+=n<<1,e+=n<<1)
			a[s][e]=INT_MAX;
	}
	makeflow();
	if(a[SOURCE][w]==flow[SOURCE][w]) {cout<<-1; return;}
	dfs(SOURCE);
	set<int> ans;
	for(int i=0;i<2001;i+=2)
		if(b[i]&&!b[i+1])
		{
			int j=i%(n<<1);
			ans.insert(j>>1);
		}
	cout<<ans.size()<<'\n';
	for(auto &i:ans) cout<<i+1<<' ';
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
}
int main(){ Init(01); //ios::sync_with_stdio(false); cin.tie(NULL);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
