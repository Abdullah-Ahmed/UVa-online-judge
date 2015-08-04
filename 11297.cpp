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
#define f first
#define s second
using namespace std;
int n,m,q;
vector<int>st[6000];
vector<int>st2[6000];
// int a[1000];
vector<int>a[600];
void build(int p, int l, int r,int index) {                           // O(n log n)
    if (l == r)                            // as L == R, either one is fine
      st[index][p] = l;                                         // store the index
    else {                                // recursively compute the values
      build(L(p) , l , (l + r) / 2,index);
      build(R(p), (l + r) / 2 + 1, r,index);
      int p1 = st[index][L(p)], p2 = st[index][R(p)];
      st[index][p] = (a[index][p1] <= a[index][p2]) ? p1 : p2;
  } }

void builds(int p,int l,int r,int index){
     if(l == r)
     	st[index][p] = l,st2[index][p] = l;
     else{
     	builds(L(p),l,(l+r)/2,index);
     	builds(R(p),(l+r)/2+1,r,index);
     	int p1 = st[index][L(p)];
     	int p2 = st[index][R(p)];
     	st[index][p] = (a[index][p1] <= a[index][p2]) ? p1 : p2;

     	p1 = st2[index][L(p)];
     	p2 = st2[index][R(p)];
     	st2[index][p] = (a[index][p1] > a[index][p2]) ? p1 : p2;
     }
}
int findmin(int p,int l,int r,int i, int j,int index){
       if(i > r || j < l) return -1;
       if(l >= i && r <= j) return st[index][p];
       int p1 = findmin(L(p),l,(l+r)/2,i,j,index);
       int p2 = findmin(R(p),(l+r)/2+1,r,i,j,index);
       if(p1 == -1) return p2;
       if(p2 == -1) return p1;
       return  (a[index][p1] <= a[index][p2]) ? p1 : p2;
}
int findmax(int p,int l ,int r,int i ,int j,int index){
	if(i > r || j < l) return -1;
	if(l >= i && r <= j) return st2[index][p];
	int p1 = findmax(L(p),l,(l+r)/2,i,j,index);
	int p2 = findmax(R(p),(l+r)/2+1,r,i,j,index);
	if(p1 == -1) return p2;
	if(p2 == -1) return p1;
	return (a[index][p1] >= a[index][p2]) ? p1 : p2;
}

  int update_point(int p, int l, int r, int idx, int new_value,int index) {
    int i = idx, j = idx;

    if (i > r || j < l)
      return st[index][p];

    if (l == i && r == j) {
      a[index][i] = new_value; // update the underlying array
      return st[index][p] = l; // this index
    }

    int p1, p2;
    p1 = update_point(L(p) , l              , (l + r) / 2, idx, new_value,index);
    p2 = update_point(R(p), (l + r) / 2 + 1, r          , idx, new_value,index);

    return st[index][p] = (a[index][p1] <= a[index][p2]) ? p1 : p2;
}


int update_point2(int p, int l, int r, int idx, int new_value,int index) {
    int i = idx, j = idx;

    if (i > r || j < l)
      return st2[index][p];

    if (l == i && r == j) {
      return st2[index][p] = l; // this index
    }

    int p1, p2;
    p1 = update_point2(L(p) , l              , (l + r) / 2, idx, new_value,index);
    p2 = update_point2(R(p), (l + r) / 2 + 1, r          , idx, new_value,index);

    return st2[index][p] = (a[index][p1] >= a[index][p2]) ? p1 : p2;
}


int main(){
	std::ios::sync_with_stdio(false);
while(cin >> n >> m){
	int z;
	lop(i,n) a[i].clear(),st[i].clear(),st2[i].clear();
lop(i,n){
lop(j,m){
 cin >> z ,a[i].push_back(z);
}
st[i].assign(4*a[i].size(), 0);
st2[i].assign(4*a[i].size(), 0);
builds(1,0,m-1,i);
}

//st2.assign(4*a.size(),0);
cin >> q;
int x3,y3,x4,y4;
int x,y,x2,y2,v;
int i,j;
char c;
lop(k,q){
	cin >> c ;
	if(c == 'q'){
	cin >> x3 >> y3 >> x4 >> y4;
 	x3--,y3--,x4--,y4--;
x = min(x3,x4);
x2 = max(x3,x4);
y = min(y3,y4);
y2 = max(y3,y4);
// cout<<x<<space<<y<<space<<x2<<space<<y2<<endl;
int mn = 1<<30,mx = 0;
loop(z,x,x2+1){
int index =  findmin(1,0,m-1,y,y2,z);
int index2 =  findmax(1,0,m-1,y,y2,z);
	mn = min(a[z][index],mn);
	mx = max(a[z][index2],mx);
//  cout<<ast<<z<<space<<index<<space<<a[z][index]<<endl;
}
cout<<mx<<space<<mn<<endl;
}else{
	cin >> x >> y >> v;
	x--,y--;
update_point(1,0,m-1,y,v,x);
update_point2(1,0,m-1,y,v,x);
}

}
}
	return 0;
}
