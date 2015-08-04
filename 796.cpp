#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
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
#define f first
#define s second
using namespace std;
typedef pair<int,int> ii ;
ii links[10000];
int timer = 0;
vector<int> a[10000];
int index = 0;
int dfslow[10000] = {0},dfsnum[10000],dfsparent[10000];

void bridges(int u){
	dfslow[u] = dfsnum[u] = timer++;
	for(int i = 0 ;i < a[u].size() ; i++){
		if(dfsnum[a[u][i]] == -1){
			dfsparent[a[u][i]] = u;
			bridges(a[u][i]);
			if(dfslow[a[u][i]] > dfsnum[u])
				links[index].f = min(u,a[u][i]),links[index].s = max(u,a[u][i]),index++;
			dfslow[u] = min(dfslow[u],dfslow[a[u][i]]);
		}else if(a[u][i] != dfsparent[u])
		dfslow[u] = min(dfslow[u],dfsnum[a[u][i]]);
	}
}
int main(){
	std::ios::sync_with_stdio(false);
//readfilefo("in.txt");
int n;
while(cin >> n){
timer = index = 0;
lop(i,n) dfsnum[i] = -1,dfslow[i] = 0,dfsparent[i] = 0,a[i].clear();
int x,y,z;
lop(i,n){
	cin >> x;
	char c;
	cin >>c>>y>>c;
	lop(j,y) cin >>z,a[x].push_back(z);
}
lop(i,n)
if(dfsnum[i] == -1)
       bridges(i);
   cout<<index <<" critical links"<<endl;
   sort(links,links+index);
   lop(i,index)
        cout<<links[i].f<<" - "<<links[i].s<<endl;
        cout<<endl;
    }
	return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;


bool M[100][100];
int N,colour[100],dfsNum[100],num,pos[100],leastAncestor[100],parent[100];
//classical function
int  Articulation(int u){
int v;
stack<int> S;
S.push(u);
while(!S.empty()){
v=S.top();
if(colour[v]==0){
colour[v]=1;
dfsNum[v]=num++;
leastAncestor[v]=num;
}
for(;pos[v]<N;pos[v]++){
if(M[v][pos[v]] && pos[v]!=parent[v]){
if(colour[pos[v]]==0){
parent[pos[v]]=v;
S.push(pos[v]);
break;
}else leastAncestor[v]= min (leastAncestor[v],dfsNum[pos[v]]);
}
}
if(pos[v]==N){
colour[v]=2;
S.pop();
if(v!=u) leastAncestor[parent[v]]=min(leastAncestor[parent[v]],leastAncestor[v]);
}
}

           // return cnt ;
}

pair<int ,int> v[100] ;

int idx = 0 ;
void Bridge_detection(){
memset(colour,0,sizeof(colour));
memset(pos,0,sizeof(pos));
memset(parent,-1,sizeof(parent));
num=0;
int ans=0;

for(int i=0;i<N;i++) if(colour[i]==0) Articulation(i);

for(int i=0;i<N;i++)
for(int j=0;j<N;j++)
if(parent[j]==i && leastAncestor[j]>dfsNum[i]) ans++;
printf("%d critical links\n",ans);

for(int i=0;i<N;i++)
for(int j=0;j<N;j++)
if(parent[j]==i && leastAncestor[j]>dfsNum[i])   v[idx].first = min(i,j) , v[idx].second = max(i,j) , idx++ ;
sort(v,v+idx);
for(int i=idx;i>=0;i--) printf("%d - %d\n",v[i].first,v[i].second);
printf("\n");
}


int main()
{
 int u,v,e;
char c;
while(scanf("%d\n",&N)==1){
memset(M,false,sizeof(M));
for(int i=0;i<N;i++){
scanf("%d",&u);
scanf("%c%c%d%c",&c,&c,&e,&c);
for(int j=0;j<e;j++){
scanf(" %d",&v);
M[u][v]=M[v][u]=true;
}
}
if(N)
Bridge_detection();
else printf("0 critical links\n");
}

    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
#define SZ 100
bool M[SZ][SZ];
int N,colour[SZ],dfsNum[SZ],num,pos[SZ],leastAncestor[SZ],parent[SZ];
void dfs(int u){
int v;
stack<int> S;
S.push(u);
while(!S.empty()){
v=S.top();
if(colour[v]==0){
colour[v]=1;
dfsNum[v]=num++;
leastAncestor[v]=num;
}
for(;pos[v]<N;pos[v]++){
if(M[v][pos[v]] && pos[v]!=parent[v]){
if(colour[pos[v]]==0){
parent[pos[v]]=v;
S.push(pos[v]);
break;
}else leastAncestor[v]= min (leastAncestor[v],dfsNum[pos[v]]);
}
}
if(pos[v]==N){
colour[v]=2;
S.pop();
if(v!=u)  leastAncestor[parent[v]]=min(leastAncestor[parent[v]],leastAncestor[v]);;
}
}
}
struct edge{
int u,v;
edge(){
}
edge(const int _u, const int _v){
u=min(_u,_v);
v=max(_u,_v);
}
bool operator < (const edge &X) const{
if(u!=X.u) return u<X.u;
return v<X.v;
}
};
vector<edge> v;
void Bridge_detection(){
memset(colour,0,sizeof(colour));
memset(pos,0,sizeof(pos));
memset(parent,-1,sizeof(parent));
num=0;
int ans=0;
for(int i=0;i<N;i++) if(colour[i]==0) dfs(i);
for(int i=0;i<N;i++)
for(int j=0;j<N;j++)
if(parent[j]==i && leastAncestor[j]>dfsNum[i]) ans++;
printf("%d critical links\n",ans);
v.clear();
for(int i=0;i<N;i++)
for(int j=0;j<N;j++)
if(parent[j]==i && leastAncestor[j]>dfsNum[i]) v.push_back(edge(i,j));
sort(v.rbegin(),v.rend());
for(int i=v.size()-1;i>=0;i--) printf("%d - %d\n",v[i].u,v[i].v);
printf("\n");
}
int main(){
int u,v,e;
char c;
while(scanf("%d\n",&N)==1){
memset(M,false,sizeof(M));
for(int i=0;i<N;i++){
scanf("%d",&u);
scanf("%c%c%d%c",&c,&c,&e,&c);
for(int j=0;j<e;j++){
scanf(" %d",&v);
M[u][v]=M[v][u]=true;
}
}
Bridge_detection();
}
return 0;
}*/
