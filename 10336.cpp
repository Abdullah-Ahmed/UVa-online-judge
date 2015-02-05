#include <bits/stdc++.h>
#define loop(i,s,e) for(int i = s ; i<e ; i++)
#define lop(i,e) for(int i = 0 ; i < e ; i++)
using namespace std;
char maps[100][100];
bool v[100][100] = {false};
int n,m;
pair<int, char> cnt[30];
static int dx [] = { -1, 1, 0, 0} ;
static int dy [] = {0, 0, -1, 1} ;

bool comp(pair<int, char> a, pair<int , char>  b){
    if (a.first != b.first)
        return a.first < b.first;
    return a.second  > b.second;
}


bool check(int x , int y){return (x >= 0 &&  y >= 0 && x < n && y < m) ;}

void dfs(int x,int y,char state){
    v[x][y] = true ;
      lop(i,4){
        int xs = x + dx[i];
        int ys = y + dy[i];
        if(check(xs,ys) && !v[xs][ys] && maps[xs][ys] == state)
                    dfs(xs,ys,state);
      }
}

int main(){
    int tc, cs = 1;
    cin >> tc;
    while(tc--){
    cin>>n>>m;
lop(i,n) lop(j,m) cin >>maps[i][j];
lop(i,n) lop(j,m) v[i][j] = false;
lop(i,30) cnt[i].first = 0 , cnt[i].second = char('a' + i);

lop(i,n)
lop(j,m)
if(!v[i][j]){
    dfs(i,j,maps[i][j]);
    int index = (int) maps[i][j] - 'a';
    cnt[index].first++;
}
        printf("World #%d\n", cs++);
        sort(cnt, cnt + 30, comp);
        for(int i = 29 ; i >= 0 ; i-- ) if(cnt[i].first) cout << cnt[i].second << ": " << cnt[i].first << endl;
    }

    return 0;
}