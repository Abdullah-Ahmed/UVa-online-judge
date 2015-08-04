#include <iostream>
#define endl '\n'
using namespace std;
bool v[10000001];
long long primes[700000],index = 0;
int main(){
		std::ios::sync_with_stdio(false);
     v[0] = v[1] = true;
     for(long long i = 2 ; i < 10000001;i++){
     	if(!v[i]){
     		primes[index++] = i;
     		for(long long j = i*2;j < 10000001;j+=i){
     			v[j] = true;
     		}
     	}
     }

int n,ns;

while(cin >> n){
if(n < 8) {
	cout<<"Impossible.\n";
	continue;
}
ns = n;
ns-=4+(n%2);
int h = index , l = 0,m;
for(int i = 0 ; i < 30;i++){
m = (h+l)/2;
if(primes[m] > ns)
h = m;
else l = m;
}
for(int i = m;i >= 0;i--){
	if(primes[i] < ns &&!v[ns - primes[i]]){
		cout<<2<<" "<<2+(n%2)<<" "<<primes[i]<<" "<<ns-primes[i]<<endl;
	      break;
	}
}

}
    return 0;
}
