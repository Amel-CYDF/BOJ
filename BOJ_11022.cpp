#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 1010
#define MOD 1000000007

int n,m,k;

int main(){
 //   freopen("input.txt","r",stdin);
    int te; scanf("%d",&te);
    for(int i=1;~scanf("%d %d",&n,&m);i++)
        printf("Case #%d: %d + %d = %d\n",i,n,m,n+m);
    return 0;
}
