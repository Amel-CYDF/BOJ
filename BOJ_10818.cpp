#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 1000010
#define MOD 1000000007

int n,m,a[N];

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    auto t=minmax_element(a,a+n);
    printf("%d %d",*t.first,*t.second);
    return 0;
}
