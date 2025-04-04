#include<bits/stdc++.h>
using namespace std;


 int typewriter(string s){
 int time =0;
 char current='a';
 for(int i=0;i<s.length();i++){
    char c=s[i];
    int clock=abs(c-current);
    int anticlock=26-clock;
    int minsteps=min(clock,anticlock);
    time+=1+minsteps;
    current =c;

 }
 return time;
 }

int main(){
 cout<<"input: ";
 string s;
 cin>>s;
cout<<"Minimum time: "<<typewriter( s)<<endl;

}
