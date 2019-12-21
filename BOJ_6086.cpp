#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int n,a[110][110],now[110][110],ans,pre[110];
list<int> ed[110];

int chg(int p)
{
    return p<'a'?p-'A':p-'a'+26;
}

int main(){
 //   freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s,e;
        int w;
        scanf(" %c %c %d",&s,&e,&w);
        s=chg(s); e=chg(e);
        a[s][e]+=w; now[e][s]-=w;
        ed[s].push_back(e); ed[e].push_back(s);
    }
    while(1)
    {
        memset(pre,-1,sizeof(pre));
        queue<int> flow;
        flow.push(0);
        while(!flow.empty())
        {
            int p=flow.front(); flow.pop();
            if(p==25) break;
            for(int i:ed[p])
                if(pre[i]<0&&now[p][i]<a[p][i])
                    pre[i]=p,flow.push(i);
        }
        if(pre[25]<0) break;
        int minflow=INT_MAX,pos=25;
        while(pos)
            minflow=min(minflow,a[pre[pos]][pos]-now[pre[pos]][pos]),pos=pre[pos];
        pos=25;
        while(pos)
            now[pre[pos]][pos]+=minflow,now[pos][pre[pos]]-=minflow,pos=pre[pos];
        ans+=minflow;
    }
    printf("%d",ans);
    return 0;
}
