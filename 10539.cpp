#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>
#define space " "
using namespace std;

int intlog(double base, double x) {
    return (int)(log(x) / log(base));
}

long long power(long long base , long long p){
	if(p == 1)
		return base;
	if(base%2) return base*power(base,p-1);
	long long rest = power(base,p/2);
	return rest * rest ;
}

bool v[10000001] ={false};
long long primes [700000];
int index = 0;
int main(){
 freopen("in.txt","r",stdin);

for(long long i = 2 ; i < 10000001 ; i++)
	if(!v[i]){
		primes[index++] = i;
		for(long long j = i * i ; j < 10000001 ; j+= i)
			        v[j] = true;
}
long long  l , h;
int tc=1;
cin >>tc;
while(tc--){
long long c = 0 ,t;
cin >> l >> h ;
for(int i = 0 ; i < index; i++){
     t = 0;
long long z = primes[i];
     while(z <= h){
      z*= primes[i];
      if(z >= l && z <= h) t++; 
     }
          c+=t; t = 0;
}
cout<<c<<endl;
}
    return 0;
}
/*
We Can solve it using log but log gets with TLE
for(int i = 0 ; i < index ; i++){
          t = intlog(primes[i],h)-intlog(primes[i],l);
          t--; // Number it self 
          if(t < 0) t = 0;
          c+=t;
}
*/
