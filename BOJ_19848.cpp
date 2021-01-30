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

int n,m;
string a;
list<int> b;

void Solve()
{
    cin>>a;
    m=a.front();
    int k=0;
    for(auto &i:a)
    {
        if(i!=m)
        {
            b.pb(k);
            n++;
            k=1;
            m=i;
        }
        else k++;
    }
    b.pb(k);
    cout<<(n+2>>1)<<'\n';
    while(1)
    {
        if(b.size()==2)
        {
            cout<<"1 "<<b.front()+b.back();
            return;
        }
        else
        {
            auto t=b.begin();
            ++t; auto p=*t; ++t; auto q=*t;
            int r=b.front()+p;
            cout<<r-min(p,q)+1<<' '<<r+min(p,q)<<'\n';
            if(p<=q)
                b.front()+=q-p;
            else
            {
                ++t;
                if(t!=b.end())
                    *t+=p-q;
                else t=b.insert(t,p-q);
                --t;
            }
            --t; t=b.erase(t); b.erase(t);
        }
    }
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(0);
//    int tc; cin>>tc; for(int i=1;i<=tc;i++)
//    cout<<"Case #"<<i<<'\n',
    Solve();
    return 0;
}
