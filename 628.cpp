#include <bits/stdc++.h>
using namespace std;
int b[10];
string bb[100];
vector<string>words;
	int n;
	string s;
string as[] = {"0","1","2","3","4","5","6","7","8","9"};
void solve(int index,int ns){
	if(index == ns){
		for(int i = 0;i < ns;i++) cout<<bb[i];cout<<'\n';
			return;
	}
if(s[index] == '0'){
for(int i = 0;i <= 9;i++){
	bb[index] = as[i]; 
	solve(index+1,ns);
}
}else{
	for(int i = 0;i < words.size();i++){
		bb[index] = words[i];
		solve(index+1,ns);
	}
}
}

int main(){
		std::ios::sync_with_stdio(false);
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(cin >> n){
            cout<<"--\n";
	for(int i = 0;i < n;i++) cin >> s,words.push_back(s);

	int m;
	cin >> m;
for(int i = 0;i < m;i++){
	cin >> s;
solve(0,s.size());

}
words.clear();
	}
    return 0;
}