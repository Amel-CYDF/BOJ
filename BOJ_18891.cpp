#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

int n,nn,e=253;
ll m;

struct party
{
    string name;
    int r,b,s,t,u;
    double p;
};
vector<party> a,no;

bool cmp(party lhs,party rhs)
{
    if(lhs.r+lhs.s+lhs.t!=rhs.r+rhs.s+rhs.t) return lhs.r+lhs.s+lhs.t>rhs.r+rhs.s+rhs.t;
    return lhs.name<rhs.name;
}

bool ccmp(pair<double,int> lhs,pair<double,int> rhs)
{
    if(abs(lhs.ff-rhs.ff)>1e-12) return lhs.ff<rhs.ff;
    return a[lhs.ss].u>a[rhs.ss].u;
}

void print()
{
    for(auto i:a)
    {
        cout<<i.name<<' '<<i.r<<' '<<i.s<<' '<<i.t<<'\n';
    }
}

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n>>m;
    a.resize(n);
    for(int i=0;i<n;i++) cin>>a[i].name>>a[i].r>>a[i].b,a[i].u=i;
    sort(a.begin(),a.end(),cmp);
    m=0; for(auto i:a) m+=(ll)i.b,e-=i.r;
    for(int i=n-1;i>=0&&a[i].r<5;i--)
        if((ll)a[i].b*100<m*3) e+=a[i].r,no.pb(a[i]),a.erase(a.begin()+i);
    n=a.size();
    e=300-e;
    m=0; for(auto i:a) m+=(ll)i.b;
    for(auto &i:a) i.p=(double)i.b/m;
    //1
    int cnt=0;
    for(int i=n;i--;)
    {
        double tmp=(a[i].p*e-a[i].r)/2;
        if(tmp<1&&abs(tmp-1)>1e-12) continue;
        int ttmp=floor(tmp*2+1e-12);
        cnt+=a[i].s=ttmp+1>>1;
    }
    //2-1
    if(cnt<=30)
    {
        pair<double,int> tmp[55];
        cnt=30-cnt;
        int ccnt=cnt;
        for(int i=n;i--;)
        {
            double ttmp=a[i].p*cnt;
            int x=floor(ttmp+1e-12);
            a[i].s+=x; tmp[i]={ttmp-x,i}; ccnt-=x;
        }
        sort(tmp,tmp+n,ccmp);
        for(int i=n;ccnt--&&i--;) a[tmp[i].ss].s++;
    }
    //2-2
    else
    {
        pair<double,int> tmp[55];
        int ccnt=30;
        for(int i=n;i--;)
        {
            double ttmp=(double)30*a[i].s/cnt;
            int x=floor(ttmp+1e-12);
            a[i].s=x; tmp[i]={ttmp-x,i}; ccnt-=x;
        }
        sort(tmp,tmp+n,ccmp);
        for(int i=n;ccnt--&&i--;) a[tmp[i].ss].s++;
    }
    //3
    pair<double,int> tmp[55];
    cnt=17;
    for(int i=n;i--;)
    {
        double ttmp=a[i].p*17;
        int x=floor(ttmp+1e-12);
        a[i].t=x; tmp[i]={ttmp-x,i}; cnt-=x;
    }
    sort(tmp,tmp+n,ccmp);
    for(int i=n;cnt--&&i--;) a[tmp[i].ss].t++;
    sort(a.begin(),a.end(),cmp);
    for(auto i:a) cout<<i.name<<' '<<i.r+i.s+i.t<<'\n';
    reverse(no.begin(),no.end());
    for(auto i:no) cout<<i.name<<' '<<i.r<<'\n';
    return 0;
}
