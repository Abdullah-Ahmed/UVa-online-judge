#include <bits/stdc++.h>
#define ast "***"
#define endl '\n'
#define loop(i,s,e) for(int i = s ;i<e ; i++ )
#define lop(i,e) for(int i = 0 ;i < e ; i++)
#define inf 1e9
#define f first
#define s second
using namespace std;
pair<int,int> p,pp;
vector<pair<int,int> > gs[700];
int a[5][100];
int timer[6];
priority_queue< pair<int,int> , vector<pair<int,int> >,greater<pair<int,int> > > q;
vector<int> dst;
void dij(int s){
    dst.assign(600,inf);
    dst[s] = 0;
    p = {0,s};
    q.push(p);
    while(!q.empty()){
        pair<int,int> y = q.top();q.pop();
        int checker = y.f;
        int point = y.s;
        if(dst[point] == checker){
            for(int i = 0 ; i < gs[point].size();i++){
                pair<int,int> z = gs[point][i];
                if(dst[z.f] > dst[point] + z.s ){
                    dst[z.f] = dst[point] + z.s;
                    pp = {dst[z.f],z.f};
                    q.push(pp);
                }
            }
        }
    }
}


int main(){
		std::ios::sync_with_stdio(false);
int n,dtt;
while(cin >> n >> dtt){

lop(i,700) gs[i].clear();

for(int i = 0 ; i < n ;i++) cin>>timer[i];

for(int i = 0 ; i < n ;i++) {
	int k = 0;
	cin >> a[i][k++];
	while(cin.peek()!= '\n') cin >> a[i][k++];
	for(int j = 0;j < k;j++)
		if(gs[a[i][j]].size()){
			int tmp = a[i][j];
			a[i][j] = (a[i][j]+100*i);
		}
			for(int j = 0;j < k;j++)
				for(int u = j+1;u < k;u++)
					if(j!=u){
                            int s =  (a[i][j] >= 100 ? a[i][j] - 100*i:a[i][j]);
                           int dt =(a[i][u] >= 100 ? a[i][u] - 100*i:a[i][u]) ;
						int d = abs(s-dt)*timer[i];
						pp = {a[i][u],d};
						gs[a[i][j]].push_back(pp);
						pp = {a[i][j],d};
						gs[a[i][u]].push_back(pp);
				}

	for(int j = 0;j < k;j++){
	int tmp = a[i][j];
	for(int q = 1; q <= i ;q++){
	if( (tmp-100*q) >= 0 &&gs[tmp-100*q].size()){

        if(tmp%100)
        pp = {tmp,60};
        else
            pp = {tmp,0};

         gs[tmp-100*q].push_back(pp);

         if(tmp%100)
         pp = {tmp-100*q,60};
         else pp = {tmp-100*q,0};

         gs[tmp].push_back(pp);
			}
		}
	}
}

dij(0);
int mn = inf;
for(int i = 0 ; i < n ;i++)
mn = min(mn,dst[dtt+100*i]);

if(mn == inf)
    cout<<"IMPOSSIBLE"<<endl;
else cout<<mn<<endl;
}
  return 0;
}
