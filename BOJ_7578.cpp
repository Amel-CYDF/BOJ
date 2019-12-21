#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct bit
{
    int a[1<<20],siz;

    void init(int p)
    {
        for(siz=1;siz<p;siz<<=1);
    }

    void upd(int pos,int p)
    {
        for(;pos<=siz;pos+=pos&-pos)
            a[pos]+=p;
    }

    int sum(int pos)
    {
        int ret=0;
        for(;pos;pos^=pos&-pos)
            ret+=a[pos];
        return ret;
    }
};

int n,a[1<<20],d[1<<20],b[1<<20];
ll ans;
bit w;

bool comp(int lhs,int rhs)
{
    return a[lhs]<a[rhs];
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    w.init(n);
    for(int i=1;i<=n;i++) scanf("%d",a+i),d[i]=i;
    sort(d+1,d+n+1,comp);
    sort(a+1,a+n+1);
    for(int i=1,s;i<=n;i++)
        scanf("%d",&s),b[i]=d[lower_bound(a+1,a+n+1,s)-a];
    for(int i=n;i;i--)
        ans+=(ll)w.sum(b[i]),w.upd(b[i],1);
    printf("%lld",ans);
    return 0;
}
