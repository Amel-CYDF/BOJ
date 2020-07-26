#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 600921647
#define N 500000
#define M 3010

int n,m,mintemp;
vector<pii> a;

int use1(vector<pii> *p)
{
    int t=min_element(p->begin(),p->end())->ff;
    int ret=0;
    for(auto i:*p) ret=max(ret,(i.ff-t)*i.ss);
    return ret+30;
}

bool cmp(pii lhs,pii rhs)
{
    return (lhs.ff-mintemp)*lhs.ss > (rhs.ff-mintemp)*rhs.ss;
}

int use2(vector<pii> *p)
{
    if(p->size()<2) return 60;
    mintemp=min_element(p->begin(),p->end())->ff;
    sort(p->begin(),p->end(),cmp);
    int ret=INT_MAX,t=p->begin()->ff,dap=0;
    for(auto i:*p)
    {
        ret=min(ret,(i.ff-mintemp)*i.ss+dap);
        if(t>i.ff)
        {
            t=i.ff;
            dap=0;
            for(auto j:*p)
            {
                dap=max(dap,(j.ff-t)*j.ss);
                if(j==i) break;
            }
        }
        else dap=max(dap,(i.ff-t)*i.ss);
    }
    return ret+60;
}

int use3(vector<pii> *p)
{
    if(p->size()<3) return 90;
    mintemp=min_element(p->begin(),p->end())->ff;
    sort(p->begin(),p->end(),cmp);
    int ret=INT_MAX,t=mintemp;
    vector<pii> tmp;
    for(auto i:*p)
    {
        ret=min(ret,(i.ff-t)*i.ss+use2(&tmp));
        tmp.pb(i);
    }
    return ret+30;
}

int main(){
   // freopen("input.txt","r",stdin);
    /*
int tc; cin>>tc;
while(tc--)
{//*/

    cin>>n>>m;
    for(int i=0,j,k;i<n;i++) cin>>j>>k,a.pb({j,k});
    int ans=use1(&a);
    if(m>1) ans=min(ans,use2(&a));
    if(m>2) ans=min(ans,use3(&a));
    cout<<ans;

    /*
}//*/
    return 0;
}
