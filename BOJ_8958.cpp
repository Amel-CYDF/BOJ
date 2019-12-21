#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 15
#define MOD 1000000

int n,m;
char a[85];

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    while(n--)
    {
        memset(a,0,sizeof(a));
        scanf("%s",a);
        int ans=0;
        for(int i=0,cnt=0;a[i];i++)
        {
            if(a[i]=='O') cnt++,ans+=cnt;
            else cnt=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}
