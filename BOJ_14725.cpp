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

int n,m;
struct node
{
	string v;
	vector<node*> c;
}rt;

bool cmp(const node *lhs,const node *rhs)
{
	return lhs->v<rhs->v;
}

void dfs(node *p,int lv)
{
	if(~lv)
	{
		for(int i=lv;i--;) cout<<"--";
		cout<<p->v<<'\n';
	}
	sort(p->c.begin(),p->c.end(),cmp);
	for(auto &i:p->c) dfs(i,lv+1);
}

void Solve()
{
	cin>>n;
	for(int i;n--;)
	{
		cin>>i;
		auto t=&rt;
		for(string j;i--;)
		{
			cin>>j;
			node *r=NULL;
			for(auto &k: t->c) if(k->v==j) r=k;
			if(!r)
			{
				auto w=new node();
				w->v=j;
				t->c.pb(w);
				t=w;
			}
			else t=r;
		}
	}
	dfs(&rt,-1);
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

