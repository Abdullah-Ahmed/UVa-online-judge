#include  <iostream>
#include <stdio.h>
using namespace std;
bool check(int x){
bool h[10] = {false};
int c = 0;
while(x){
        c++;
    if(h[x%10]||c > 5) return false;
    h[x%10] = true;
    x/=10;
}
return true;
}
int sizee(int x){
int c = 0;
while(x)x/=10,c++;
return c;
}
bool containzero(int x){
while(x){
    if(!(x%10)) return true;
    x/=10;
}
return false;
}
int main(){
int n;
bool ff = false,fs = false;
int cs = 0;
while(cin >> n&&n){
        ff = false;
		if (fs) printf("\n");
		fs = true;
for(int i  = 1234; i<= 98765;i++)
    if(check(i)&&check(i*n)){
        bool h[10] = {false},f = true;
        int j = i,z = i*n,c = 0,cc = 0;
        while(j) h[j%10] = true,j/=10,c++;
        while(z) {
            if(h[z%10]){
                f = false;
                break;
            }
                z/=10;
        }
        if(f){
int x = sizee(i);
int y = sizee(i*n);
bool xx = containzero(i*n);
bool yy = containzero(i);
if((x == y&&x == 5)||(y == 5&&x == 4 &&!xx&&!yy)||(x == 5&&y == 4&&!yy&&!xx))
        printf("%05d / %05d = %d\n",i*n,i,n),ff = true;
        }
    }
if(!ff) printf("There are no solutions for %d.\n",n);
}
return 0;
}











//Using 5 loops




#include <iostream>
using namespace std;
int z, n;
bool h[10];
int counts(int x){
int c = 0;
while(x)c++,x/=10;
return c;
}

bool check(int z){
  //  cout<<z<<endl;
    int c = 0,zz = z;
bool hh[10] = {false};
int k;
c = counts(z);
while(z){
k = z%10;
    if(h[k]||hh[k]){
     return false;}
hh[k] = true;
z/=10;
}
return true;
}


int main(){
    bool f = false,fs = false;
    int ccc = 0;
while (cin >> n&&n){
  f = false;

  if(fs)
   cout<<'\n';
   fs = true;
    int zz;
  for(int i = 0;i < 10;i++)
    for(int j = 0;j < 10;j++)
        if(j!=i)
  for(int k = 0;k < 10;k++)
    if(k!=i&&k!=j)
    for(int x = 0;x < 10;x++)
    if(x!=k&&x!=i&&x!=j)
    for(int y = 0;y < 10;y++)
  if(y!= x&&y!=k&&y!=i&&y!=j){
        z = i*10000+j*1000+k*100+x*10+y;
    h[i] = h[j] = h[k] = h[x] = h[y] = true;
  zz = counts(z*n);
if(counts(z) ==4 &&zz == 4) continue;
    if( zz <= 5&&zz>=4&&check(z*n)){
if(zz == 4) cout<<0<<z*n;
else cout<<z*n;

cout<<" / ";
if(counts(z) == 4)cout<<0<<z;
else
cout<<z;
cout<<" = "<<n<<'\n';
f = true;
    }
           h[i] = h[j] = h[k] = h[x] = h[y] = false;
  }
  if(!f)
    cout<<"There are no solutions for "<<n<<".\n";
}
    return 0;
}

