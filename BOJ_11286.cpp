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

struct cmp
{
	bool operator()(const int lhs, const int rhs)const
	{
		if(abs(lhs)!=abs(rhs)) return abs(lhs)>abs(rhs);
		return lhs>rhs;
	}
};
priority_queue<int,vi,cmp> a;

void Solve()
{
	cin>>n;
	for(int i; n--;)
	{
		cin>>i;
		if(!i)
		{
			if(a.empty()) cout<<"0\n";
			else cout<<a.top()<<'\n', a.pop();
		}
		else a.push(i);
	}
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
