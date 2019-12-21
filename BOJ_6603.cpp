#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 15
#define MOD 1000000000

int n,m,a[N],b[N],c[N]={1,1,1,1,1,1};

int main(){
  //  freopen("input.txt","r",stdin);
    while(1)
    {
        memcpy(b,c,sizeof(c));
        scanf("%d",&n);
        if(!n) break;
        for(int i=0;i<n;i++) scanf("%d",a+i);
        do
        {
            for(int i=0;i<n;i++) if(b[i]) printf("%d ",a[i]);
            puts("");
            prev_permutation(b,b+n);
        }while(memcmp(b,c,sizeof(int)*n));
        puts("");
    }
    return 0;
}
