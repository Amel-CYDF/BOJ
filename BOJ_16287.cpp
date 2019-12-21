#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 5010
#define M 12500010
#define MOD 10007

int n,m,b[N],k=1,c[N],d[N];

struct amel
{
    int p,a,b;
    int same(amel rhs)
    {
        if(rhs.a==a||rhs.b==a) return a;
        if(rhs.a==b||rhs.b==b) return b;
        return 0;
    }
    bool operator<(const amel &rhs)const
    {
        return p<rhs.p;
    }
}a[M];

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++) scanf("%d",b+i);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++) a[k].a=i,a[k].b=j,a[k++].p=b[i]+b[j];
    sort(a+1,a+k);
//    for(int i=1;i<k;i++) printf("%d %d %d\n",a[i].p,a[i].a,a[i].b);
    for(int lf=1,rg=k-1;lf<rg;)
    {
        while(lf<rg&&a[lf].p+a[rg].p<m) lf++;
        while(lf<rg&&a[lf].p+a[rg].p>m) rg--;
        if(a[lf].p+a[rg].p!=m) continue;
        memset(c,0,sizeof(c));
        for(int i=rg;lf<i&&a[i].p==a[rg].p;i--)
        {
            int r=a[lf].same(a[i]);
            if(!r) {printf("YES"); return 0;}
            r==a[i].a?c[a[i].b]+=r:c[a[i].a]+=r;
            r==a[lf].a?d[a[lf].b]=1:d[a[lf].a]=1;
        }
        for(int i=lf+1,t=a[lf].a+a[lf].b;i<rg&&a[i].p==a[lf].p;i++)
        {
            int r=a[lf].same(a[i]);
            if(!r)
            {
                for(int j=rg;i<j&&a[j].p==a[rg].p;j--)
                    if(!a[i].same(a[j])) {printf("YES"); return 0;}
            }
            else if(d[r])
            {
                if(r==a[i].a&&c[a[i].b]!=t&&c[a[i].b]!=r) {printf("YES"); return 0;}
                else if(r==a[i].b&&c[a[i].a]!=t&&c[a[i].a]!=r) {printf("YES"); return 0;}
            }
        }
        d[a[lf].a]=d[a[lf].b]=0; lf++; rg--;
        while(lf<rg&&a[lf].p==a[lf-1].p) lf++;
        while(lf<rg&&a[rg].p==a[rg+1].p) rg--;
    }
    printf("NO");
    return 0;
}
