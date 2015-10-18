#include <bits/stdc++.h>
#define f first
#define s second
#define MAX 1LL<<62
using namespace std;
priority_queue< pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >q;
long long d[10000];
map<pair<int,int>,bool>mp;
pair<int,int>p,p1,p2,pr,pp;
vector<pair<int,int> >gs[10000];
vector<pair < pair<int,int>,int> > edges;
int n,m;
double mx = 0.0;
long long mxx = 0;
pair<int,int>ans;

void sortestpath(int x){
d[x] = 0;
p = {0,x};
q.push(p);
while(!q.empty()){
    pr = q.top();q.pop();
		if(pr.f == d[pr.s])		{
    for(int  i = 0;i <gs[pr.s].size();i++){
        p = gs[pr.s][i];
        if(d[p.f] > d[pr.s] + p.s){
            d[p.f] = d[pr.s] + p.s;
            p2 = {d[p.f],p.f};
            q.push(p2);
            p1 = {pr.s,p.f};
            mp[p1] = true;
            p1 = {p.f,pr.s};
            mp[p1] = true;   
        }
    }
}
}
}
int main(){
//  freopen("in.txt","r",stdin);
//  freopen("E:\\code blocks\\complete search\\Qualification Parctice\\MyJudge\\yourans.out","w",stdout);
// freopen("O.txt","w",stdout);
int cs = 1;
 while(cin >> n >> m&&n){
//if(cs > 1) printf("\n");
 mx = 0.0;
 mxx = 0;
 ans = {0,-1};
 mp.clear();
 for(int i = 0;i < n ;i++)
    d[i] = MAX,gs[i].clear();
 edges.clear();
    int x,y,z;
    for(int i = 0;i < m;i++){
        cin >> x >> y >> z;
        x--,y--;
        p = {y,z};
        gs[x].push_back(p);
        p = {x,z};
        gs[y].push_back(p);
       p = {x,y};
        edges.push_back(make_pair(p,z));
    }
    for(int i = 0;i < n;i++)d[i] = MAX;
    sortestpath(0);
mxx = 0;
for(int i = 0;i < n;i++)
  if(mxx < d[i]){
 mxx = d[i];
 ans = {i,-1};
 }

mx = (double)mxx;
for(int i = 0;i < edges.size();i++){
p = edges[i].f;
    x = edges[i].f.first;
    y = edges[i].f.second;
        z = edges[i].s;

double diff = (double)abs(d[x]-d[y]);
double path = (double)max(d[x],d[y]) + ((double)z-diff)/2.0;
if(path > mx){
mx = path;
ans = {x,y};
}
}

printf("System #%d\n", cs++);
if (ans.s == -1) {
      printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n",mx,ans.f+1);
    } else {
      printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n",mx,ans.f+1,ans.s+1);
    }
}
    return 0;
}
