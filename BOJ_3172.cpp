#include <bits/stdc++.h>
using namespace std;

int n,a[100010],tree[400010],trinx=1;
long long ans;
string c[100010];

bool comp(int lhs,int rhs)
{
    int i=c[lhs].length()-1;
    int j=c[rhs].length()-1;

    while(c[lhs][i]==c[rhs][j]&&i&&j) i--,j--;
    if(c[lhs][i]!=c[rhs][j]) return c[lhs][i]<c[rhs][j];
    return !i;
}

void add(int x)
{
    x+=trinx;
    while(x) tree[x]++,x>>=1;
}

int hap(int lf,int rg)
{
    if(lf>rg) return 0;
    lf+=trinx; rg+=trinx;
    int ret=0;
    while(lf<rg)
    {
        if(lf%2) ret+=tree[lf],lf++;
        else if(rg%2==0) ret+=tree[rg],rg--;
        else lf>>=1,rg>>=1;
    }
    return ret+tree[lf];
}

int main(){
  //  freopen("input.txt","r",stdin);

    scanf("%d",&n);
    for(int i=1;i<=n;i++) a[i]=i;
    while(trinx<n) trinx<<=1;
    trinx--;
    for(int i=1;i<=n;i++) cin>>c[i];
    sort(c+1,c+n+1);
    sort(a+1,a+n+1,comp);

    for(int i=1;i<=n;i++)
    {
        ans+=(long long)hap(a[i],n);
        add(a[i]);
    }

    printf("%lld",ans);

    return 0;
}
