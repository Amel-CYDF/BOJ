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

int n,m,a[55][55],r,w;
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};

void Solve()
{
	cin>>n>>m>>r;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) cin>>a[i][j];
	for(; ~a[w][0]; w++);
	for(; r--; )
	{
		int tmp[55][55]={};
		for(int i=n; i--; )
			for(int j=m; j--; )
			{
				tmp[i][j]+=a[i][j];
				for(int k=4; k--; )
				{
					int x=i+dx[k], y=j+dy[k];
					if(0<=x&&x<n&&0<=y&&y<m&&~a[x][y])
						tmp[x][y]+=a[i][j]/5,
						tmp[i][j]-=a[i][j]/5;
				}
			}
		memcpy(a,tmp,sizeof(a));
		for(int i=w-1; i>0; i--) a[i][0]=a[i-1][0];
		for(int j=0; j<m-1; j++) a[0][j]=a[0][j+1];
		for(int i=0; i<w; i++) a[i][m-1]=a[i+1][m-1];
		for(int j=m-1; j>0; j--) a[w][j]=a[w][j-1];
		for(int i=w+1; i<n-1; i++) a[i][0]=a[i+1][0];
		for(int j=0; j<m-1; j++) a[n-1][j]=a[n-1][j+1];
		for(int i=n-1; i>w+1; i--) a[i][m-1]=a[i-1][m-1];
		for(int j=m-1; j>0; j--) a[w+1][j]=a[w+1][j-1];
		a[w][0]=a[w+1][0]=-1;
		a[w][1]=a[w+1][1]=0;
	}
	int ans=2;
	for(int i=n; i--; )
		for(int j=m; j--; ) ans+=a[i][j];
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
