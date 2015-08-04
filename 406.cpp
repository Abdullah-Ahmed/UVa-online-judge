#include <iostream>
#define endl '\n'
using namespace std;
bool v[1000001];
long long primes[700000];
int fast[2000];
int index = 1;
int main(){
    	std::ios::sync_with_stdio(false);
primes[0] = 1;
for(long long i = 2 ; i*i < 1000001;i++){
        fast[i] = index;
    if(!v[i]){
        primes[index++] = i;
        for(long long j = i*2 ; j < 1000001;j+=i)
            v[j] = true;
    }
}
int x,c;
while(cin >> x >> c){
    int  k = fast[x]+!v[x];// cout<<k<<endl;
    int y = k-c*2;
   int z =  y/2+(y%2);// cout<<z<<" "<<y<<endl;
   cout<<x<<" "<<c<<":";
if(y >= 0){
    for(int j = z;j < k-z ;j++)
        cout<<" "<<primes[j];
}else for(int i = 0 ; primes[i] <= x && i < index;i++)  cout<<" "<<primes[i];
cout<<endl<<endl;
}
    return 0;
}
