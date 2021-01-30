#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007

int n,m,k,c,d;
vpii node,a,b;

void Solve()
{
    cin>>n>>m>>k;
    c=n-m+k-1; d=n=m-k+1;
    node.pb(mp(79,2)); n--;
    if(n) node.pb(mp(1,79)), n--;
    a.pb(mp(0,1));
    if(n) node.pb(mp(1,1)), n--;
    a.pb(mp(0,2)); b.pb(mp(1,2)); b.pb(mp(1,3));
    for(int i=78;n&&i>1;i--)
    {
        b.pb(mp(node.size(),2));
        if(i!=78) b.pb(mp(node.size(),node.size()-(78-i)));
        node.pb(mp(2,i)); n--;
        if(!n)
        {
            for(int r=3,g=node.size()-(79-i)+1;r<=79-i;r++,g++) b.pb(mp(node.size()-1,g));
        }
        for(int j=3;n&&j<=80-i;j++)
        {
            a.pb(mp(node.size(),node.size()-1));
            if(j!=80-i) b.pb(mp(node.size(),node.size()-(78-i)));
            b.pb(mp(node.size(),node.size()-(78-i)-1));
            node.pb(mp(j,i)); n--;
            if(!n)
            {
                for(int r=j,g=node.size()-1;r>2;r--,g--) b.pb(mp(g,2));
                for(int r=j+1,g=node.size()-(79-i)+1;r<=79-i;r++,g++) b.pb(mp(node.size()-1,g));
            }
        }
        a.pb(mp(node.size()-1,0));
    }
    for(auto i:node) cout<<i.ff<<' '<<i.ss<<'\n';
    for(int x=3,y=79;c--;)
    {
        cout<<x<<' '<<y<<'\n';
        if(x==79) x=83-y, y--;
        else x++;
    }
    for(auto &i:a) i.ff++,i.ss++;
    for(auto &i:b) i.ff++,i.ss++;
    for(auto i:a)
    {
        if(!m) break;
        cout<<i.ff<<' '<<i.ss<<'\n';
        m--;
    }
    for(auto i:b)
    {
        if(!m) break;
        cout<<i.ff<<' '<<i.ss<<'\n';
        m--;
    }
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
}
int main(){ Init(0); //ios::sync_with_stdio(false); cin.tie(NULL);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
