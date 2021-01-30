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

int n,m,s,e;
vpii ed[2010];
int a[2010],b[2010],par[2010],lca[2010],ans[2010];
vi g;

void amel(const int &p, int q[])
{
	memset(q,-1,n<<2);
	priority_queue<pii> dij;
	dij.push(mp(0,p)); q[p]=0;
	while(!dij.empty())
	{
		auto t=dij.top(); dij.pop();
		if(q[t.ss]<-t.ff) continue;
		for(auto i:ed[t.ss])
			if(!~q[i.ff]||q[i.ff]>i.ss-t.ff)
				q[i.ff]=i.ss-t.ff,
				dij.push(mp(t.ff-i.ss,i.ff));
	}
}

void Solve()
{
	cin>>n>>m>>s>>e; s--; e--;
	for(int i,j,k;m--;)
	{
		cin>>i>>j>>k; i--; j--;
		ed[i].pb(mp(j,k));
		ed[j].pb(mp(i,k));
	}
	cin>>m;
	g.resize(m);
	for(auto &i:g) cin>>i,i--;

	amel(s,a); amel(e,b);

	memset(lca,-1,sizeof(lca));
	par[e]=-1;
	for(int i=m;i--;)
    {
        lca[g[i]]=g[i];
        if(i!=m-1) par[g[i]]=g[i+1];
    }

    vpii r;
    for(int i=n;i--;) r.pb(mp(a[i],i));
    sort(r.begin(),r.end());
    for(auto &i:r)
        if(!~lca[i.ss])
        {
            for(auto &j:ed[i.ss])
                if(i.ff==a[j.ff]+j.ss)
                    lca[i.ss]=lca[j.ff];
        }

    memset(ans,0x7F,sizeof(ans));
    for(int i=n;i--;)
        for(auto &j:ed[i])
            if(i!=lca[i]||j.ff!=lca[j.ff]||par[i]!=j.ff)
            {
                int t=a[i]+j.ss+b[j.ff];
                bool fl=true;
                for(int k=lca[i];~k;k=par[k])
                    if(k==lca[j.ff]) {fl=false; break;}
                if(fl) continue;
                for(int k=lca[i];k!=lca[j.ff];k=par[k])
                    ans[k]=min(ans[k],t);
            }

    for(int i=0;i<m-1;i++)
    {
        if(ans[g[i]]>>30&1) cout<<"-1\n";
        else cout<<ans[g[i]]<<'\n';
    }
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(0);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
