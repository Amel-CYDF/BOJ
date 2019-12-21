#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000

int n,m,a[55][55],ans[55],dap;

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %d",&m,&n);
    for(int ii=0;ii<m;ii++)
    {
        int tmp[55];
        for(int i=1;i<=n;i++) scanf("%d",tmp+i);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                a[tmp[i]][tmp[j]]++;
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            a[i][j]>a[j][i]?ans[i]++:ans[j]++;
    for(int i=1;i<=n;i++) dap=max(dap,ans[i]);
    for(int i=1;i<=n;i++) if(ans[i]==dap) printf("%d ",i);
    return 0;
}
