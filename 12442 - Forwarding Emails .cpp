#include <bits/stdc++.h>
using namespace std;
int timer = 0;
int dfsnum[60000],dfslow[60000];
vector<int>stk;
bool vs[60000];
bool taken[60000];
map<int,int>mp;

vector<int> gs[60000];
vector<int> ps[60000];
vector<int> reversed[60000];
int outdegree[60000];
int level[60000];
int n,m;

void dfs(int x){
	dfslow[x] = dfsnum[x] = timer++;
	vs[x] = true;
	stk.push_back(x);
	for(int i = 0;i < gs[x].size();i++){
		if(dfsnum[gs[x][i]] == -1)
			dfs(gs[x][i]);
		if(vs[gs[x][i]])
			dfslow[x] = min(dfslow[x],dfslow[gs[x][i]]);
	}
	if(dfsnum[x] == dfslow[x]){
		vector<int>SCC;
		int vx,mn = 1<<30;
		while(true){
		vx = stk.back(); stk.pop_back();
		vs[vx] = false;
		SCC.push_back(vx);
		mn = min(mn,vx);
	if(vx == x) break;
	}
	level[mn] = SCC.size()-1;
	while(SCC.size()){
	 mp[SCC.back()] = mn;
	 SCC.pop_back();
	}

	}
}


int main(){
		std::ios::sync_with_stdio(false);
//	freopen("in.txt","r",stdin);
int tc,cs = 1;
cin >> tc;
while(tc--){
	cin >> n;
	int x,y;
	
	mp.clear();
	for(int i = 1;i <= n;i++){
		dfsnum[i] = -1;
		dfslow[i] = vs[i] = taken[i] = false;
		level[i] = 0;
		gs[i].clear();
		reversed[i].clear();
		ps[i].clear();
		outdegree[i] = 0;
	}


	for(int i = 0;i < n ;i++){
		cin >> x >> y;
		gs[x].push_back(y);
	}


	for(int i = 1;i <= n;i++)
		if(dfsnum[i] == -1)
				dfs(i);

	priority_queue<pair<int,int> , vector<pair<int,int> >,greater<pair<int,int> > >qq;
	queue<int>q;
	pair<int,int>p;		
	for(int i = 1;i <= n;i++){
		x = mp[i];
		for(int j = 0;j < gs[i].size();j++){
			y = mp[gs[i][j]];
			if(x!=y){
			ps[x].push_back(y);
			reversed[y].push_back(x);
		}
	}

			outdegree[x] = ps[x].size();
			p = {ps[x].size(),x};
			if(!ps[x].size())
				q.push(x);

	}

while(!q.empty()){
	y = q.front();q.pop();
	taken[y] = true;
for(int i = 0;i < reversed[y].size();i++){
	outdegree[reversed[y][i]]--;
	if(!outdegree[reversed[y][i]]&&!taken[reversed[y][i]]){
		level[reversed[y][i]] = level[y] + 1;
		q.push(reversed[y][i]);
	}
}
}
int mx = 0,final = 1;
for(int i = 1;i <= n;i++){
	if(mx < level[i]){
		final = i;
		mx = level[i]; 
	}
}
cout<<"Case "<<cs++<<": "<<final<<endl;
}

	return 0;
}
