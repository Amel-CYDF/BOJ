#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

int n;
char c[]={'(',')','{','}','[',']'};
string a[1010]={"","01","23","45"};

void amel(int p,string q)
{
    if(a[p].length()>q.length() || (a[p].length()==q.length()&&a[p]>q)) a[p]=q;
}

int main(){
   // freopen("input.txt","r",stdin);
    for(int i=4;i<=1000;i++)
    {
        a[i]="01"+a[i-1];
        for(int j=2;j<i;j++) amel(i,a[j]+a[i-j]);
        if(i%2==0) amel(i,"0"+a[i/2]+"1");
        if(i%3==0) amel(i,"2"+a[i/3]+"3");
        if(i%5==0) amel(i,"4"+a[i/5]+"5");
    }
    cin>>n;
    for(int i;n--;puts(""))
    {
        cin>>i;
        for(auto j:a[i]) cout<<c[j-'0'];
    }
    return 0;
}