#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char a[1010],b[1010];
        scanf("%s %s",a,b);
        int x=strlen(a),y=strlen(b);
        if(x!=y) {printf("Impossible\n"); continue;}
        sort(a,a+x);
        sort(b,b+y);
        int j=0;
        while(a[j]&&a[j]==b[j]) j++;
        printf(j==x?"Possible\n":"Impossible\n");
    }
    return 0;
}
