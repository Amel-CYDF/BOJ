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

int n,m,a[1010][1010],b[1010][1010];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
vi d,c[1010][1010];

int dfs(int x,int y)
{
	if((x<0|n<=x|y<0|m<=y)||a[x][y]||b[x][y]) return 0;
	b[x][y]=1;
	int ret=1;
	for(int i=4;i--;) ret+=dfs(x+dx[i],y+dy[i]);
	return ret;
}

void amel(int x,int y)
{
	if(x<0|n<=x|y<0|m<=y) return;
	if(!c[x][y].empty()&&c[x][y].back()==d.size()) return;
	c[x][y].pb(d.size());
	if(a[x][y]) return;
	for(int i=4;i--;) amel(x+dx[i],y+dy[i]);
}

void Solve()
{
	cin>>n>>m;
	for(int i=n;i--;)
	{
		string t;
		cin>>t;
		for(int j=m;j--;) a[i][j]=t[m-j-1]=='1';
	}
	for(int i=n;i--;)
		for(int j=m;j--;)
			if(!a[i][j]&!b[i][j])
			{
				d.pb(dfs(i,j));
				amel(i,j);
			}
	for(int i=n;i--;cout<<'\n')
		for(int j=m;j--;)
		{
			if(!a[i][j]) {cout<<0; continue;}
			int t=1;
			for(auto &r: c[i][j]) t+=d[r-1];
			cout<<t%10;
		}
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

