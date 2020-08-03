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

int n,m,ans[1000030][3];
string d[3]={"1-3-5-7-9-12-15-1...", "1-3-5-7-10-13-16-...", "-2-4-6-8-11-14-17..."};

ll mpow(ll p, int q, int r)
{
    if(!q) return 1;
    return mpow(p*p%r, q>>1, r) * (q&1 ? p : 1ll) % r;
}

void Init()
{
    ans[3][1]=1; ans[3][2]=2;
    int p, q=10;
    for(int i=4;i<=1000020;i++)
    {
        p = q * 10 % (i-1);
        q=mpow(10, i-2, i);
        for(int j=0;j<3;j++)
        {
            int t= (p - ans[i-1][j] + i - 1) % (i-1);
            if(!t) t=i-1;
            ans[i][j]=(q - t + i) % i;
        }
    }
}

void Solve()
{
    cin>>n>>m;
    if((m==0&&n<21)||(m==1&&n<3))
    {
        string ret;
        for(int i = n * (m?10:1); i>0; i--)
        {
            for(int j=i;j;j/=10) ret.pb(j%10+'0'),i--;
            if(i>0) ret.pb('-');
        }
        reverse(ret.begin(), ret.end());
        cout<<ret<<'\n';
    }
    else
    {
        int t=m+1;
        for(int i=n; i; i/=10) t++;
        int r= (int)(mpow(10, m, t) * (n%t) % t);
        if((ans[t][0]<=r && r<ans[t][1])||(ans[t][0]>ans[t][1] && (ans[t][0]<=r || r<ans[t][1]))) cout<<d[0]<<'\n';
        else if((ans[t][1]<=r && r<ans[t][2])||(ans[t][1]>ans[t][2] && (ans[t][1]<=r || r<ans[t][2]))) cout<<d[1]<<'\n';
        else cout<<d[2]<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
   // freopen("input.txt","r",stdin);
    Init();
    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
