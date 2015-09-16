#include <iostream>
#include <queue>
#include <map>
#include <sstream>
#include <algorithm>
#include <stdio.h>
using namespace std;
bool v[400000];
int cs[400000];
string css[400000];
map<int,int>mp;
map<int,int>::iterator it;
	int a[4][4];
	int finalstate;
int getstate(){
	int c = 0;
	for(int i = 1;i<= 3;i++){
		for(int j = 1;j <= 3 ;j++)
			c*=10,c+=a[i][j];
	}
		return c;
}

int bfs(){
    queue<int>q;
    int index = 0;
    mp[123456789] = index;

	q.push(123456789);
	cs[index] = 0;
		css[index] = "";
	index++ ;
	while(!q.empty()){
	int	y ,idx;
	y = q.front();q.pop();
	idx= mp[y];
	int z;
  for(int i = 3;i >= 1;i--)
  	for(int j = 3;j >= 1;j--)
  		a[i][j] = y%10,y/=10;
  
    for(int i = 1 ;i <= 3;i++){
    	int x = i == 1 ? 3 : i-1;
     swap(a[i][1],a[i][2]);
     swap(a[i][2],a[i][3]);

    z =  getstate();
    it = mp.find(z);
    if(it == mp.end()){
    	mp[z] = index;
         cs[index] = cs[idx] + 1;

            stringstream ss;
            ss << css[idx] << i << "H" ;
         css[index]=ss.str();

         index++;
         q.push(z);
    }


     swap(a[i][2],a[i][3]);
     swap(a[i][1],a[i][2]);

 swap(a[2][i],a[3][i]);
 swap(a[2][i],a[1][i]);
  z = getstate();
    it = mp.find(z);
    if(it == mp.end()){
    	mp[z] = index;
         cs[index] = cs[idx] + 1;
            stringstream ss;
              ss << css[idx] << i << 'V';
         css[index]=ss.str();
         index++;
         q.push(z);
    }

 swap(a[2][i],a[1][i]);
 swap(a[2][i],a[3][i]);
    }
	}
return -1;
}
int main(){
    std::ios::sync_with_stdio(false);
//  freopen("in.txt","r",stdin);
//  freopen("E:\\code blocks\\complete search\\Qualification Parctice\\MyJudge\\yourans.out","w",stdout);
    bfs();

while(1){
for(int  i = 1;i <= 3;i++)
	for(int j = 1;j <= 3;j++){
		cin >> a[i][j];
		if(!a[i][j]) return 0;
	}

  	finalstate = getstate();

if (finalstate == 123456789) {printf("0\n"); continue;}
         
        if (mp.count(finalstate)) {
    int x = mp[finalstate];          
            string s = css[x];
    reverse(s.begin(),s.end());
    printf("%d %s",cs[x],s.c_str());
        }
        else printf("Not solvable");
        printf("\n");
    
 }
    return 0;
}