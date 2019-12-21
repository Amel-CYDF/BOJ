#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 1010
#define MOD 1000000007

int n,m,k;

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    printf("%d\n%d\n%d\n%d",(n+m)%k,(n%k+m%k)%k,n*m%k,n%k*m%k%k);
    return 0;
}
