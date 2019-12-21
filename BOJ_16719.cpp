#include <bits/stdc++.h>
using namespace std;

char c[110];
int n,a[110];

pair<bool,int> amel(int st)
{
    int ret=105;
    for(;c[st]&&!a[st];st++)
        if(c[ret]>c[st]) ret=st;
    if(ret==105) return {0,0};
    if(!c[st]||c[ret]<c[st]) return {1,ret};
    return {0,ret};
}

void print()
{
    for(int i=0;c[i];i++)
        if(a[i]) printf("%c",c[i]);
    printf("\n");
}

int main(){
    //freopen("input.txt","r",stdin);
    
    scanf("%s",c);
    n=strlen(c);
    c[105]=111;

    for(int i=0;c[i];i++)
    {
        int ans=0,flag=0;
        for(int j=-1;j<0||c[j];j++)
            if(j<0||a[j])
            {
                pair<bool,int> tmp=amel(j+1);
                if(tmp.first) { a[tmp.second]=1,flag=1; break; }
                if(tmp.second) ans=tmp.second;
            }
        if(!flag) a[ans]=1;
        print();
    }

    return 0;
}
