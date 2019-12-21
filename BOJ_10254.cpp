#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pll;
#define N 200010

int n;
ll ans;
pll ans1,ans2;
pll a[N];
vector<pll> b;

void init()
{
    ans=0;
    b.clear();
    memset(a,0,sizeof(a));
}

bool chk(ll x1,ll y1,ll x2,ll y2)
{
    return x1*y2-y1*x2<0;
}

bool clockwise(pll st,pll mid,pll p)
{
    return chk(mid.first-st.first,mid.second-st.second,p.first-mid.first,p.second-mid.second);
}

void amel()
{
    vector<pll> hull;
    for(int i=1;i<=n;i++)
    {
        while(hull.size()>=2&&!clockwise(hull[hull.size()-2],hull.back(),a[i])) hull.pop_back();
        hull.push_back(a[i]);
    }
    b.insert(b.end(),hull.begin(),hull.end());
    b.pop_back();
}

void ansupd(pll p,pll q)
{
    ll tmp=(p.first-q.first)*(p.first-q.first)+(p.second-q.second)*(p.second-q.second);
    if(tmp>ans)
        ans=tmp,ans1=p,ans2=q;
}

int main(){
   // freopen("input.txt","r",stdin);
    int te;
    scanf("%d",&te);
    while(te--)
    {
        init();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld %lld",&a[i].first,&a[i].second);
        sort(a+1,a+n+1);
        amel();
        reverse(a+1,a+n+1);
        amel();
        int cnt=b.size();
        b.push_back(b[0]);
        int now=1;
        for(int i=0;i<cnt;i++)
        {
            while(chk(b[i+1].first-b[i].first,b[i+1].second-b[i].second,
                b[now+1].first-b[now].first,b[now+1].second-b[now].second)) now++,now%=cnt;
            ansupd(b[i],b[now]);
            ansupd(b[i],b[now+1]);
            ansupd(b[i+1],b[now]);
            ansupd(b[i+1],b[now+1]);
        }
        printf("%lld %lld %lld %lld\n",ans1.first,ans1.second,ans2.first,ans2.second);
    }
    return 0;
}
