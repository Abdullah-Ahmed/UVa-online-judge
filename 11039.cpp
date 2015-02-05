#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    int tt;
    cin >> tt ;
    while(tt--){
   vector<int>a;
   vector<int>b;
   int n ,z = 0 , y = 0;
   cin >> n;

   for(int i = 0,t ; i < n ;i++){
    cin >> t;
    if(t > 0) a.push_back(t),z++;
    else
        b.push_back(t*-1),y++;
   }
 
sort(a.begin(),a.end());
sort(b.begin(),b.end());

int last = 0 ;
bool f = true ;
int m = 0 , p =a.size()-1,i = b.size()-1;

if(a[p] > b[i]){
    last = a[p];p--;
    f = true;
}
else {
    last = b[i];
    i--; f = false;
}
m++;
while(true){
    if(f){
        while(b[i]> last&& i >= 0) i--;
        if(i < 0) break;
        m++;
        last = b[i];
        i--;
        f = false;
    }
    else {
        while(a[p] > last && p >= 0) p--;
        if(p < 0) break;
        m++;
        last = a[p];
        p--;
        f = true;
    }
}
cout<<m<<endl;
    }
    return 0;
}
