#include <iostream>
#include <stdio.h>
#define loop(i,s,e) for(int i=s;i<=e;i++)
#define space " "
using namespace std;
unsigned long long int a[1000001];
void solve(int n)
{
    long long prev=2,nxt=1,incr=0;
    long long tmp=1;
    a[3]=0,a[4]=1;
    loop(x,5,n)
    {
        a[x]=(a[x-1]+(prev*nxt)),incr++,nxt++;
        if(incr==2) prev=nxt,nxt=prev-1,incr=0;
    }
}

int main()
{
    solve(1000001);
    int n;
    scanf("%d",&n);
    while(n>=3)
    {
        printf("%llu\n",a[n]);
        scanf("%d",&n);
    }

    return 0;
}