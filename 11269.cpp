#include <iostream>
#include <algorithm>
#include <stdio.h>
#define f first
#define s second
#define loop(i,s,e) for(int i = s; i < e ;i++)
#define lop(i,e) for(int i = 0; i < e ;i++)
#define space " "
#define ast "****"
using namespace std;

bool comp(pair<int,int>a,pair<int,int>b){
     int timer1 = a.f+b.f+b.s;
     int timer2 = b.f+a.f+a.s;
     if(a.s > b.f) timer1+=(a.s - b.f);
     if(b.s > a.f) timer2+=(b.s - a.f);
      return (timer1 < timer2);
}


int main(){
pair<int,int> as[100];
int n;
while(cin>>n){
int c = 0 ,cc = 0;
int mnup = 1<<30,mndwn = 1<<30;
lop(i,n) cin >>as[i].f;
lop(i,n) cin >>as[i].s;

sort(as,as+n,comp);

 int timer1 = 0 , timer2 = as[0].f;
for(int i = 0; i < n; i++) {
timer1 += as[i].f;
if(timer1 > timer2) timer2 += (timer1 - timer2);
timer2 += as[i].s;}

cout<<timer2<<endl;

}
    return 0;
}
