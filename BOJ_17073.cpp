#include <bits/stdc++.h>
using namespace std;

int n,w,cnt,vis[500010];
vector<int> a[500010];

void dfs(int p)
{
    vis[p]=1;
    int flag=0;
    for(int i=0;i<a[p].size();i++)
        if(!vis[a[p][i]])
        {
            flag=1;
            dfs(a[p][i]);
        }
    if(!flag) cnt++;
}

int main(){
  //  freopen("input.txt","r",stdin);

    scanf("%d %d",&n,&w);
    for(int i=0;i<n-1;i++)
    {
        int p,q;
        scanf("%d %d",&p,&q);
        a[p].push_back(q);
        a[q].push_back(p);
    }
    dfs(1);
    printf("%f",(double)w/cnt);

    return 0;
}
