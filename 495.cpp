#include <iostream>
#include <sstream>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
string bigadd(string n,string m){
   long long carry = 0 ;
   long long cell = 0 ;
   string bigernumber ;
   string smallernumber ;
    if(m.size() >= n.size())
        bigernumber = m , smallernumber = n;
    else
              bigernumber = n , smallernumber = m;

    long long totallength = bigernumber.size();


        char ss[100000];
        int j,i,z;
for( j = bigernumber.size()-1 ,i = smallernumber.size() - 1,z = 0 ;i >= 0 && j >= 0 ;j--,i--){
stringstream sss;
    ss[z] =((((bigernumber[j]-'0') + (smallernumber[i]-'0') ) +carry )%10 )+'0';
   carry = ((((bigernumber[j]-'0') + (smallernumber[i]-'0') ) +carry ) /10 );
   z++;
  }
while(j>=0)
{
    ss[z] =(((bigernumber[j]-'0')    +carry )%10 )+'0';
   carry = (((bigernumber[j]-'0')  +carry ) /10 );
   z++;
   j--;
}
if(carry)
    ss[z++] = carry+'0';

 char tmp[100000];
    for(int tt = 0,ttt = z - 1 ; tt < z ; tt++,ttt--) tmp[tt] = ss[ttt];
   tmp[z] = '\0';
return (string) tmp;
}
int main(){
		std::ios::sync_with_stdio(false);
 string f[5000+5];
 f[0] = "0",f[1] = "1";
 for(int i = 2 ;i <= 5000;i++)
 	f[i] = bigadd(f[i-1],f[i-2]);
 int n;
 while(cin >> n){
 	cout<<"The Fibonacci number for "<<n<<" is "<<f[n]<<endl;
 }
    return 0;
}
