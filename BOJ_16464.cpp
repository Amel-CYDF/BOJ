#include <bits/stdc++.h>
using namespace std;

int n;

bool gazua(int p)
{
    while(p>1)
    {
        if(p%2) return 1;
        p/=2;
    }
    return 0;
}

int main()
{
   // freopen("input.txt","r",stdin);

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        printf(gazua(k)?"Gazua\n":"GoHanGang\n");
    }

    return 0;
}
