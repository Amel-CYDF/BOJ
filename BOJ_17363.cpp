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
char a[110][110];

void Solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) cin>>a[m-j-1][i];
    for(int i=0;i<m;i++,puts(""))
        for(int j=0;j<n;j++)
            switch(a[i][j])
            {
                case '.': case 'O': cout<<a[i][j]; break;
                case '-': cout<<'|'; break;
                case '|': cout<<'-'; break;
                case '/': cout<<'\\'; break;
                case '\\': cout<<'/'; break;
                case '^': cout<<'<'; break;
                case '<': cout<<'v'; break;
                case 'v': cout<<'>'; break;
                case '>': cout<<'^'; break;
            }
}

int main(){
    //freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
