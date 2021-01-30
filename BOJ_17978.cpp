#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1'000'000'009
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
int n,m;

struct node
{
    int x,y,z;
    node(){}
    node(int xx,int yy,int zz){x=xx; y=yy; z=zz;}
};

//vector<node> a;
//vector<bool> b;
node a[105];
bool b[105];

double amel()
{
    double x=0,y=0,z=0,xx=0,yy=0,zz=0,ret=0;
    int p=0,q=0;
    for(int i=n;i--;)
    {
        if(b[i]) xx+=a[i].x,yy+=a[i].y,zz+=a[i].z,q++;
        else x+=a[i].x,y+=a[i].y,z+=a[i].z,p++;
    }
    if(p) x/=p,y/=p,z/=p;
    if(q) xx/=q,yy/=q,zz/=q;
    for(int i=n;i--;)
        ret+=b[i]?(xx-a[i].x)*(xx-a[i].x)+(yy-a[i].y)*(yy-a[i].y)+(zz-a[i].z)*(zz-a[i].z):(x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y)+(z-a[i].z)*(z-a[i].z);
    return ret;
}

node crossprod(const node &p,const node &q)
{
    return node(p.y*q.z-p.z*q.y,p.z*q.x-p.x*q.z,p.x*q.y-p.y*q.x);
}

bool dotprod(const node &p,const node &q)
{
    return (ll)p.x*q.x+(ll)p.y*q.y+(ll)p.z*q.z>0;
}

void Solve()
{
    cin>>n>>m;
//    a.resize(n);
//    b.resize(n,false);
//    for(auto &i:a) cin>>i.x>>i.y>>i.z;
    for(int i=n;i--;) cin>>a[i].x>>a[i].y>>a[i].z;
    double ans=amel();
    if(n<3&&m&2) ans=0;
    if(m&2)
    {
        for(int i=n;i--;)
            for(int j=i;j--;)
                for(int k=j;k--;)
                {
                    node t=crossprod(node(a[i].x-a[j].x,a[i].y-a[j].y,a[i].z-a[j].z),node(a[i].x-a[k].x,a[i].y-a[k].y,a[i].z-a[k].z));
                    for(int d=8;d--;)
                    {
                        for(int r=n;r--;)
                            b[r]=dotprod(t,node(a[r].x-a[i].x,a[r].y-a[i].y,a[r].z-a[i].z));
                        b[i]=d&1; b[j]=d&2; b[k]=d&4;
                        ans=min(ans,amel());
                    }
                }
    }
    printf("%.06f",ans);
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
//	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){Init(0);
//    int tc; cin>>tc; for(int i=1;i<=tc;i++)
//    cout<<"Case #"<<i<<'\n',
    Solve();
    return 0;
}
