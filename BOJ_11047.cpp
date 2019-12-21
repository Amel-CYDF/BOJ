#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 15
#define MOD 1000000000

int n,m,a[N],ans;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=n-1;i>=0;i--)
        ans+=m/a[i],m%=a[i];
    printf("%d",ans);
    return 0;
}
