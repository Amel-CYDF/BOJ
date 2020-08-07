#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007

int n,m;

struct node
{
	pii p;
	int num;
	bool isblue;
	node(){}
	node(int x, int y, int mynum, bool myisblue)
		{ p=mp(x,y); num=mynum; isblue=myisblue; }
};
vector<node> a;
vpii ans;
node w;

bool cmp(node &lhs,node &rhs)
{
	if(lhs.p.ff!=rhs.p.ff) return lhs.p.ff<rhs.p.ff;
	return lhs.p.ss<rhs.p.ss;
}

bool ccw(pii &p,pii &q,pii &r)
{
	int x1=q.ff-p.ff,y1=q.ss-p.ss,x2=r.ff-p.ff,y2=r.ss-p.ss;
	return (ll)x1*y2 > (ll)y1*x2;
}

bool cmp2(node &lhs,node &rhs)
{
	return ccw(w.p,lhs.p,rhs.p);
}

void amel(vector<node> *p)
{
	if(p->empty()) return;
	auto t=min_element(p->begin(),p->end(),cmp);
	w=*t; p->erase(t);
	sort(p->begin(),p->end(),cmp2);
	if(!w.isblue)
	{
		if(p->begin()->isblue)
		{
			node ww=p->front();
			*p->begin()=w;
			w=ww;
			sort(p->begin(),p->end(),cmp2);
		}
		else if(p->rbegin()->isblue)
		{
			node ww=p->back();
			*p->rbegin()=w;
			w=ww;
			sort(p->begin(),p->end(),cmp2);
		}
		else
		{
			while(1)
			{
				int now=-1;
				for(auto i=p->begin(); ;++i)
				{
					now+=(i->isblue?2:-1);
					if(!now)
					{
						++i;
						if(i!=p->end())
						{
							vector<node> tmp(p->begin(),i);
							tmp.pb(w);
							amel(&tmp);
							tmp.assign(i,p->end());
							amel(&tmp);
							return;
						}
						break;
					}
				}
				reverse(p->begin(),p->end());
			}
		}
	}
	int now=2;
	for(auto i=p->begin(); ;++i)
	{
		now+=(i->isblue?2:-1);
		if(!now)
		{
			int r=i->num; --i;
			ans[w.num]=mp(r,i->num);
			vector<node> tmp(p->begin(), i);
			amel(&tmp);
			tmp.assign(i+2,p->end());
			amel(&tmp);
			return;
		}
	}
}

void Solve()
{
	cin>>n;
	ans.resize(n);
	for(int i=0,x,y;i<n;i++)
	{
		cin>>x>>y;
		a.pb(node(x,y,i,true));
	}
	for(int i=1,x,y;i<=n<<1;i++)
	{
		cin>>x>>y;
		a.pb(node(x,y,i,false));
	}
	amel(&a);
	for(auto &i:ans) cout<<i.ff<<' '<<i.ss<<'\n';
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
}
int main(){ Init(01); //ios::sync_with_stdio(false); cin.tie(NULL);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
