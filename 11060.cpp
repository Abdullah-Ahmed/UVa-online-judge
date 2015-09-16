#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stdio.h>
#define f first
#define s second
using namespace std;
map<string,int> mps;
map<int,string> mp;
int n,m,index = 1;
int x,y;
vector<int>gs[105];
vector<int>nodes;
int in[200];
int main(){
		std::ios::sync_with_stdio(false);
//		freopen("in.txt","r",stdin);
	int tc = 1;
while(cin >> n){
string s,s2;
mp.clear();
mps.clear();
nodes.clear();
index = 1;
for(int i=1;i<=n;i++) gs[i].clear(),in[i] = 0;

for(int i = 0;i < n ;i++){
	cin >> s;
	mp[index] = s;
	mps[s] = index++;
}
cin >> m ;
for(int i = 0;i < m ;i++){
	cin >> s >> s2;
	x = mps[s];
	y = mps[s2];
	gs[x].push_back(y);
	in[y]++;
}
priority_queue<int,vector<int>,greater<int> >qq;
pair<int,int> p;
queue<int>q;

for(int i = 1;i <= n ;i++)
if(!in[i]){
	qq.push(i);
}
while(!qq.empty()){
	x = qq.top();qq.pop();
nodes.push_back(x);
	for(int i = 0;i < gs[x].size();i++){
		in[gs[x][i]]--;
		if(!in[gs[x][i]])
			qq.push(gs[x][i]);
	}

}

        cout << "Case #" << tc++ << ": Dilbert should drink beverages in this order:";

for(int i = 0;i < nodes.size();i++)cout<<' '<<mp[nodes[i]];
cout<<'.'<<'\n'<<'\n';
}
    return 0;
}
