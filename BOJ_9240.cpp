#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pll;
#define N 100010

int n,cnt;
double ans;
pll a[N];
vector<pll> b;

bool chk(ll x1,ll y1,ll x2,ll y2)
{
    return x1*y2-y1*x2<0;
}

bool chk1(ll x1,ll y1,ll x2,ll y2)
{
    return x1*y2-y1*x2>=0;
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
    ans=max(ans,sqrt((p.first-q.first)*(p.first-q.first)+(p.second-q.second)*(p.second-q.second)));
}

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld %lld",&a[i].first,&a[i].second);
    sort(a+1,a+n+1);
    amel();
    reverse(a+1,a+n+1);
    amel();
    cnt=b.size();
    for(int i=0;i<cnt;i++) b.push_back(b[i]);
    int now=1;
    for(int i=0;i<cnt;i++)
    {
        while(!chk1(b[i+1].first-b[i].first,b[i+1].second-b[i].second,
            b[now+1].first-b[now].first,b[now+1].second-b[now].second)) now++,now%=cnt;
        ansupd(b[i],b[now]);
        ansupd(b[i],b[now+1]);
        ansupd(b[i+1],b[now]);
        ansupd(b[i+1],b[now+1]);
    }
    printf("%.7f",ans);
    return 0;
}
