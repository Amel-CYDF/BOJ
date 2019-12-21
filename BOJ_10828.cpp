#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1000010
#define MOD 1000000

int n,m;
stack<int> a;

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    while(n--)
    {
        char s[10]; scanf("%s",s);
        if(s[0]=='p'&&s[1]=='u') {int t; scanf("%d",&t); a.push(t);}
        else if(s[0]=='p') {printf("%d\n",a.empty()?-1:a.top()); if(!a.empty()) a.pop();}
        else if(s[0]=='s') printf("%d\n",a.size());
        else if(s[0]=='e') printf("%d\n",a.empty());
        else printf("%d\n",a.empty()?-1:a.top());
    }
    return 0;
}
