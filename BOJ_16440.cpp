#include <bits/stdc++.h>
using namespace std;

int n;
bool a[200010];


int main(){
 //   freopen("input.txt","r",stdin);

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char c;
        scanf(" %c",&c);
        if(c=='s') a[i]=1;
    }

    int cnt=0;
    for(int i=0;i<n/2;i++) if(a[i]) cnt++;
    if(cnt==n/4) printf("1\n%d",n/2);
    else
    {
        for(int i=n/2;;i++)
        {
            if(a[i-n/2]) cnt--;
            if(a[i]) cnt++;
            if(cnt==n/4) { printf("2\n%d %d",i+1-n/2,i+1); break; }
        }
    }

    return 0;
}
