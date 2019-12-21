#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define N 110
#define M 12
#define MOD 998244853

double a;
int ans;
char b[4]={0,'U','N','S'};

int main(){
  //  freopen("input.txt","r",stdin);
    for(int i=3;i;i--)
    {
        int p,q;
        cin>>p>>q;
        if(p>=500) p-=50;
        if(a<(double)q/p)
            a=(double)q/p,ans=i;
    }
    cout<<b[ans];

    return 0;
}
