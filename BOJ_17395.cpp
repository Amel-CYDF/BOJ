#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100010

int m,cnt;
ll a;

int main(){
 //   freopen("input.txt","r",stdin);
    scanf("%lld %d",&a,&m);
    for(ll i=a;i;i>>=1) cnt+=i&1ll;
    if(cnt<m) printf("-1");
    else
    {
        for(int i=0;i<cnt+1-m;i++)
            a^=a&-a;
        printf("%lld ",a);
        for(int i=0;a;i++)
            a^=a&-a,printf("%lld ",a);
    }
    puts("");
    return 0;
}