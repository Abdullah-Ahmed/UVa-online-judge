#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
map<string,int> hashy;
int cnt = 0;
bool takens[26] = {false};

void allstring(string s,int last){
   if(s.size() == last){
    hashy[s] = cnt++;
  //  cout<<s<<endl;
   return;
   }
int index;
if(s == "") index = 0;
else index = s[s.size()-1] -'a'+1;
   for(int i = index ; i < 26;i++){
       takens[i] = true;
        char x = 'a';
        x+=i;
        allstring(s+x,last);
   }
}

int main(){
    for(int i = 0 ; i< 6 ; i++){
             allstring("",i);
    }
 string s;
 while(cin>>s) cout<<hashy[s]<<endl;
    return 0;
}
