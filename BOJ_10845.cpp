#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 100010
#define MOD 15746

int n,m;
queue<int> a;

int main(){
 //   freopen("input.txt","r",stdin);
    scanf("%d",&n);
    while(n--)
    {
        char s[10]; scanf("%s",s);
        if(s[0]=='p'&&s[1]=='u') scanf("%d",&m),a.push(m);
        else if(s[0]=='p') {printf("%d\n",a.empty()?-1:a.front()); if(!a.empty()) a.pop();}
        else if(s[0]=='s') printf("%d\n",a.size());
        else if(s[0]=='e') printf("%d\n",a.empty());
        else if(s[0]=='f') printf("%d\n",a.empty()?-1:a.front());
        else printf("%d\n",a.empty()?-1:a.back());
    }
    return 0;
}
