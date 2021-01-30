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

int n,m,h,a[110][110][110];
int dx[]={1,-1,0,0,0,0}, dy[]={0,0,1,-1,0,0}, dz[]={0,0,0,0,1,-1};

struct node
{
	int x,y,z;
};
queue<node> bfs;

void Solve()
{
	cin>>n>>m>>h;
	for(int i = h; i--; )
		for(int j = m; j--; )
			for(int k=n; k--; )
			{
				cin>>a[k][j][i];
				if(a[k][j][i]==1) bfs.push({k,j,i});
			}
	while(!bfs.empty())
	{
		auto t=bfs.front(); bfs.pop();
		for(int i=6; i--; )
		{
			int x=t.x+dx[i], y=t.y+dy[i], z=t.z+dz[i];
			if(0<=x&&x<n&&0<=y&&y<m&&0<=z&&z<h&&!a[x][y][z])
				a[x][y][z]=a[t.x][t.y][t.z]+1, bfs.push({x,y,z});
		}
	}
	for(int i=n; i--; )
		for(int j=m; j--; )
			for(int k=h; k--; )
				if(!a[i][j][k]) {cout<<-1; return;}
	cout<<*max_element((int *)a,&a[n][m][h])-1;
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
