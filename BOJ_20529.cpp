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

int n,m,b[20];
string t;

int amel(string &p)
{
	int ret=0;
	ret<<=1; ret|=p[0]=='E';
	ret<<=1; ret|=p[1]=='S';
	ret<<=1; ret|=p[2]=='T';
	ret<<=1; ret|=p[3]=='J';
	return ret;
}

int dif(int p,int q)
{
	int ret=0;
	for(int i=4; i--;) ret+=((p>>i)^(q>>i))&1;
	return ret;
}

void Solve()
{
	cin>>n;
	memset(b,0,sizeof(b));
	for(int i=n; i--; ) cin>>t, b[amel(t)]++;
	for(int i=16; i--; ) if(b[i]>=3) {cout<<"0\n"; return;}
	int ans=INT_MAX;
	for(int i=16;i--;)
		if(b[i]==2)
		{
			for(int j=16;j--;)
				if(i!=j && b[j]) ans=min(ans,dif(i,j)<<1);
		}
	for(int i=16; i--;)
		for(int j=i; j--;)
			for(int k=j; k--;)
				if(b[i]&&b[j]&&b[k])
					ans=min(ans,dif(i,j)+dif(j,k)+dif(k,i));
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
