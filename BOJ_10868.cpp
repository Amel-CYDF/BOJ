#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree
{
    int a[1<<22],siz;

    void init(int p)
    {
        for(siz=1;siz<p;siz<<=1);
        for(int i=siz;i<siz+p;i++) scanf("%d",a+i);
        for(int i=siz+p;i<siz<<1;i++) a[i]=INT_MAX;
        for(int i=siz-1;i;i--) a[i]=min(a[i<<1],a[(i<<1)+1]);
    }

    void upd(int pos,int p)
    {
        pos+=siz;
        a[pos]=p; pos<<=1;
        while(pos) a[pos]=min(a[pos<<1],a[(pos<<1)+1]),pos<<=1;
    }

    int qrmin(int l,int r,int tl,int tr,int pos)
    {
        if(r<tl||tr<l) return INT_MAX;
        if(tl<=l&&r<=tr) return a[pos];
        return min(qrmin(l,l+r>>1,tl,tr,pos<<1),qrmin((l+r>>1)+1,r,tl,tr,(pos<<1)+1));
    }

    int qrmin(int l,int r) {return qrmin(1,siz,l,r,1);}
};

int n,m;
segtree st;

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    st.init(n);
    while(m--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",st.qrmin(x,y));
    }
    return 0;
}
