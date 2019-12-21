#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 300010

struct bit
{
    ll a[N];
    int siz;
    void init(int p)
    {
        for(siz=1;siz<p;siz<<=1);
    }
    void upd(int pos,ll p)
    {
        while(pos<=siz)
            a[pos]+=p,pos+=pos&-pos;
    }
    ll sum(int pos)
    {
        ll ret=0;
        while(pos)
            ret+=a[pos],pos^=pos&-pos;
        return ret;
    }
};

int n,m;
bit lf,rg;

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    lf.init(n+1>>1); rg.init(n+1>>1);
    for(int i=1;i<=n;i++)
    {
        ll s;
        scanf("%lld",&s);
        i&1?lf.upd(i+1>>1,s):rg.upd(i>>1,s);
    }
    for(int i=0,a,b,c;i<m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a==1)
        {
            ll p=b&1?lf.sum(c+1>>1)-lf.sum(b>>1):rg.sum(c>>1)-rg.sum(b-1>>1);
            ll q=b&1?rg.sum(c>>1)-rg.sum(b>>1):lf.sum(c+1>>1)-lf.sum(b>>1);
            printf("%lld\n",p-q>0?p-q:q-p);
        }
        else
            b&1?lf.upd(b+1>>1,(ll)c):rg.upd(b>>1,(ll)c);
    }
    return 0;
}