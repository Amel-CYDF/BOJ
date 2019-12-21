#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 110
#define MOD 1000000000

int n,m;

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    if(n==4||n==7) {printf("-1"); return 0;}
    for(int i=n/5;i>=0;i--)
        if((n-5*i)%3==0) {printf("%d",i+(n-5*i)/3); return 0;}
    return 0;
}
