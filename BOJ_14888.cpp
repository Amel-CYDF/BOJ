#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 15
#define M 61
#define MOD 10007

int n,m,a[N],b[4],mans=INT_MAX,Mans=INT_MIN;

int main(){
 //   freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<4;i++) cin>>b[i];
    for(int i=0;i<1<<(n-1<<1);i++)
    {
        int now=a[0],c[4]={};
        for(int j=0;j<n-1;j++) c[i>>(j<<1)&3]++;
        if(memcmp(b,c,16)) continue;
        for(int j=0;j<n-1;j++)
            switch(i>>(j<<1)&3)
            {
                case 0: now+=a[j+1]; break;
                case 1: now-=a[j+1]; break;
                case 2: now*=a[j+1]; break;
                case 3: now/=a[j+1];
            }
        mans=min(mans,now);
        Mans=max(Mans,now);
    }
    printf("%d\n%d",Mans,mans);
    return 0;
}
