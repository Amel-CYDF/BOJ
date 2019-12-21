#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 1000010
#define MOD 1000000007

int n,m,k;

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    printf("%d\n%d\n%d\n%d\n%d",n+m,n-m,n*m,n/m,n%m);
    return 0;
}
