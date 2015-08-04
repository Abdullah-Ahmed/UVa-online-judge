#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;
int main(){
		std::ios::sync_with_stdio(false);
	int n = 0,m = 0;
	int a[100],b[100];
         
	char s1[1000],s2[1000],*p;
	while (cin.getline(s1, sizeof(s1))){
		cin.getline(s2, sizeof(s2));

		n = m = 0;
		p = strtok(s1, " \t\n");
		while (p){
			a[n++] = atoi(p);
			p = strtok(NULL, " \t\n");
		}
		p = strtok(s2, " \t\n");
		while (p){
			b[m++] = atoi(p);
			p = strtok(NULL, " \t\n");
		}
int c = 0;
bool v[100],f;
for(int j  = 0 ; j < m ;j++) v[j] = false;
	for(int i = 0 ; i < n;i++){
		f = false;
		for(int j = 0 ; j < m ; j++)
			if(a[i] == b[j]&&!v[j]){
		       f = true;
		       v[j] = true;
		       break;
		   }
		   c+=f;
		   
	}
	if(!c) cout<<"A and B are disjoint\n";
	else if(c!=min(n,m)){
           cout<<"I'm confused!\n";
	}else{
		if(n == m) cout<<"A equals B\n";
		else if(n>m) cout<<"B is a proper subset of A\n";
		else cout<<"A is a proper subset of B\n";
	}
            n = m = 0;
}
    return 0;
}
