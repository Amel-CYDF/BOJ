#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,int> plli;
#define N 1010
#define MOD 1000000007

int n,m,dap[N];
pll a[N];
plli fir[N];
vector<pll> ans;

bool cw(pll p,pll q,pll r)
{
    return (q.second-p.second)*(r.first-q.first)-(q.first-p.first)*(r.second-q.second)>0;
}

void amel()
{
    vector<pll> hull;
    for(int i=1;i<=n;i++)
    {
        while(hull.size()>=2&&!cw(hull[hull.size()-2],hull.back(),a[i])) hull.pop_back();
        hull.push_back(a[i]);
    }
    ans.insert(ans.end(),hull.begin(),hull.end());
    ans.pop_back();
}

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n); m=n;
    for(int i=1;i<=n;i++) scanf("%lld %lld",&a[i].first,&a[i].second);
    for(int i=1;i<=n;i++) fir[i]={a[i],i};
    sort(fir+1,fir+n+1);
    for(int fl=1;n>=3;fl++)
    {
        sort(a+1,a+n+1); ans.clear();
        amel();
        reverse(a+1,a+n+1);
        amel();
        if(ans.size()<3) break;
        sort(ans.begin(),ans.end());
        vector<pll> tmp;
        for(int i=1;i<=n;i++)
        {
            if(!binary_search(ans.begin(),ans.end(),a[i])) {tmp.push_back(a[i]); continue;}
            int s=lower_bound(fir+1,fir+m+1,make_pair(a[i],0))-fir;
            dap[fir[s].second]=fl;
        }
        n=0;
        for(pll i:tmp) a[++n]=i;
    }
    for(int i=1;i<=m;i++) printf("%d ",dap[i]);
    return 0;
}