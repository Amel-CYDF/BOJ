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
#define MOD 1'000'000'003

int n,m,a[1010][1010],b[1010][1010],c[1010][1010];
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};

pii dfs(int x,int y)
{
	if(b[x][y]) return mp(x,y);
	b[x][y]=1;
	auto ret=dfs(x+dx[a[x][y]],y+dy[a[x][y]]);
	b[x][y]=0;
	return ret;
}

void amel(int x,int y)
{
	if(c[x][y]) return;
	c[x][y]=1;
	for(int i=4; i--;)
	{
		int xx=x+dx[i^1],yy=y+dy[i^1];
		if(0<=xx&xx<n&0<=yy&yy<m & a[xx][yy]==i)
		{
			amel(xx,yy);
		}
	}
}

void Solve()
{
	cin>>n>>m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			char c;
			cin>>c;
			if(c=='D') a[i][j]=1;
			else if(c=='L') a[i][j]=2;
			else if(c=='R') a[i][j]=3;
		}
	int ans=0;
	for(int i=n; i--;)
		for(int j=m;j--;)
			if(!c[i][j])
			{
				auto t=dfs(i,j);
				amel(t.ff,t.ss);
				ans++;
			}
	cout<<ans;
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(0);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}

