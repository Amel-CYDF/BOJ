#include <bits/stdc++.h>
using namespace std;

char c[1000010];
int n,ans;

int main(){
 //   freopen("input.txt","r",stdin);

    scanf("%s",c);
    n=strlen(c);

    int cnt=0;
    stack<int> sk;
    for(int i=0;i<n;i++)
    {
        if(c[i]=='(') sk.push(0),cnt++;
        else
        {
            cnt--;
            if(c[i-1]==')') ans++,sk.pop();
            else sk.pop(),ans+=cnt;
        }
    }
    printf("%d",ans);

    return 0;
}
