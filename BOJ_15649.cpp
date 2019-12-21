#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define N 55
#define M 100010
#define MOD 15746

int n,m,a[10];

void amel(int p)
{
    if(!p)
    {
        for(int i=m;i;i--)
            for(int j=1;j<=n;j++) if(a[j]==i) printf("%d ",j);
        puts(""); return;
    }
    for(int i=1;i<=n;i++)
        if(!a[i]) a[i]=p,amel(p-1),a[i]=0;
}

int main(){
 //   freopen("input.txt","r",stdin);
    cin>>n>>m;
    amel(m);
    return 0;
}
