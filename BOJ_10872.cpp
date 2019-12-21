#include <bits/stdc++.h>
using namespace std;

int n,m;

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(m=1;n;n--) m*=n;
    printf("%d",m);
    return 0;
}
