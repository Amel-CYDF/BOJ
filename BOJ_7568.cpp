#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define N 55
#define M 100010
#define MOD 15746

int n,m;
pii a[N];

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d %d",&a[i].first,&a[i].second);
    for(int i=0;i<n;i++)
    {
        m=0;
        for(int j=0;j<n;j++) if(a[i].first<a[j].first&&a[i].second<a[j].second) m++;
        printf("%d ",m+1);
    }
    return 0;
}
