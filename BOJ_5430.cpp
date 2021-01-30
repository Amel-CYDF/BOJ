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

int n,m;
string a,b;
vi c;

void Solve()
{
	cin>>a>>n>>b;
	int lf=0, rg=n;
	bool r=false;
	for(auto &i:a)
	{
		if(i=='R') r^=true;
		else
		{
			if(r) rg--;
			else lf++;
		}
	}
	if(lf>rg) {cout<<"error\n"; return;}
	c.clear();
	for(int i=1;i<b.size();i++)
	{
		int t=0;
		for(; '0'<=b[i]&&b[i]<='9'; i++)
			t*=10, t+=b[i]-'0';
		c.pb(t);
	}
	c.erase(c.begin()+rg, c.end());
	c.erase(c.begin(), c.begin()+lf);
	if(r) reverse(c.begin(),c.end());
	if(c.empty()) {cout<<"[]\n"; return;}
	cout<<'[';
	for(int i=0;i<c.size()-1;i++) cout<<c[i]<<',';
	cout<<c.back()<<"]\n";
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
