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

int n,w,tc,b[25],r[25];
pii c[25];
ll a[25][125],d[25]={1};

int main(){
  //  freopen("input.txt","r",stdin);
    for(int i=1;i<=20;i++) d[i]=d[i-1]*6;
    for(int i=1;i<=20;i++)
        for(int j=0;j<=i*6;j++)
            for(int k=1;k<=6;k++)
                a[i][j]+=j>k?a[i-1][j-k]:d[i-1];
    cin>>tc;
    while(tc--)
    {
        cin>>n>>w;
        for(int i=1;i<=n;i++) scanf("%d",b+i);
        for(int i=1;i<=n;i++) c[i]={b[i],i};
        sort(c+1,c+n+1);
        for(int i=1;i<=n;i++) r[c[i].ss]=i;
        int tmp=0,t=0; ll ans=0;
        for(int i=1;i<=n;i++) tmp+=b[i];
        if(tmp>=w) ans=d[n];
        tmp=w-tmp;
        for(int i=1;i<=n;i++)
        {
            tmp+=c[i].ff;
            ll now=a[i][tmp]*d[n-i];
            if(now>ans) ans=now,t=i;
        }
        cout<<ans<<'\n';
        for(int i=1;i<=n;i++) printf("%d ",r[i]<=t);
        puts("");
    }
    return 0;
}
