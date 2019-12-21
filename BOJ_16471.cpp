#include <bits/stdc++.h>
using namespace std;

int n,a[100010],b[100010],cnt;

int main()
{
   // freopen("input.txt","r",stdin);

    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n;i++) scanf("%d",b+i);
    sort(a,a+n); sort(b,b+n);

    int x=0;
    for(int i=0;i<n;)
    {
        if(x>=n) break;
        if(a[i]>=b[x++]) continue;
        cnt++; i++;
    }

    printf(cnt>=(n+1)/2?"YES":"NO");
    return 0;
}
