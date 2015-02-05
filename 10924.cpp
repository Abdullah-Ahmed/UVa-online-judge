#include <iostream>
#include <bits/stdc++.h>
#include <map>
#define space  " "
using namespace std;
bool v[10000001] = {false};

int main(){


	for (long long i = 2; i * i < 10000001; i++) {
		if (!v[i]) {
			for (long long j = i * i; j < 10000001; j += i) {
				v[j] = 1;
			}
		}
	}


map<char,int> mp;
int c = 1;
for(char i = 'a' ; i<= 'z';i++)mp[i] = c++;
for(char i = 'A' ; i<= 'Z';i++)mp[i] = c++;
string s;
while(cin>>s){
    long long cs = 0;
    for(int i  = 0 ; i< s.size() ; i++) cs += mp[s[i]];
    if(v[cs]) cout<<"It is not a prime word."<<endl;
    else cout<<"It is a prime word."<<endl;
}
    return 0;
}
