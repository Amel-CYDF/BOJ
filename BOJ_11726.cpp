#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1100
#define MOD 10007

int n,m,a[N]={1,1};

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=2;i<=n;i++) a[i]=a[i-1]+a[i-2],a[i]%=MOD;
    printf("%d",a[n]);
    return 0;
}
