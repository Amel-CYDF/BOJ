#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 1010

int n;
ll ans;
stack<int> t;

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n;
    for(int j;n--;)
    {
        cin>>j;
        while(!t.empty()&&t.top()<=j) t.pop();
        ans+=t.size();
        t.push(j);
    }
    cout<<ans;

    return 0;
}