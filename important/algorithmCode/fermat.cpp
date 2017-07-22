#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
ll modulo (ll a, ll b, ll c)
{
    int result = 1;

    while (b)
    {
        if (b&1){
          result *= a;
          result %= c;
        }
        b >>=1 ;
        a *= a;
        a %= c;
    }

    return result;
}

int isPrime(ll n)
{
    int i;
    int x;

    if (n==2)
        return 1;

    for (i=0;i<10;i++){
        x = rand()%n;
        if (x==0||x==1)
            x++;
        if (modulo(x,n-1,n)!=1)
            return 0;
    }

    return 1;
}

int main()
{
    ll i;
    int count = 0;

    for (i=2;i<10;i++){
        if(isPrime(i))
            count++;
    }

    printf("count=%dn",count);

return 0;
} 