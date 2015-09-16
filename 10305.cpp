#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int>sorted;
vector<int> gs[105];
bool v[200];
void dfs(int x){
v[x] = true;
for(int i = 0;i < gs[x].size();i++)
    if(!v[gs[x][i]])
        dfs(gs[x][i]);
sorted.push_back(x);
}
int main(){
	std::ios::sync_with_stdio(false);
 while(cin >> n >> m &&(n||m)){
 int x,y;
 sorted.clear();
 for(int i = 1;i <= n;i++)
    v[i] = false,gs[i].clear();
 for(int i = 0;i < m ;i++){
    cin >> x >> y;
    gs[x].push_back(y);
 }
 for(int i = 1;i <= n;i++)
    if(!v[i])
        dfs(i);
 while(sorted.size()) cout<<sorted.back()<<' ',sorted.pop_back();
 cout<<endl;
 }
    return 0;
}
//****************************************************************************
//Using Kahn
#include <iostream>
#include <vector>
#include <queue>
#define f first
#define s second
using namespace std;
int n,m;
vector<int>sorted;
vector<int> gs[105];
bool v[200];
void dfs(int x){
v[x] = true;
for(int i = 0;i < gs[x].size();i++)
    if(!v[gs[x][i]])
        dfs(gs[x][i]);
sorted.push_back(x);
}
pair<int,int>p;
priority_queue<pair<int,int> >q;
int main(){
	std::ios::sync_with_stdio(false);
 while(cin >> n >> m &&(n||m)){
 int x,y;
 sorted.clear();
 for(int i = 1;i <= n;i++)
    v[i] = false,gs[i].clear();
 for(int i = 0;i < m ;i++){
    cin >> x >> y;
    gs[x].push_back(y);
 }
for(int i = 1;i <= n;i++){
    p = {gs[i].size(),i};
    q.push(p);
 }
while(!q.empty()){
    p = q.top();q.pop();
    if(v[p.s]) continue;
    dfs(p.s);
}
 while(sorted.size()) cout<<sorted.back()<<' ',sorted.pop_back();
 cout<<endl;
 }
    return 0;
}
