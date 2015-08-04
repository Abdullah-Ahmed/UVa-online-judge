#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <sstream>
#define readfilefo(filename) freopen(filename,"r",stdin)
#define space " "
#define dots "--"
#define ast "**"
#define endl '\n'
using namespace std;
typedef struct{
    int f,s,t,dst;
    int lf,ls,lt;
}node;
map<string,bool>mp;
map<string,bool>::iterator it;
    int d;

    string getstring(int a, int b,int c){
        stringstream ss ;
        ss<<a << '-' << b << '-' << c;
        string st;
        st+=ss.str();
return st;
    }
    bool check(string s){
        it = mp.find(s);
           return (!(it!=mp.end()));
    }
    node ass(int aa,int bb,int cc,int dst,string ss){
                    node sss ;
                    sss.f= aa;
                    sss.s = bb;
                    sss.t = cc;
                    sss.dst = dst;
                    mp[ss] = true;
          return sss;
    }

    int f1,f11;
    int f2,f22;

int a,b,c;

void bfs2(){
queue<node>q;
node ss ;
ss.f = 0 , ss.s = 0  , ss.t = c;
ss.dst = 0;
q.push(ss);
 mp[getstring(0,0,c)] = true;
 while(!q.empty()){
  node y = q.front();q.pop();
      int as[3] = {y.f,y.s,y.t};
      int itsvalues[] = {a,b,c};
//--------------This part can be written more smart ---------------------------------
        if(y.f == d&&y.dst < f11){
            f1 = d;
            f11 = y.dst;
            continue;
        }
            if(y.s == d&&y.dst < f11){
                f1 = d;
            f11 = y.dst;
            continue;
        }
            if(y.t == d&&y.dst < f11){
                f1 = d;
            f11 = y.dst;
            continue;
        }
            if(y.f < d&& y.f >= f2){
              if(y.f == f2)
                f22 = min(f22,y.dst);
                else
            f22 = y.dst;
            f2 = y.f;
        }
            if(y.s < d&& y.s >= f2 ){
              if(y.s == f2)
                f22 = min(f22,y.dst);
                else
            f22 = y.dst;
            f2 = y.s;
        }

            if(y.t < d && y.t >= f2 ){
              if(y.t == f2)
                f22 = min(f22,y.dst);
                else
            f22 = y.dst;

            f2 = y.t;
        }

//-------------------------------------------------------------
      for(int i = 0;i  < 3;i++)
      for(int j = 0;j < 3 ;j++)
      if(i!=j&&as[i]){
        int t1 = as[i];
        int t2 = as[j];
        int values = 0;
        if(as[i]+as[j] >= itsvalues[j]){
          values+= (itsvalues[j] - as[j]);
          as[i] -= (itsvalues[j] - as[j]);
          as[j] = itsvalues[j];
        }else{
          values += as[i];
          as[j]+=as[i];
          as[i] = 0;
        }
                string ss = getstring(as[0],as[1],as[2]);
                  if(check(ss)){
                    q.push(ass(as[0],as[1],as[2],y.dst + values,ss));
                 }
 as[i] = t1;
 as[j] = t2;
      }
 }
}

int main(){
    std::ios::sync_with_stdio(false);
//  readfilefo("in.txt");
//   freopen("out.txt","w",stdout);
int  tc = 1;
 cin >> tc ;
while(tc--){
    cin >> a>> b >> c >> d;
    f1 = -1;
    f11 = 1<<30;
    f2 = 0;
    f22 = 1<<30;
    bfs2();
mp.clear();
if(f1 == -1){
  f22 = ( f22 == 1<<30 ?  0 : f22);
  cout<<f22<<' '<<f2<<endl;
}
else
cout<<f11<<' '<<f1<<endl;}

    return 0;
}
