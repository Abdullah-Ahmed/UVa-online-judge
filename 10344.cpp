#include <iostream>
#include <algorithm>
#define loop(i,s,e) for(int i=s;i<=e;i++)
#define space " "
using namespace std;

long long calculate(int a,int op,int b)
{
if(op==1) return a+b;
if(op==2) return a-b;
if(op==3) return a*b;
}

int solve(int q,int w,int e,int r,int t)
{
    bool f;
	long long tmp;
	loop(a,1,3)
	loop(b,1,3)
	loop(c,1,3)
	loop(d,1,3){
    tmp=calculate(calculate(calculate(calculate(q,a,w),b,e),c,r),d,t); 
    if(tmp==23){
    f=true;
    return tmp;
     } 
  }
    return 0;
}

int main()
{
	int q,w,e,r,t;
	int a[10];
	int tmp;
	bool f=false,p=false;
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
	while(a[0]||a[1]||a[2]||a[3]||a[4]){
	sort (a,a+5);
	do
	{
        if(solve(a[0],a[1],a[2],a[3],a[4])==23){p=true;break;}
	}
	
	while ( next_permutation(a,a+5) ); 
	if(p) cout<<"Possible\n";
    else
    	cout<<"Impossible\n";
    	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
        p=false;
    }

    return 0;
}
