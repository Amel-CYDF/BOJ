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
string a;

bool amel()
{
	stack<int> b;
	for(auto &i: a)
		switch(i)
		{
			case '(': b.push(0); break;
			case '[': b.push(1); break;
			case ']': if(b.empty() || b.top() != 1) return false;
				b.pop(); break;
			case ')': if(b.empty() || b.top() != 0) return false;
				b.pop();
		}
	return b.empty();
}

void Solve()
{
	while(1)
	{
		getline(cin, a);
		if(a.size() == 1 && a.front() == '.') break;
		cout<< (amel() ? "yes\n" : "no\n");
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
