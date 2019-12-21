#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 100010
#define M 0
#define MOD 15746

struct amel
{
    int a,b;
    char s[110];
    bool operator<(const amel &rhs)const
    {
        return a==rhs.a?b<rhs.b:a<rhs.a;
    }
}a[N];

int n,m,ans[N],dap;

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i].a>>a[i].s,a[i].b=i;
    sort(a,a+n);
    for(int i=0;i<n;i++) printf("%d %s\n",a[i].a,a[i].s);
    return 0;
}
