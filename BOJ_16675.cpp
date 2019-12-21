#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 62510

char a,b,c,d;
int x,y,z,w;

bool who(char p,char q)
{
    return (p=='R'&&q=='S')||(p=='P'&&q=='R')||(p=='S'&&q=='P');
}

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>a>>b>>c>>d;
    if(who(a,c)&&who(a,d)) {printf("MS"); return 0;}
    if(who(b,c)&&who(b,d)) {printf("MS"); return 0;}
    if(who(c,a)&&who(c,b)) {printf("TK"); return 0;}
    if(who(d,a)&&who(d,b)) {printf("TK"); return 0;}
    printf("?");
    return 0;
}
