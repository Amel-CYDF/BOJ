#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 15
#define MOD 1000000

int n,m,a[]={0,1,2,4,7,13,24,44,81,149,274};

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    while(~scanf("%d",&n)) printf("%d\n",a[n]);
    return 0;
}
