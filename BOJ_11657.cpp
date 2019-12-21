#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 510
#define M 0
#define MOD 15746

int n,m,ans[N];
list<pii> ed[N];

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n>>m;
    int s,e,w;
    while(~scanf("%d %d %d",&s,&e,&w)) ed[s].push_back({e,w});
    memset(ans,1,sizeof(ans)); ans[1]=0;
    for(int i=n,flag=1;flag;i--)
    {
        flag=0;
        if(!i) {printf("-1"); return 0;}
        for(int j=1;j<=n;j++)
            for(pii k:ed[j])
                if(ans[j]<1<<24&&ans[k.first]>ans[j]+k.second)
                    flag=1,ans[k.first]=ans[j]+k.second;
    }
    for(int i=2;i<=n;i++) printf("%d\n",ans[i]>1<<24?-1:ans[i]);
    return 0;
}
