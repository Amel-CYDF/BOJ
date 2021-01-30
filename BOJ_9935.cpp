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

int n,m,c[1'000'010];
string a,b;
stack<pii> s;

void Solve()
{
	cin>>a>>b;
	for(int i=0; i<a.size(); i++)
	{
		if(a[i]==b.front() || (!s.empty()&&a[i]==b[s.top().ff+1]))
		{
			if(a[i]==b.front())
			{
				if(b.size()==1) c[i]=1;
				else s.push(mp(0,i));
			}
			else if(s.top().ff+1==b.size()-1)
			{
				c[i]=1;
				for(int i=b.size(); !s.empty()&&i>s.top().ff; )
					c[s.top().ss]=1, i=s.top().ff, s.pop();
			}
			else s.push(mp(s.top().ff+1,i));
		}
		else
		{
			while(!s.empty()) s.pop();
		}
	}
	bool r=true;
	for(int i=0; i<a.size(); i++)
		if(!c[i]) r=false, cout<<a[i];
	if(r) cout<<"FRULA";
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
