#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m;
vi a,ans;
vector<vi> ed;
queue<pii> bfs;

void Solve()
{
    cin>>n;
    ans.resize(n, -1);
    a.resize(n, 0);
    ed.resize(n);
    for(int i=0,j;i<n;i++)
        do
        {
            cin>>j;
            j--;
            ed[i].pb(j);
        }while(~j);
    cin>>m;
    for(int i;m--;) cin>>i, --i, bfs.push({i,0}), ans[i]=0;
    while(!bfs.empty())
    {
        auto t=bfs.front(); bfs.pop();
        t.ss++;
        for(auto i:ed[t.ff])
            if(!~ans[i])
            {
                a[i]++;
                if(a[i] >= ed[i].size()>>1) bfs.push({i, t.ss}), ans[i]=t.ss;
            }
    }
    for(auto i:ans) cout<<i<<' ';
}

int main(){
 //   freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
