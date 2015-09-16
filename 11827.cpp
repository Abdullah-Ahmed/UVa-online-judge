#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;
int a[10000];
bool v[10000001];
long long primes[700000];
int index = 0;
vector<int> divs[200];
void factors(long long x,int c){
	long long p = primes[0];
	int idx = 1;
	while(p*p <= x && x!= 1){
		while(!(x%p)){
			x/=p;
			divs[c].push_back(p);
		}
		p = primes[idx++];
	}
	if(x!= 1)
		divs[c].push_back(x);
}
long long interSection(int x,int y){
	int i = 0,j = 0;
	long long cs = 1;
		if(!a[x])
			return a[y];
if(!a[y]) return a[x];


	while(i<divs[x].size()&&j < divs[y].size()){
		if(divs[x][i] == divs[y][j])
			cs*= divs[x][i],i++,j++;
		else if(divs[x][i] < divs[y][j]) i++;
		else j++;
	}
	return cs;
}
int main(){
		std::ios::sync_with_stdio(false);
//	freopen("in.txt","r",stdin);
for(long long i = 2 ; i < 10000001;i++){
	if(!v[i]){
		primes[index++] = i;
	for(long long j = i*i ; j < 10000001;j+=i)
		v[j] = true;
}
}
string s;
int n = 1,m;
 cin >> n;
 getline(cin,s);
 while(n--){
  m = 1;
//cin >> a[0]; while(cin.peek()!='\n') cin >> a[m++];

getline(cin,s);
		istringstream streams(s);
		m = 0;

		while(streams>>a[m]) ++m;

for(int i = 0;i < m;i++){
    divs[i].clear();
	factors(a[i],i);
}

long long  mx = 0;
for(int i = 0;i < m;i++)
	for(int j = i+1;j<m;j++)
		mx = max(mx,interSection(i,j));
	cout<<mx<<'\n';
}
    return 0;
}
