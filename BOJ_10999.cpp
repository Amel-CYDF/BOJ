#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree
{
    ll a[1<<22],lazy[1<<22];
    int siz;

    void init(int p)
    {
        for(siz=1;siz<p;siz<<=1);
        for(int i=siz;i<siz+p;i++) scanf("%d",a+i);
        for(int i=siz-1;i;i--) a[i]=a[i<<1]+a[(i<<1)+1];
    }

    void wave(int l,int r,int pos)
    {
        if(!lazy[pos]) return;
        a[pos]+=(r-l+1)*lazy[pos];
        if(l!=r)
            lazy[pos<<1]+=lazy[pos],lazy[(pos<<1)+1]+=lazy[pos];
        lazy[pos]=0;
    }

    void upd(int l,int r,int tl,int tr,int pos,ll p)
    {
        wave(l,r,pos);
        if(r<tl||tr<l) return;
        if(tl<=l&&r<=tr)
        {
            lazy[pos]=p;
            wave(l,r,pos);
            return;
        }
        upd(l,l+r>>1,tl,tr,pos<<1,p);
        upd((l+r>>1)+1,r,tl,tr,1+(pos<<1),p);
        a[pos]=a[pos<<1]+a[(pos<<1)+1];
    }
    void upd(int l,int r,ll p) {return upd(1,siz,l,r,1,p);}

    ll sum(int l,int r,int tl,int tr,int pos)
    {
        wave(l,r,pos);
        if(r<tl||tr<l) return 0;
        if(tl<=l&&r<=tr) return a[pos];
        return sum(l,l+r>>1,tl,tr,pos<<1)+sum((l+r>>1)+1,r,tl,tr,(pos<<1)+1);
    }
    ll sum(int l,int r) {return sum(1,siz,l,r,1);}

};

int n,m,k;
segtree w;

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    w.init(n);
    for(int i=0,a,b,c;i<m+k;i++)
    {
        scanf("%d",&a);
        if(a==1)
        {
            ll d;
            scanf("%d %d %lld",&b,&c,&d);
            w.upd(b,c,d);
        }
        else
        {
            scanf("%d %d",&b,&c);
            printf("%lld\n",w.sum(b,c));
        }
    }
    return 0;
}
