#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 110
#define MOD 1000000000

int n,m,a[N][10],ans;

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<10;i++) a[1][i]=1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<10;j++)
        {
            if(j) a[i][j-1]+=a[i-1][j],a[i][j-1]%=MOD;
            if(j!=9) a[i][j+1]+=a[i-1][j],a[i][j+1]%=MOD;
        }
    for(int i=0;i<10;i++) ans+=a[n][i],ans%=MOD;
    printf("%d",ans);
    return 0;
}
