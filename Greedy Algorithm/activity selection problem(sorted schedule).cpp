#include<bits/stdc++.h>
using namespace std;

int activitySelection(vector<int> &start,vector<int>& end,int n){
 int ans=1;
 for(int i=0;i<n-1;i++){
if(end[i]<=start[i+1]){
    ans++;
}

}
return ans;
}
int main(){

int n;
cout<<"Number of schedules: ";
cin>>n;
vector<int> start(n);
vector<int> end(n);
 for(int i=0;i<n;i++){
    cin>> start[i];
    cin>>end[i];
 }


int result=activitySelection(start,end,n);

cout<<"total: "<<result<<endl;

}
