#include <bits/stdc++.h>
using namespace std;

int n,a[100010],b[100010],cnt,ans;

int main(){
   // freopen("input.txt","r",stdin);

    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);

    for(int i=0;i<n-1;i++) b[i]=(a[i]>a[i+1]);
    for(int i=0;i<n-1;i++) cnt+=b[i];

    if(cnt-b[0]==0) ans++;
    if(cnt-b[n-2]==0) ans++;
    for(int i=1;i<n-1;i++)
    {
        if(a[i-1]>a[i+1]) continue;
        if(cnt-b[i-1]-b[i]==0) ans++;
    }

    printf("%d",ans);

    return 0;
}
