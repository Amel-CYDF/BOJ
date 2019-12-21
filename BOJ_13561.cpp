#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define N 1000010
#define M 100010
#define MOD 1000000009

int n,m,cnt[M],p;
pii ans={1,INT_MAX},a[N];

int main(){
   // freopen("input.txt","r",stdin);
    cin>>m>>n;
    for(int i=1;i<=n;i++) scanf("%d %d",&a[i].ff,&a[i].ss);
    sort(a+1,a+n+1);
    for(int fr=1,rr=1;fr<=n;)
    {
        for(int i=a[fr].ff;fr<=n&&a[fr].ff==i;fr++)
        {
            if(!cnt[a[fr].ss]) p++;
            cnt[a[fr].ss]++;
        }
        if(p!=m) continue;
        while(p==m)
            for(int i=a[rr].ff;rr<=n&&a[rr].ff==i;rr++)
            {
                cnt[a[rr].ss]--;
                if(!cnt[a[rr].ss]) p--;
            }
        fr--; rr--;
        if(ans.ss>a[fr].ff-a[rr].ff+1>>1)
            ans={a[fr].ff+a[rr].ff>>1,a[fr].ff-a[rr].ff+1>>1};
        fr++; rr++;
    }
    cout<<ans.ff;
    return 0;
}
