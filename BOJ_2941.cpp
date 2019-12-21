#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define N 55
#define M 100010
#define MOD 15746

int n,m;
char s[8][5]={"c=","c-","d-","lj","nj","s=","z=","dz="},a[110];

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>a;
    for(int i=0;a[i];i++,m++)
    {
        if(!memcmp(s[7],a+i,3)) {i+=2; continue;}
        for(int j=0;j<7;j++)
            if(!memcmp(s[j],a+i,2)) {i++; break;}
    }
    cout<<m;
    return 0;
}
