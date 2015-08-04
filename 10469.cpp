#include <iostream>

using namespace std;

int main(){
		std::ios::sync_with_stdio(false);
	int n,m,c;
	while (cin >> n >> m){
	 c = 0;
	for(int i = 0,k = 1 ; i < 32;i++,k*=2){
		if ( ( ((n&(1<<i)) != 0) + ((m&(1<<i))!= 0) ) % 2 )
			c+=k;
	}
cout<<c<<endl;
}
    return 0;
}
