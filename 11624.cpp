#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#define f first
#define s second
using namespace std;
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
char mp[2000][2000];
int counter[2000][2000];
int n,m;
void firebfs(int x,int y){
counter[x][y] = 0;
queue<pair<int,int> > q;
pair<int,int>p,p2;
p = {x,y};
q.push(p);
while(!q.empty()){
	p = q.front();q.pop();
	int xx,yy;
	int cs = counter[p.f][p.s];
	for(int i = 0 ;i < 4;i++){
		xx = p.f + dx[i];
		yy = p.s + dy[i];
		if(xx >= 0 && yy >= 0 && xx < n && yy < m && cs + 1 <  counter[xx][yy] && mp[xx][yy] != '#'){
           counter[xx][yy] = cs + 1;
           p2 = {xx,yy};
           q.push(p2);
		}
	}
}
}

int jonbfs(int x,int y){
queue<pair<int,int> > q;
pair<int,int>p,p2;
p = {x,y};
q.push(p);
counter[x][y] = 0;
while(!q.empty()){
	p = q.front();q.pop();

	int cs = counter[p.f][p.s];

	for(int i = 0 ;i < 4;i++)
	if(p.f+dx[i] < 0 || p.s+dy[i] < 0 || p.f+dx[i] >= n || p.s+dy[i] >= m)
				return cs + 1 ;

	int xx,yy;
	for(int i = 0 ;i < 4;i++){
		xx = p.f + dx[i];
		yy = p.s + dy[i];
		if(xx >= 0 && yy >= 0 && xx < n && yy < m && cs+1 < counter[xx][yy] &&mp[xx][yy] != '#'){
			p2 = {xx,yy};
			counter[xx][yy] = cs + 1;
			q.push(p2);
		}
	}
}
return -1;
}



int main(){
	std::ios::sync_with_stdio(false);
// freopen("in.txt","r",stdin);
	int fx,fy,jx,jy;
int tc;
cin >> tc;
while(tc--){
	pair<int,int> fs;
	vector<pair<int,int> > ff;
 cin >> n >> m;
 for(int i = 0;i < n;i++)
 	for(int j = 0;j < m;j++) {
 		cin >> mp[i][j];
 		if(mp[i][j]== 'F'){
 		 fs = {i,j};
 		 ff.push_back(fs);
 		}
 		 if(mp[i][j]== 'J') jx = i,jy = j;
 		 counter[i][j] = 1<<30;
 	}
 	for(int i = 0 ;i < ff.size();i++)
firebfs(ff[i].f,ff[i].s); 	

int x = jonbfs(jx,jy);

if(x == -1) cout<<"IMPOSSIBLE\n";else cout<<x<<'\n';
}
    return 0;
}
