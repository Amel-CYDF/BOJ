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
int a[100][100];
int dx[]={0,1,-1,0,-1,1},dy[]={1,-1,-1,-1,1,1};
int b[6][2]={5,4, 5,3, 4,3, 1,2, 2,0, 0,1};

void amel(int r, int p, int x, int y)
{
    if(r==n)
    {
        m+=a[x][y];
        return;
    }
    if(a[x][y]) return;
    a[x][y]=1;
    r++;
    for(int i=2;i--;) amel(r, b[p][i], x+dx[b[p][i]], y+dy[b[p][i]]);
    a[x][y]=0;
    return;
}

void Solve()
{
    cin>>n;
    a[50][50]=1;
    amel(0, 0, 50, 51);
    cout<<m;
}

int main(){
//    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
