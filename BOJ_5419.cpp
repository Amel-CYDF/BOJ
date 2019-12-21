#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 75010
#define MOD 1000000

//struct seg2d
//{
//    int a[1<<20],siz,side;
//    void init(int p)
//    {
//        for(side=1;side<p;side<<=1);
//        siz=side*side;
//    }
//    int where(int x,int y)
//    {
//        int ret=0;
//        for(int i=side,nx=0,ny=0;i;i>>=1)
//        {
//            if(x>=nx+i) nx+=i,ret+=i<<1;
//            if(y>=ny+i) ny+=i,ret+=i;
//        }
//        return ret;
//    }
//    void upd(int x,int y,int p)
//    {
//        for(int i=where(x,y);i;i>>=2) a[i]+=p;
//    }
//    void sum(int
//
//};

struct bit
{
    ll a[1<<17];
    int siz;
    void init(int p)
    {
        for(siz=1;siz<p;siz<<=1);
        memset(a,0,sizeof(a));
    }
    void upd(int pos,ll p)
    {
        for(;pos<=siz;pos+=pos&-pos) a[pos]+=p;
    }
    ll sum(int p)
    {
        ll ret=0;
        for(;p;p^=p&-p) ret+=a[p];
        return ret;
    }
};

int n,m,b[N];
ll ans;
pii a[N];
bit v;

void init()
{
    ans=0; memset(b,0,sizeof(b));
    memset(a,0,sizeof(a));
}

int main(){
  //  freopen("input.txt","r",stdin);
    int te; scanf("%d",&te);
    while(te--)
    {
        init();
        scanf("%d",&n); v.init(n);
        for(int i=1;i<=n;i++) scanf("%d %d",&a[i].first,&a[i].second),a[i].first=-a[i].first,b[i]=a[i].second;
        sort(a+1,a+n+1); sort(b+1,b+n+1);
        for(int i=1;i<=n;i++)
        {
            int s=lower_bound(b+1,b+n+1,a[i].second)-b;
            ans+=v.sum(s); v.upd(s,1ll);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
