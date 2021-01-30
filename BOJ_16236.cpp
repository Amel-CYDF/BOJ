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

int n,m,a[25][25],ans;
pii now;
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};

void Solve()
{
	cin>>n;
	for(int i=n; i--; )
		for(int j=n; j--; )
		{
			cin>>a[i][j];
			if(a[i][j]==9) now=mp(i,j), a[i][j]=0;
		}
	for(int r=2, rr=0; ; )
	{
		int vis[25][25]={};
		queue<pii> bfs;
		bfs.push(now); vis[now.ff][now.ss]=1;
		while(!bfs.empty())
		{
			auto t=bfs.front(); bfs.pop();
			for(int i=4; i--; )
			{
				int x=t.ff+dx[i], y=t.ss+dy[i];
				if(0<=x&&x<n&&0<=y&&y<n&&a[x][y]<=r&&!vis[x][y])
					vis[x][y]=vis[t.ff][t.ss]+1, bfs.push(mp(x,y));
			}
		}
		int t=INT_MAX;
		pii tmp(-1,-1);
		for(int i=n; i--; )
			for(int j=n; j--; )
				if(vis[i][j]&&t>vis[i][j]&&a[i][j]&&a[i][j]<r)
						t=vis[i][j], tmp=mp(i,j);
		if(t>1212) break;
		rr++;
		if(rr==r) r++,rr=0;
		a[tmp.ff][tmp.ss]=0;
		now=tmp;
		ans+=t-1;
	}
	cout<<ans;
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
