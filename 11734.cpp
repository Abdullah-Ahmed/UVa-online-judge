#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
    int tc = 1,cs = 1;
   string team,judge;
 string tt;
 getline(std::cin, tt);
 if(tt.size()==1) tc = tt[0] - '0';
 else {
    tc = (tt[0]-'0')*10 + (tt[1] - '0');
 }
       while(tc--){
 getline(std::cin, team);
 getline(std::cin, judge);

   if(team == judge){
        printf("Case %d: Yes\n",cs++);
        continue;
       }

         string s1;
         for(int i = 0 ;i < team.size();i++){
          if(team[i]!= ' ') s1+=team[i];
         }

         string s2;
         for(int i = 0 ;i < judge.size();i++){
          if(judge[i]!= ' ') s2+=judge[i];
         }
         if(s1==s2){
                 printf("Case %d: Output Format Error\n",cs++);
         }else{
              printf("Case %d: Wrong Answer\n",cs++);
         }
       }

    return 0;
}
