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
#define line cout<<"******************\n";
using namespace std;
long long a[200000+10];
vector<long long>st;
void build(int p,int l,int r){
	if(l == r)
	 st[p] = a[l];
	else{
	build(L(p),l,(l+r)/2);
	build(R(p),(l+r)/2+1,r);
	st[p] = st[L(p)] +st[R(p)];
}
}
long long  findsum(int p,int l ,int r,int i,int j){
	if(i > r || j < l) return -1;
	if(l >= i && r <= j) return st[p];
long long  x = findsum(L(p),l,(l+r)/2,i,j) ;
long long y = findsum(R(p),(l+r)/2+1,r,i,j);
if(x == -1) return y;
if(y == -1) return x;
return  x + y;
}

int updatesum(int p,int l,int r,int index,int value){
	int i = index;
	int j = index;
	if(i > r || j < l) return st[p];
	if(l == i && r == j){
		st[p] += value;
		// a[l] = value;
		return st[p];
	}
	long long x = updatesum(L(p),l,(l+r)/2,index,value);
	long long y = updatesum(R(p),(l+r)/2+1,r,index,value);
	return st[p] = x + y;
}

int main(){
	// readfilefo("in.txt");
   // freopen("out.txt","w",stdout);
	std::ios::sync_with_stdio(false);
int n,tc = 1;
while(cin >> n&&n){
lop(i,n) cin >> a[i];
if(tc != 1) cout<<endl;
st.clear();
st.assign(4*n,0);
build(1,0,n-1);
int x,y;
string  c;
cout<<"Case "<<tc++<<":"<<endl;
cin >> c;
while(c!="END"){
	if(c == "END") break;
	cin >> x >> y;
    if(c == "M"){
    	x--,y--;
    	cout<<findsum(1,0,n-1,x,y)<<endl;
    }else if( c == "S"){
    	x--;

    	updatesum(1,0,n-1,x,(y-a[x]));
    	a[x] = y;
    }
    cin >> c;
}
}
	return 0;
}
