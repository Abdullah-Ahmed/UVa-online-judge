#include <stdio.h>
#include <iostream>
#include <vector>
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
using namespace std;
int dfslow[10000],dfsnum[10000],dfsparent[10000];
int n,m,timer = 0;
vector<int> a[10000];
bool mp[10000][10000];
void bridges(int x){
	dfslow[x] = dfsnum[x] = timer++;
	for(int i = 0 ; i < a[x].size();i++){
		if(dfsnum[a[x][i]] == -1){
			dfsparent[a[x][i]] = x;

			mp[x][a[x][i]] = true;

			bridges(a[x][i]);

			if(dfslow[a[x][i]] > dfsnum[x])

				mp[a[x][i]][x] = true;

			dfslow[x] = min(dfslow[x],dfslow[a[x][i]]);

		}else if(dfsparent[x] != a[x][i]){
			if(dfsnum[x] > dfsnum[a[x][i]])
			     mp[x][a[x][i]] = true;

		dfslow[x] = min(dfslow[x],dfsnum[a[x][i]]);
	}
	}
}

int main(){
	int tc = 1;
//	readfilefo("in.txt");
//freopen("o.txt","w",stdout);
	std::ios::sync_with_stdio(false);
while(cin >> n >> m &&n&&m){
timer = 0; 
lop(i,n)a[i].clear(),dfslow[i] = dfsparent[i] = 0 ,dfsnum[i] = -1;
lop(i,n)lop(j,n) mp[i][j] = false;
int x,y;
lop(i,m) cin >> x >> y,x--,y--,a[x].push_back(y),a[y].push_back(x);

lop(i,n)
if(dfsnum[i] == -1)
	bridges(i);
cout<<tc++<<endl<<endl;
lop(i,n)
lop(j,n)
if(mp[i][j])
cout<<i+1<<space<<j+1<<endl;
cout<<"#"<<endl;
}
	return 0;
}
