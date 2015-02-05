#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
    map<char, char>index;
    index['3'] = 'E';
    index['E'] = '3';
    index ['A'] =	'A' ;
    index['M'] =	'M';
    index	['Y'] =	'Y';
    index['B'] = ' ';
    index['N'] = ' ';
    index['Z'] =	'5';

    index['C'] = ' ';
    index['O'] =	'O';
     index['0'] =	'O';
    index['1'] =	'1';

    index['D'] = ' ';
    index['P'] = ' ';
    index['2'] = 'S';

    index['Q'] = ' ';
    index['F'] = ' ';
    index['R'] = ' ';
    index['4'] = ' ';
    index['G'] = ' ';
    index['S'] = '2';
    index['5'] =	'Z';
    index['H'] = 'H';
    index[' T'] =	'T';
    index['6'] = ' ';
    index['I'] =	'I';
    index['U'] =	'U';
    index['7'] = ' ';
    index['J'] = 'L';
    index['V'	] = 'V';
    index['8'] =	'8';

    index['K'] = ' ';
    index['W'] = 'W';
    index['9'] = ' ';
    index['L'] =	'J';
    index['X'] =	'X';

    string s;
    while(cin >>s){
    bool f =true,p = true;
    int i = 0;
    int j = s.size()-1;
    while(j>=i){
        if(index[s[i]] != s[j]) {f = false; break;}
        i++;j--;
    }

     i = 0;
     j = s.size()-1;
    while(j>=i){
        if(s[i] != s[j]) {p = false; break;}
        i++;j--;
    }
    if(!f&&!p) cout<<s<<" -- is not a palindrome."<<endl;
    else if(!f&&p)cout<<s<<" -- is a regular palindrome."<<endl;
    else if(f&&!p)cout<<s<<" -- is a mirrored string."<<endl;
    else cout<<s<<" -- is a mirrored palindrome."<<endl;
    cout<<endl;
   // cout<<f<<" "<<p<<endl;
    }
    return 0;
}
