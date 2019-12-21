#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 10010
#define M 62510

struct segtree
{
    int tr[N<<3],siz,cnt[N<<3],len[N<<3];
    vector<int> v;
    void init()
    {
        for(siz=1;siz<v.size()-1;siz<<=1);
        memset(tr,0,sizeof(tr));
        memset(cnt,0,sizeof(cnt));
        memset(len,0,sizeof(len));
        for(int i=siz;i<siz+v.size()-1;i++)
            len[i]=v[i-siz+1]-v[i-siz];
        for(int i=siz-1;i;i--)
            len[i]=len[i<<1]+len[(i<<1)+1];
    }
    int top()
    {
        return tr[1];
    }
    void where(int &p)
    {
        p=(lower_bound(v.begin(),v.end(),p)-v.begin())+siz;
    }
    void addupd(int p)
    {
        for(int ret=len[p]-tr[p],i=p;i&&!cnt[i];i>>=1)
            tr[i]+=ret;
        cnt[p]++;
    }
    void add(int lf,int rg)
    {
        where(lf); where(rg); rg--;
        while(lf<rg)
        {
            if(lf&1) addupd(lf++);
            else if(!(rg&1)) addupd(rg--);
            else lf>>=1,rg>>=1;
        }
        addupd(lf);
    }
    void delupd(int p)
    {
        cnt[p]--;
        if(cnt[p]) return;
        if(p>=siz) tr[p]=0,p>>=1;
        for(;p&&!cnt[p];p>>=1) tr[p]=tr[p<<1]+tr[(p<<1)+1];
    }
    void del(int lf,int rg)
    {
        where(lf); where(rg); rg--;
        while(lf<rg)
        {
            if(lf&1) delupd(lf++);
            else if(!(rg&1)) delupd(rg--);
            else lf>>=1,rg>>=1;
        }
        delupd(lf);
    }
    void print()
    {
        for(int i=1,j=2;i<siz+v.size()-1;i++)
        {
            if(i==j) puts(""),j<<=1;
            printf("%d ",tr[i]);
        }
        puts("");
        for(int i=1,j=2;i<siz+v.size()-1;i++)
        {
            if(i==j) puts(""),j<<=1;
            printf("%d ",cnt[i]);
        }
        puts("");
        puts("");
    }
};

struct node
{
    int x,y1,y2,st;
    bool operator<(const node rhs)const
    {
        return x<rhs.x;
    }
}a[N<<1];

int n;
ll ans;

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    segtree b;
    for(int x1,x2,y1,y2,i=n;i--;)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        a[i<<1]={x1,y1,y2,1}; a[(i<<1)+1]={x2,y1,y2,0};
        b.v.pb(y1); b.v.pb(y2);
    }
    sort(a,a+(n<<1));
    sort(b.v.begin(),b.v.end());
    unique(b.v.begin(),b.v.end());
    b.init();
    for(int i=0,prv=0;i<n<<1;)
    {
//        printf("%d\n%d %d\n",a[i].x,a[i].y1,a[i].y2);
        ans+=(ll)(a[i].x-prv)*b.top();
        for(prv=a[i].x;a[i].x==prv;i++)
            a[i].st?b.add(a[i].y1,a[i].y2):b.del(a[i].y1,a[i].y2);
//        b.print();
    }
    cout<<ans;
    return 0;
}
