#include <iostream>
#include <algorithm>
using namespace std;
bool v[600];
int primes[30],index = 0;
int main(){
		std::ios::sync_with_stdio(false);
for(int i = 2 ; i < 501 ; i++){
	if(!v[i]){
		primes[index++] = i;
		for(int j = i*i ; j < 501 ;j+=i)
			v[j] = true;
	}
}
int n;

while(cin >> n&&n){

long long c = 0;
for(int i = 1 ; i < n ;i++){
     int factors[100],x = 0;
     int count[100];
     for(int j = 1 ; j*j <= i ;j++)
     	if(!(i%j)){
     		factors[x++] = j;
     		if(j != i/j)
     		factors[x++]  = i/j;
     	}
     	sort(factors,factors+x);
     	for(int k = x - 1; k >= 0 ; k--){
     		int c2 = (n-i)/factors[k];
     		for(int z = 0 ; z < x ;z++)
     			if(z!=k&&!(factors[z]%factors[k])){
     				c2-=count[z];
     			}
     			count[k] = c2;
     			c+=c2*factors[k];
     	}
}
cout<<c<<endl;
}
	return 0;
}
/*
int main(){
int n;
   cin >> n ;
   int x = 0 , c = 0,g ;
   for(int i = 1 ; i < n ;i++){
   	cout<<i<<" ";
   	for(int j = i + 1 ; j <= n;j++)
   		g = gcd(i,j),x+=g,c+=g,cout<<g<<" ";
   	cout<<endl<<x<<endl;
   	x = 0;
   }
cout<<c<<endl;
    return 0;
}
*/