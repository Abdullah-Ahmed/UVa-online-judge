#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;
bool v[50][50];
char mp[50][50];
static int dx[] = {1,-1,0,0};
static int dy[] = {0,0,1,-1};
int n,m;
char land;
bool check(int x,int y){ return (x >= 0 && y >= 0&& x < n && y < m && !v[x][y]&&mp[x][y] == land );}
int c = 0;
void dfs(int x,int y){
	v[x][y] = true;
	c++;
	int xx,yy;
	for(int i = 0 ;i < 4 ;i++){
		xx = x + dx[i];
		yy = y + dy[i] ;
		if(yy >= m) yy = 0;
		else if(yy < 0) yy = m-1;
		if(check(xx,yy))
			dfs(xx,yy);
	}

}
int main(){
	std::ios::sync_with_stdio(false);
//	freopen("in.txt","r",stdin);
	int mx,x,y;
  while(cin >> n >> m){
  	mx = 0;
  	for(int i = 0;i < n ;i++)
  		for(int j = 0;j < m ;j++)
  			 cin >> mp[i][j],v[i][j] = false;
  			cin >> x >> y;
  			land = mp[x][y];
  			dfs(x,y);
  			c = 0;

  			for(int i = 0;i < n ;i++)
  		for(int j = 0;j < m ;j++)
  			if(mp[i][j] == land && !v[i][j]){
  			    c = 0;
  				dfs(i,j);
  			mx = max(mx,c);
  		}
cout<<mx<<endl;
  }
    return 0;
}
