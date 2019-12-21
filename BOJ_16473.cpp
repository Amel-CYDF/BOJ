#include <bits/stdc++.h>
using namespace std;

int n,k,a[5010],ans[5010][5010];

int main()
{
   // freopen("input.txt","r",stdin);

    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);

    for(int t=n-3;t>=0;t--)
        for(int i=2;i+t<n;i++)
        {
            ans[i][i+t]=max(ans[i][i+t],ans[i-1][i+t]);
            ans[i][i+t]=max(ans[i][i+t],ans[i][i+t+1]);
            if(a[i-1]==a[i+t+1]) ans[i][i+t]=max(ans[i][i+t],ans[i-1][i+t+1]+2);
        }

    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        int t;
        scanf("%d",&t);
        printf("%d\n",n-1-ans[t][t]);
    }
    return 0;
}
