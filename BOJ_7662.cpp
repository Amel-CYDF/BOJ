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
multiset<int> a;

void Solve()
{
	cin>>n;
	a.clear();
	for(int i; n--; )
	{
		char c;
		cin>>c>>i;
		if(c=='I') a.insert(i);
		else if(!a.empty())
		{
			if(~i) a.erase(--a.end());
			else a.erase(a.begin());
		}
	}
	if(a.empty()) cout<<"EMPTY\n";
	else cout<<*(--a.end())<<' '<<*a.begin()<<'\n';
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
