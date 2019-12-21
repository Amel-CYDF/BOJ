#include <stdio.h>
int narr[1001];
int marr[1001];
long long int result = 1;
int count;
int gcd(int a, int b)
{
    if(a%b==0) return b;
    return gcd(b, a%b);
}
void amel(int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            long long int temp;
            temp = gcd(narr[i], marr[j]);
            result *= temp;
            narr[i] /= temp;
            marr[j] /= temp;
            if(result>=1000000000)
            {
                result %= 1000000000;
                count++;
            }
        }
    }
}
int main(void)
{
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &narr[i]);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) scanf("%d", &marr[i]);
    amel(n, m);
    if(count == 0) printf("%d", result);
    else printf("%09d", result);
    return 0;
}