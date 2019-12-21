#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 55
#define MOD 1000000007

int n,m;

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    if(m<45) n=(n+23)%24;
    m=(m+15)%60;
    printf("%d %d",n,m);
    return 0;
}
