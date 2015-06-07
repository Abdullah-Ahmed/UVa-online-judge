#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define space "  "
using namespace std;
typedef long long ll;
bool v[10000000];
ll primes[700000];
int index = 0;
vector<ll>anagrams;
vector<ll>finalanagrams;
int takens[10];
bool selected[10] = {false};
vector<ll>all;
bool permutaion(int x[],int idx,int index){
if(index == idx){
    ll s = 0;
    for(int i = 0 ; i < idx;i++)s*=10,s+=takens[i];
    if(v[s]) return false;
    all.push_back(s);
}
for(int i = 0 ; i < idx ;i++){
    if(!selected[i]){
        selected[i] = true;
        takens[index] = x[i];
       if(!permutaion(x,idx,index+1))
               return false;
        selected[i] = false;
    }
}
return true;
}
void check(ll n){
int x[10],idx = 0;
int m = n;
while(m)
    x[idx++] = m%10,m/=10;
all.clear();
for(int i = 0 ; i < 10 ; selected[i++] = false);
if(permutaion(x,idx,0)){
for(int i = 0 ; i < all.size();i++){
    finalanagrams.push_back(all[i]);
v[all[i]] = true;
}
}
return;
}
bool isanagram(long long n){
ll m = n,c =0;
while(m) m/=10,c++;
if(c < 3) return true;
int sums[10] = {0};
m = n;
int k = 0;
while(m){
k++;
    if(k  > c/2){
        if(c%2 && k == c/2+1){
                 m/=10;
                continue;
        }
        else sums[m%10]--;
    }else
    sums[m%10]++;
    m/=10;
}
for(int i = 0 ; i < 10 ;i++)
    if(sums[i]) return false;
return true;
}

int main(){
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
for (ll i = 2 ; i*i < 10000000 ; i++)
if(!v[i]){
    if(isanagram(i))anagrams.push_back(i);
    for(ll j = i*i ; j < 10000000;j+=i)
        v[j] = true;
}

ll n ;

for(int i = 0 ; i < anagrams.size();i++)
    if(!v[anagrams[i]])
check(anagrams[i]);

sort(finalanagrams.begin(),finalanagrams.end());

while(scanf("%d", &n), n){
        ll t = 0;
       m = n;
           int mx = 1;
    while (m){
       m /= 10;
       mx *= 10;
            }

    for(int i = 0 ; i < finalanagrams.size();i++){
        if(finalanagrams[i] > n&&finalanagrams[i]<mx){
            t = finalanagrams[i];
               break;
        }
    }
    cout<<t<<endl;
}

    return 0;
}
