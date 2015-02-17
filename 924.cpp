#include <iostream>
#include <bits/stdc++.h>
#define loop(i,s,e) for(int i = s ; i < e ; i++)
#define lop(i,e) for(int i = 0 ; i < e ; i++)
#define space " "
using namespace std;
bool v[3000];
bool a[3000][3000];
int es,m,x;
void counts(int start){
	v[start] = true;
	queue<int>q;
	q.push(start);
	int days = 0 , mx = 0 , f = 0;
   int noofchilds = 1;
	while(!q.empty()){
int tmpnoofchilds = noofchilds;
noofchilds = 0;
		int c = 0;
				days++;
		lop(k,tmpnoofchilds){
		int y = q.front(); q.pop();
		lop(i,es){
			if(!v[i] && a[y][i]){
                 c++;
                v[i] = true;
                q.push(i);
                noofchilds++;
			}
		}
    }
        if(c > mx){
    	mx = c;
    	f = days;

	}
}

	if(mx){
		cout<<mx<<space<<f<<endl;
	}
	else cout<<mx<<endl;
}

int main(){
//	freopen("in.txt","r",stdin);
cin >> es;

lop(i,es){
	cin >>m;
	v[i] = false;
	lop(j,m) cin>>x , a[i][x] = true;
}
int test;

cin >>test;

lop(i,test){
	cin >>x;
	counts(x);
	lop(i,es) v[i] = false;
}
    return 0;
}
