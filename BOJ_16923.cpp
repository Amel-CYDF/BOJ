#include <bits/stdc++.h>
using namespace std;

char a[27];
char b[27];
bool c[30];

int main(){
    scanf("%s",a);
    for(int i=0;i<26;i++) if(a[i]) a[i]-='a'-1;
    if(a[25])
    {
        for(int i=0;i<26;i++) b[i]=a[i];
        if(!next_permutation(a,a+26)) printf("-1");
        else for(int i=0;!i||b[i-1]==a[i-1];i++) printf("%c",a[i]+'a'-1);
    }
    else
    {
        for(int i=0;a[i];i++) c[a[i]]=1;
        for(int i=0;a[i];i++) printf("%c",a[i]+'a'-1);
        int ans=1;
        while(c[ans]) ans++;
        printf("%c",ans+'a'-1);
    }
    return 0;
}
