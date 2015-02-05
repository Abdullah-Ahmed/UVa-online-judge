#include <bits/stdc++.h>
#define loop(i,s,e) for(int i=s;i<e;i++)
#define space "  "
#define astrics "***"
using namespace std;

typedef pair<float ,float> pairz ;
typedef pair<float , pairz> doublepair;

vector<pairz> a;
vector<doublepair> edges;
vector<int>parent;

void init( int n )
{
    parent.assign(n,0);
    loop(i,0,n) parent[i]=i;
}

int  find(int i)
{
	return (parent[i]==i) ?   i : parent[i]= find(parent[i]) ;
}

bool check(int i,int j)
{
	return ( find(i) == find(j) ) ;
}

void unione(int i, int j)
{
	parent[find(i)] = find(j) ;
}

float finddist (float x,float y,float a,float b)
{
	return sqrt( ( abs(x-a)*abs(x-a) ) + ( abs(y-b) * abs(y-b) ) );
}

int main()
{

int tc;
cin>>tc;
while(tc--){
	int n;

	cin >> n;
        edges.clear();
        a.clear();

float x ,y;

float mine = 1e9 , minidx = 0;

	loop( i , 0 , n)
	{
		cin >> x >> y ;

      float d= finddist(x , y , 0 ,0 );
 (d < mine ) ? mine = d,minidx = i : mine ;

		a.push_back(pairz(x, y));

	}


loop ( i , 0 , n )
loop ( j , i+1 , n )
 {
 	pairz tz = a[i];
 	 pairz tz1 = a[j];
 	 float dz = finddist ( tz.first , tz.second , tz1.first ,tz1.second) ;


     edges.push_back ( doublepair ( dz , make_pair (i , j) ) ) ;
 }

sort(edges.begin(), edges.end());


init(n) ;


float dist=0.0;

loop(i , 0 , edges.size())
{
	pairz tz = edges[i].second;   	

	if(!check(tz.first,tz.second))
	{

		unione(tz.first,tz.second) ;

       dist+=edges[i].first;

	}

}
printf("%.2f\n",dist);
if(tc > 0) printf("\n");
}
    return 0;
}








