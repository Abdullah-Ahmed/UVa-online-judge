#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define space " "
#define ast "***"
#define dbg(n) cout<<"Debug "<<n<<endl
#define loop(i,s,e) for(int i = s ;i < e ; i++)
#define lop(i,e) for(int i = 0 ;i < e ; i++)
#define readfilefo(filename) freopen(filename,"r",stdin)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a)  a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x)  ((x)<<1)
#define R(x)  (((x)<<1)+1)
using namespace std;
map<string,int>mp;
int index = 0;
vector<string>arr;
vector<int>gs[30000];
int bfsparent[30000];
bool v[30000];

void bfs(string st,string dt){
   int src = mp[st];
   int dst = mp[dt];
   for(int i = 0;i < 30000;i++)
   	bfsparent[i] = i,v[i] = false;

   queue<int>q;
   q.push(src);
   v[src] = true;
   bfsparent[src] = src;
   while(!q.empty()){
    int y = q.front();q.pop();
    for(int i = 0;i < gs[y].size();i++)
    	if(!v[gs[y][i]]){
    		v[gs[y][i]] = true;
    		bfsparent[gs[y][i]] = y;
    		q.push(gs[y][i]);
    	}
   }
   int x = dst;
vector<string>sss;
   while(x!=bfsparent[x]){
       sss.push_back(arr[x]);
       x = bfsparent[x];
   }
   sss.push_back(arr[x]);

if(sss.size()==1){
	puts("No solution.");
   // cout<<"No solution.\n";
    return;
}
string s;
   while(sss.size()){
   	s = sss.back();
   	puts(s.c_str());
   	// cout<<sss.back()<<'\n';
   sss.pop_back();
   }
//   cout<<'\n';
}
int main(){
	string s;
char ss[100];
   while(1){
   	gets(ss);
   	s = ss;
   	if(!s.size()) break;
   	arr.push_back(s);
   }

   for(int i = 0 ;i < arr.size();i++){
     mp[arr[i]] = index++;
   }
//   cout<<ast;

//   string s,s2;
   for(int i = 0;i < arr.size();i++){
      s = arr[i];
      for(int j = 0;j < s.size();j++){
      	for(char k = 'a';k <= 'z';k++){
      		s[j] = k;
      		if(s!=arr[i]&&mp.count(s))
      			gs[mp[arr[i]]].push_back(mp[s]);
      	}
      	s = arr[i];
      }
   }

string sb,sbb;
bool f = false;
while(cin >> sb >> sbb){
	if(f) puts("");
	f = true;
bfs(sb,sbb);
}

	return 0;
}
