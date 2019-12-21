#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 110
#define MOD 1000000000

int n,m;
ll a[N]={0,1,1,1,2};

int main(){
  //  freopen("input.txt","r",stdin);
    for(int i=5;i<=100;i++) a[i]=a[i-1]+a[i-5];
    scanf("%d",&n);
    while(~scanf("%d",&n)) printf("%lld\n",a[n]);
    return 0;
}
