#include <bits/stdc++.h>
using namespace std;

int n,m,k;

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    printf("%d",k==n?1:(k-n-1)/(n-m)+2);
    return 0;
}
