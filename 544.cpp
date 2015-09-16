#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define f first
#define s second
#define sf second.first
#define ss second.second
using namespace std;
typedef pair<int,int> pairs;
typedef pair<int,pair<int,int> > dpair;
vector<dpair>edges;
vector<int> gs[202];
map<string,int>mp;
int parent[300];
 int n,m,dst,index = 0;
 int values[200][200];
int dfsparent[300];
bool v[300];

bool tomax(dpair x,dpair y){ return x.f > y.f;}

void start(){
    for(int i = 0 ;i < n;i++) parent[i] = i,gs[i].clear(),dfsparent[i]=i,v[i] = false;
    }

int find(int x){
		return (parent[x] == x) ? x : parent[x] = find(parent[x]);
}
bool check(int x,int y){
	return (find(x) == find(y));
}
void unione(int x,int y){
	parent[find(x)] = find(y);
}
void dfs(int x){
    v[x] = true;
    for(int i = 0 ;i < gs[x].size();i++)
    	if(!v[gs[x][i]]){
    		dfsparent[gs[x][i]] = x;
    		dfs(gs[x][i]);
    	}
}

int main(){
int cs = 1;
 while(cin >> n >> m&&n&&m){
 index = 0;
 mp.clear();
 edges.clear();
 start();
 int x,y;
dpair edge;
string s,s2;
 for(int i = 0 ;i < m;i++){
     cin >> s >> s2 >> dst;
     if(!mp.count(s)) mp[s] = index++;
     if(!mp.count(s2)) mp[s2] = index++;
     x = mp[s];
     y = mp[s2];
     edge = {dst,make_pair(x,y)};
     edges.push_back(edge);
 values[x][y] = dst;
 values[y][x] = dst;
 }
 cin >> s >> s2;
 int src = mp[s];
 int dest = mp[s2];

sort(edges.begin(),edges.end(),tomax);

 for(int i = 0; i < edges.size() ;i++){
  x = edges[i].sf;
  y = edges[i].ss;
  if(!check(x,y)){
  	unione(x,y);
  	gs[x].push_back(y);
  	 	gs[y].push_back(x);
  	 	values[x][y] = edges[i].f;
  	 	values[y][x] = edges[i].f;

}
 }
 dfsparent[src] = src;
 dfs(src);

int mn = 1<<30;
x = dest;
while(x!= dfsparent[x]){
	mn = min(mn,values[x][dfsparent[x]]);
	x = dfsparent[x];
}
cout<<"Scenario #"<<cs++<<'\n';
cout<<mn<<" tons"<<'\n'<<'\n';
}
    return 0;
}
