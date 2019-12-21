#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1010
#define MOD 1000000

int n,m,a[N];

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        for(int i=0;i<m;i++) scanf("%d",a+i);
        int avg=0,cnt=0;
        for(int i=0;i<m;i++) avg+=a[i];
        for(int i=0;i<m;i++) cnt+=(avg<m*a[i]);
        printf("%.3f\%\n",(float)cnt*100/m);
    }
    return 0;
}
