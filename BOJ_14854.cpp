#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

int n,m,a[]={27,11,13,37},b[]={-5291,-38961,-32967,77220};

int rever(int p,int mod)
{
    p%=mod;
    if(p<0) p+=mod;
    int s=1,t=0,tmp,ttmp;
    while(p)
    {
        tmp=mod/p;
        ttmp=p; p=mod%p; mod=ttmp;
        ttmp=s; s=t-s*tmp; t=ttmp;
    }
    return t;
}

ll many(ll p,ll mod)
{
    ll ret=0;
    for(ll i=mod;mod<=p;mod*=i) ret+=p/mod;
    return ret;
}

int pac(int p,int mod)
{
    if(!p) return 1;
    int ret=(p/mod&1)?-1:1;
    ret*=pac(p/(mod==27?3:mod),mod);
    p%=mod;
    for(;p;p--) if(__gcd(p,mod)==1) ret*=p,ret%=mod;
    return ret;
}

int namogi()
{
    int ret=0,tmp=many(n,3)-many(m,3)-many(n-m,3);
    for(int i=0;i<4;i++)
    {
        if(i) tmp=many(n,a[i])-many(m,a[i])-many(n-m,a[i]);
        if((i&&tmp)||(!i&&tmp>2)) continue;
        if(!tmp) tmp=1;
        else if(tmp==1) tmp=3;
        else tmp=9;
        ret+=b[i]*pac(n,a[i])*rever(pac(m,a[i]),a[i])%142857*rever(pac(n-m,a[i]),a[i])*tmp;
        ret%=142857;
    }
    return (ret+142857)%142857;
}

int main(){
    freopen("input.txt","r",stdin);
    int tt; cin>>tt;
    while(tt--) scanf("%d %d",&n,&m),printf("%d\n",namogi());
    return 0;
}