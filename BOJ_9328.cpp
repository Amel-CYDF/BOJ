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

int n,m,b[30],c[110][110];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
char a[110][110];
string key;

void dfs(int x,int y)
{
	if(x<0||n<=x||y<0||m<=y||c[x][y]) return;
	c[x][y]=1;
	if(a[x][y]=='*' | 'A'<=a[x][y]&a[x][y]<='Z'&!b[a[x][y]-'A']) return;
	if('a'<=a[x][y]&a[x][y]<='z') b[a[x][y]-'a']=1;
	for(int i=4;i--;) dfs(x+dx[i],y+dy[i]);
}

void Solve()
{
	cin>>n>>m;
	for(int i=n;i--;)
		for(int j=m;j--;) cin>>a[i][j];
	cin>>key;
	memset(b,0,sizeof(b));
	if(key!="0")
	{
		for(auto &i: key) b[i-'a']=1;
	}
	for(int ii=30; ii--;)
	{
		memset(c,0,sizeof(c));
		for(int i=n;i--;) dfs(i,0),dfs(i,m-1);
		for(int i=m;i--;) dfs(0,i),dfs(n-1,i);
	}
	int ans=0;
	for(int i=n;i--;)
		for(int j=m;j--;) ans+=a[i][j]=='$'&c[i][j];
	cout<<ans<<'\n';
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(0);
	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}

