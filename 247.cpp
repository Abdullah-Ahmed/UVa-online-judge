#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#define space " "
#define ast "***"
#define dbg(n) cout<<"Debug "<<n<<endl
#define loop(i,s,e) for(int i = s ;i < e ; i++)
#define lop(i,e) for(int i = 0 ;i < e ; i++)
#define readfilefo(filename) freopen(filename,"r",stdin)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(a)  a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x)  ((x)<<1)
#define R(x)  (((x)<<1)+1)
#define comma ", "
using namespace std;
int n,m;
int timer = 0;
int dfslow[100],dfsnum[100];
vector<int> a[100];
vector<int>stk;
bool visted[100];
	map<string,int>mp;
	map<string,int>::iterator it;
    string indexs[1000];


void SCC(int x){
  dfslow[x] = dfsnum[x] = timer++;
  visted[x] = true;
  stk.push_back(x);
  for(int i = 0 ; i < a[x].size();i++){
         if(dfsnum[a[x][i]] == -1)
                SCC(a[x][i]);
         if(visted[a[x][i]])
         	dfslow[x] = min(dfslow[x],dfslow[a[x][i]]);}
         if(dfslow[x] == dfsnum[x]){
while (1) {
int v = stk.back(); stk.pop_back(); visted[v] = false;
cout<<indexs[v];
if(x!=v) cout<<comma;
if (x == v) break; }
         		cout<<endl;
         }
  }


int main(){
	int tc = 1;
	std::ios::sync_with_stdio(false);
	readfilefo("in.txt");
  while(cin >> n >> m&&n&&m){

    lop(i,n) visted[i] = false , dfslow[i] = 0 , dfsnum[i] = -1,a[i].clear();
    timer = 0;
    mp.clear();

    string s,s2;
    int index = 0;
    lop(i,m){
    cin >> s >> s2;
    it = mp.find(s);
    if(it == mp.end())
    	indexs[index] = s,mp[s] = index++;//,cout<<s<<space<<index-1<<endl;

    it = mp.find(s2);
    if(it == mp.end())
    	indexs[index] = s2,mp[s2] = index++;//,cout<<s2<<space<<index-1<<endl;

int x = mp[s];
int y = mp[s2];
a[x].push_back(y);
    }
    cout<<"Calling circles for data set "<<tc++<<":"<<endl;
    lop(i,n)
    if(dfsnum[i] == -1)
         SCC(i);
 }
	return 0;
}
