#include <iostream>
#define endl '\n'
using namespace std;
char mp[100][100];
bool v[100][100];
int n;
bool f = false;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
bool check(int x,int y){
	return (x >= 0 && y >= 0 && x < n && y < n && mp[x][y] != '.'&& !v[x][y]);
}
void dfs(int x,int y){
 v[x][y] = true;
 int xx,yy;
 if(mp[x][y] == 'x') f = true;

 for(int i = 0 ; i < 4;i++){
 	xx = x + dx[i];
 	yy = y + dy[i];
 	if(check(xx,yy))
 		dfs(xx,yy);
 }
}
int main(){
std::ios::sync_with_stdio(false);
//	freopen("in.txt","r",stdin);
	int tc,cs = 1,c = 0;
	cin >> tc;
	while(tc--){
		cin >> n;
		c = 0;
		for(int i = 0 ;i < n ; i++)
			for(int  j = 0;j < n ;j++) cin >> mp[i][j] , v[i][j] = false;

            for(int i = 0 ; i < n;i++)
            	for(int j = 0;j < n ;j++)
            		if(!v[i][j] && mp[i][j]!='.'){
            			f = false;
            			dfs(i,j);
            			c+=f;
            		}
            		cout<<"Case "<<cs++<<": "<< c << endl;
	}

    return 0;
}
