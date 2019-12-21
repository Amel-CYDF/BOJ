#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1010
#define MOD 1000000

int n,m,a[N],ans[N];

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++) if(a[i]>a[j]) ans[i]=max(ans[i],ans[j]+1);
    printf("%d",*max_element(ans,ans+n+1));
    return 0;
}
