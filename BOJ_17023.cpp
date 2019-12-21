#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,m,t;
long long ans;
int cow[10010],par[10010],sh[10010],ind[10010];
bool vis[10010];
vector<pii> edge[10010];

struct quecomp
{
    bool operator()(const pii &lhs,const pii &rhs)
    const{
        return lhs.second>rhs.second;
    }
};

priority_queue<pii,vector<pii>,quecomp> myque;

int main(){
    scanf("%d %d %d",&n,&m,&t); for(int i=2;i<=n;i++) sh[i]=INT_MAX;
    for(int i=1;i<=n;i++) scanf("%d",cow+i);
    for(int i=0;i<m;i++)
    {
        int st,ed,w;
        scanf("%d %d %d",&st,&ed,&w);
        edge[st].push_back({ed,w});
        edge[ed].push_back({st,w});
    }

    myque.push({1,0});
    while(!myque.empty())
    {
        pair<int,int> k=myque.top();
        myque.pop();
        if(vis[k.first]) continue;
        vis[k.first]=1; sh[k.first]=k.second;

        for(auto i:edge[k.first])
        {
            if(sh[i.first]>k.second+i.second)
                sh[i.first]=k.second+i.second,par[i.first]=k.first,myque.push({i.first,sh[i.first]});
            else if(sh[i.first]==k.second+i.second&&par[i.first]>k.first) par[i.first]=k.first;
        }
    }

    for(int i=2;i<=n;i++) ind[par[i]]++;
    queue<int> que;
    for(int i=2;i<=n;i++) if(!ind[i]) que.push(i);
    while(!que.empty())
    {
        int k=que.front();
        que.pop();
        ans=max(ans,(long long)cow[k]*(sh[k]-t));

        ind[par[k]]--; cow[par[k]]+=cow[k];
        if(!ind[par[k]]) que.push(par[k]);

    }

    printf("%lld",ans);

    return 0;
}
