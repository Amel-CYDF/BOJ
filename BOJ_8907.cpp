#include <bits/stdc++.h>
using namespace std;

int n,a[1010][1010],ans;

void init()
{
    ans=0;
    for(int i=0;i<1010;i++)
        for(int j=0;j<1010;j++) a[i][j]=0;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++) scanf("%d",&a[i][j]),a[j][i]=a[i][j];

        for(int i=0;i<n;i++)
        {
            int red=0,blue=0;
            for(int j=0;j<n;j++) a[i][j]?red++:blue++;
            blue--;
            ans+=red*blue;
        }

        printf("%d\n",n*(n-1)*(n-2)/6-ans/2);
    }
    return 0;
}
