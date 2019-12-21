#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1010
#define M 25
#define MOD 10007

int n,m,a[N][N],rg[N][N];
ll ans;

struct amel
{
    int cnt,v,h;
    ll b;
};

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%d",a[i]+j);
    for(int i=0;i<n;i++)
        for(int j=m-1,cnt=1;j>=0;rg[i][j--]=cnt)
            if(j!=m-1&&a[i][j+1]==a[i][j]) cnt++;
            else cnt=1;
    for(int i=0;i<m;i++)
    {
        stack<amel> s;
        for(int j=0;j<n;j++)
        {
            amel tmp={1,a[j][i],rg[j][i],0ll};
            while(!s.empty()&&s.top().v==a[j][i]&&s.top().h>=rg[j][i])
                {tmp.cnt+=s.top().cnt; s.pop();}
            ans+=tmp.b=(ll)tmp.cnt*rg[j][i];
            if(!s.empty()&&s.top().v==a[j][i])
                {ans+=s.top().b; tmp.b+=s.top().b;}
            s.push(tmp);
        }
    }
    printf("%lld",ans);
    return 0;
}
