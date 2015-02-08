#include <iostream>
#include <cmath>
#include <stdio.h>
#define loop(i,s,e) for(int i = s ;i < e ;i++)
#define lop(i,e) for(int i = 0;i < e ;i++)
#define space " "
using namespace std;
int pags[100]; // to keep the last ball
int n; //no of pags
int tryit(int x){
	double sqr;
lop(i,n){
	sqr = sqrt(x+pags[i]);
	if(sqr == (int)sqr || !pags[i]){  // if it a square or it empty
               pags[i] = x;
             return  tryit(x+1);
}
    }

    return x-1;

}

//recursive Solution 
int main(){
	//freopen("in.txt","r",stdin);
int tc;
cin >> tc;
while(tc--){
       cin >> n;
       lop(i,n) pags[i] = 0;
       cout<<tryit(1)<<endl;
   }
        return 0;
}

//***********************************************************************************************************************************
// iterative 
int main(){
// freopen("in.txt","r",stdin);
int tc;
cin >> tc;
while(tc--){
       cin >> n;
       lop(i,n) pags[i] = 0;
       int x = 1;
       for(x = 1; x < 100000;x++){
       	bool f = true;
	double sqr;
lop(i,n){
	sqr = sqrt(x+pags[i]);

	if(sqr == (int)sqr || !pags[i]){  
               pags[i] = x;
               f = false;
               break;
}
    }

    if(f) break;
       }
              cout<<x-1<<endl;
          }

    return 0;
}
