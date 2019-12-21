#include <bits/stdc++.h>
using namespace std;

int n,m,k,lf[2010],rg[2010],a[2010][2010],ans[2010][2010];

int main()
{
   // freopen("input.txt","r",stdin);

    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        lf[t]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int t;
        scanf("%d",&t);
        rg[t]=i;
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        int t,s;
        scanf("%d %d",&t,&s);
        a[lf[t]][rg[s]]=1;
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            ans[i][j]=max(ans[i][j],ans[i][j-1]);
            ans[i][j]=max(ans[i][j],ans[i-1][j]);
            if(a[i][j]) ans[i][j]=max(ans[i][j],ans[i-1][j-1]+1);
        }

    printf("%d",k-ans[n][m]);
    return 0;
}
