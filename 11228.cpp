#include <bits/stdc++.h>
#define space " "
#define ast "***"
#define dash "--"
#define endl '\n'
#define loop(i,s,e) for(int i = s ;i < e ; i++)
#define lop(i,e) for(int i = 0 ;i < e ; i++)
#define readfilefo(filename) freopen(filename,"r",stdin)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define x first
#define y second
#define si second.first
#define sj second.second
using namespace std;
typedef pair<int,int> pairs;
typedef pair<double,pairs> Dpair;

vector<pairs> a;
vector<Dpair> edges;
vector<int> g[1000];
   int n,r;
   int parent[1000];
bool v[1000];

double distance(int x,int y,int x2,int y2){
	return sqrt( ((x-x2)*(x-x2)) + ((y-y2)*(y-y2)) );
}

void start(){
   lop(i,n) v[i] = false,g[i].clear();
   edges.clear();
   a.clear();
  lop(i,n) parent[i] = i;
}

int  find(int i){
	return (parent[i]==i) ?   i : parent[i]= find(parent[i]) ;
}

bool check(int i,int j){
	return find(i) == find(j);
}

void unions(int i,int j){
	parent[find(i)] = find(j);
}
void dfs(int x){
	v[x] = true;
	lop(i,g[x].size())
	if(!v[g[x][i]])
		dfs(g[x][i]);
}
int main(){
		std::ios::sync_with_stdio(false);
//	readfilefo("in.txt");
//freopen("o.txt","w",stdout);
	int tc,cs = 1;
	cin >> tc;
	while(tc--){
   cin >> n >> r;

start();
int k,q;
pairs p;
   lop(i,n){
    cin >> k >>q;
    p = {k,q};
    a.push_back(p);
   }
   Dpair pp;
    lop(i,n)
    loop(j,i+1,n){
        pp = {distance(a[i].x,a[i].y,a[j].x,a[j].y),{i,j}};
     edges.push_back(pp);
    }
sort(edges.begin(),edges.end());

double d1 = 0;
lop(i,edges.size()){
	pairs t = edges[i].y;
	if(edges[i].x <= r && !check(edges[i].si,edges[i].sj)){
		d1+= edges[i].x;
		unions(edges[i].si,edges[i].sj);

		g[edges[i].si].push_back(edges[i].sj);
		g[edges[i].sj].push_back(edges[i].si);
	}

}

int c = 0;
lop(i,n)if(!v[i]){
c++;
dfs(i);}

double d2 = 0;
lop(i,edges.size()){
	pairs t = edges[i].y;
	if(!check(edges[i].si,edges[i].sj)){
		d2+= edges[i].x;
		unions(edges[i].si,edges[i].sj);
	}
}
d1+=.5,d2+=.5;
cout<<"Case #"<<cs++<<": ";
cout<<c<<space<<(int)floor(d1)<<space<<(int)floor(d2)<<endl;
}
    return 0;
}
