#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
vector<int>gs[300];
bool v[300];
int color[300];
int x,y;
 int n,m,tc = 1;
int cs = 0,css = 0;
bool dfs(int x,bool c){
	color[x] = c;
	v[x] = true;
	bool y = true;
cs+= (color[x]);
css+= (!color[x]);
	for(int i = 0 ; i < gs[x].size();i++){
	if(v[gs[x][i]] && color[gs[x][i]] == c)
		return false;
		if(!v[gs[x][i]])
	    y &= dfs(gs[x][i],!c);
	}
	return y;
}

int main(){
// freopen("in.txt","r",stdin);
 cin >> tc;
 while(tc--){
 	cin >> n >> m;
 	for(int  i = 0 ;i < n ;i++)
 		gs[i].clear(),color[i] = false,v[i] = false;

for(int i = 0;i <  m;i++){
	cin >> x >> y;
	gs[x].push_back(y);
	gs[y].push_back(x);
}
int c = 0;
for(int i = 0 ; i < n ;i++)
 if(!v[i]){
 color[i] = 1;
 cs = css = 0;
 if(!dfs(i,1)){
  c = -1;
  break;
	}
	if(css) c+= min(cs,css);
	else c+=cs;
 }

cout<<c<<endl;
 cs = 0,css = 0;
 }

    return 0;
}
