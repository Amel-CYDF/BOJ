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

int n,w;
double r;
string a,ans;

int amel(string p)
{
    int ret=0;
    for(int i=0,j=0,s=a.size(),t=p.size();;i++,j++)
    {
        if(i>=s) return ret+t-j;
        while(j<t&&a[i]!=p[j]) j++,ret++;
        if(j>=t) return 0;
    }
    return ret;
}

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>a>>n;
    for(string i;n--;)
    {
        cin>>i>>w;
        int t=amel(i);
        if(t&&r<(double)w/t) r=(double)w/t,ans=i;
    }
    if(!r) printf("No Jam");
    else cout<<ans;
    return 0;
}
