#include <bits/stdc++.h>
using namespace std;

int n,a[1<<21],tr[1<<21];

long long dfs(int p)
{
    if(p>=1<<(n+1)) return 0;
    return (long long)tr[p/2]-tr[p]+a[p]+dfs(2*p)+dfs(2*p+1);
}

int main(){
    scanf("%d",&n);
    for(int i=2;i<1<<(n+1);i++) scanf("%d",a+i);
    for(int i=1<<n;i<1<<(n+1);i++)
    {
        int t=i;
        while(t>1) tr[i]+=a[t],t>>=1;
    }
    for(int i=(1<<n)-1;i;i--) tr[i]=max(tr[2*i],tr[2*i+1]);
    tr[0]=tr[1];

    printf("%lld",dfs(1));


    return 0;
}
