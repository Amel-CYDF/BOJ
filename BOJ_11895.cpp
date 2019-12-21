#include <bits/stdc++.h>
using namespace std;

int n,ans,minnum=INT_MAX;
int one[32];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        ans+=a;
        minnum=min(minnum,a);
        for(int j=0;a;j++,a>>=1) one[j]+=a%2;
    }
    for(int i=0;i<32;i++) if(one[i]%2) minnum=ans;
    printf("%d",ans-minnum);
    return 0;
}
