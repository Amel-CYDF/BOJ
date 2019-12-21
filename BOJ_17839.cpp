#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 62510

int n,vis[N];
map<string,int> a;
list<int> ed[N];

void dfs(int p)
{
    if(vis[p]) return;
    vis[p]=1;
    for(int i:ed[p]) dfs(i);
}

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=n;i--;)
    {
        string p,q,tmp;
        cin>>p>>tmp>>q;
        if(a.find(p)==a.end()) a[p]=a.size()+1;
        if(a.find(q)==a.end()) a[q]=a.size()+1;
        ed[a[p]].pb(a[q]);
    }
    string tmp("Baba");
    dfs(a[tmp]);
    a.erase(tmp);
    for(auto i:a)
        if(vis[i.ss]) cout<<i.ff<<'\n';
    return 0;
}
