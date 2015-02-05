#include <iostream>
#include <bits/stdc++.h>
#define loop(i,s,e) for(int i = s ; i < e; i++)
#define lop(i,e) for(int i = 0 ; i < e; i++)
#define space " "
using namespace std;
bool h [200][200] ;
int maps[200][200];
int n,m;
int me = 0;
int mn = 200;
static int dx[] = {1,-1,0,0};
static int dy[] = {0,0,1,-1};
int total;

bool valid(int x,int y){return (x >= 0 && y >= 0 && x < n && y < m);}

void tryall(int lastindexx,int lastindexy){
	if(maps[lastindexx][lastindexy] == mn)return;
	loop(i,0,4){
		int xs = lastindexx+dx[i];
		int ys = lastindexy+dy[i];
		if(valid(xs,ys) && !h[xs][ys]&& maps[lastindexx][lastindexy] > maps[xs][ys]){
             h[xs][ys] = true;
             total++;
             me = max(me,total);
			tryall(xs,ys);
			h[xs][ys] = false;
			total--;
		}
	}

}


int main(){
	int tc ;
cin >>tc;
while(tc--){
string s;
cin  >> s >> n >> m;
lop(i,n)lop(j,m) h[i][j] = false;

lop(i,n)lop(j,m) cin>>maps[i][j],mn = min(mn,maps[i][j]) , me = min(me,maps[i][j]);

lop(i,n)lop(j,m){
total = 0;
tryall(i,j);
}
cout<<s<<": "<<me+1<<endl;
}
    return 0;
}
