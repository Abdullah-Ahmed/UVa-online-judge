#include <iostream>
#include <stdio.h>
#define loop(i,s,e) for(int i = s ; i< e ; i++)
#define space " "
#define ast "***"
using namespace std;
long long x;
long long check(long long range){
long long startpoint = (range * (range-1))/2 + 1;
return (range - (x-startpoint));
}
int  main(){
    freopen("in.txt","r",stdin);
    while(cin >> x){
    long long h,m,l,value;
h =1000000;
l = 0;
int j = 0,c ;
long long oldm = 0;
while(h > l){
    m = (l+h)/2;
    if(oldm == m)c++;
     value = check(m);

    if(value >= 1 && value <= m){
        break;
    }
    if(value > m)
        h = m;
    else if(value <= 0)
        l = m+1;
        j++;
}
cout<<value<<"/"<<(m - value+1)<<endl;
    }
return 0 ;
}
