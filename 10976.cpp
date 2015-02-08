#include <iostream>
#include <stdio.h>
#include <vector>
#define loop(i,s,e) for(int i = s ; i < e ; i++)
#define lop(i,e) for(int i = 0 ; i < e ; i++)
#define space " "
using namespace std;
/*
 1/k = 1/x + 1/y
  we know k and we know that x is > k   
  
  So we will find y how ?!
  1/y = 1/k - 1/x :P
  gives 
  y = (x - k) / (x * k)
  So if y is int we take it 
  We will Stop at x == y
   bec it the same like
   4 ==> 1+3 -> 2+2 -> 3+1 
 */

int main(){
unsigned long long n;	
	       while(cin >> n){
       unsigned long long x = n+1;
        unsigned long long z = n,u;
vector<pair<unsigned long long , unsigned long long> > v;
pair<unsigned long long , unsigned long long>p;
      for(x;;x++){
      	double y = (double)(x*z)/(x-z);
	      	if(y == (long long)y){
	      		u = (x*z)/(x-z);
	      		p ={x,u};
	      		v.push_back(p);
      	      if(x == y) break;
      	}
       }

cout<<v.size()<<endl;
lop(i,v.size()){
      		printf("1/%d = ",n);
      		cout<<1<<"/"<<v[i].second<<" + "<<1<<"/"<<v[i].first<<endl;

}
}
return 0;
}
