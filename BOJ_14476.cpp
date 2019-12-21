#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 62510

struct segtree
{
    int a[1<<21],siz;
    segtree(int p)
    {
        memset(a,0,sizeof(a));
        for(siz=1;siz<p;siz<<=1);
        for(int i,j=0;j<p;j++)
            scanf("%d",&i),a[siz+j]=i;
        for(int i=siz-1;i;i--)
            a[i]=__gcd(a[i<<1],a[(i<<1)+1]);
    }
    int what(int p)
    {
        return a[siz+p];
    }
    int query(int lf,int rg)
    {
        if(lf>rg) return 0;
        lf+=siz; rg+=siz;
        int ret=0;
        while(lf<rg)
        {
            if(lf&1) ret=__gcd(ret,a[lf++]);
            else if(!(rg&1)) ret=__gcd(ret,a[rg--]);
            else lf>>=1,rg>>=1;
        }
        return __gcd(ret,a[lf]);
    }
};

int n,ans=-1,c;

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    segtree a=segtree(n);
    for(int i=0;i<n;i++)
    {
        int p=__gcd(a.query(0,i-1),a.query(i+1,n-1));
        if(a.what(i)%p&&ans<p) ans=p,c=i;
    }
    printf("%d",ans);
    if(~ans) printf(" %d",a.what(c));
    return 0;
}
