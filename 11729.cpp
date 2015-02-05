#include <iostream>
#include<algorithm>
#include <stdio.h>
using namespace std;
int main(){
 pair<int,int>a[10000];
 int n,tc = 1;
 while(cin >> n && n){

 for(int i = 0 ; i < n  ; i++) cin >> a[i].second >> a[i].first ;
 sort(a,a+n);

 int s = 0,mx = 0;
 for(int i = n-1 ; i >= 0 ; i--){
    s+=a[i].second;
    mx = max(mx,s+a[i].first);
 }
 printf("Case %d: ",tc++);
cout<<mx<<endl;
 }
    return 0;
}
