#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define N 200010
#define M 25
#define MOD 998244853

int n,m,ans;

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n;
    while(cin>>n>>m)
    {
        int ans=!((m-1>>1)-(n>>1)&1);
        for(int i=1;m>>i;i++)
        {
            int lf=n/(1<<i+1),rg=m/(1<<i+1),tmp=0;
            if(lf==rg) tmp=max(0,m%(1<<i+1)-max(n%(1<<i+1),1<<i)+1);
            else tmp=(1<<i+1)-max(n%(1<<i+1),1<<i)+max(0,m%(1<<i+1)+1-(1<<i));
            if(tmp&1) ans|=1<<i;
        }
        printf("%d\n",ans);
    }
    return 0;
}
